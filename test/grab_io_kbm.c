#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <time.h>
#include <stdint.h>
#include <errno.h>


int main(int argc, char* argv[]){ 
  sleep(1);
  int rcode = 0;

  char keyboard_name[256] = "Unknown";
  char phys[256] = {0};

  int fd = open("/dev/input/event4", O_RDONLY | O_NONBLOCK);
  if ( fd == -1 ) {
    printf("Failed to open keyboard.\n");
    exit(1);
  }

  ioctl(fd, EVIOCGPHYS(sizeof(phys)), phys);
  rcode = ioctl(fd, EVIOCGNAME(sizeof(keyboard_name)), keyboard_name);

  printf("Reading From : %s \n", keyboard_name);

  printf("Getting exclusive access: ");
  rcode = ioctl(fd, EVIOCGRAB, 1);
  if (rcode == -1) {
    printf("Error grabbing device \n");
    //close(keyboard_fd);
    //return 1;
  }
  else if (rcode == 0) {
    printf("Success \n");
  }
    



  struct input_event event;


  for (size_t i = 0; i < 50; i++){

    int n = read(fd, &event, sizeof(event));
    //printf("Read result : %d \n", n);

    if (n < 0) {
      if (errno == EAGAIN) {
        printf("EAGAIN \n");
      }
      else{
        printf("Error getting event\n");
      }
    }
    else {
      printf("keyboard event: type %d code %d value %d  \n", event.type, event.code, event.value);
    }

    usleep(50000);

  }


  printf("Exiting.\n");
  ioctl(fd, EVIOCGRAB, 0);
  close(fd);
  return 0;
}
