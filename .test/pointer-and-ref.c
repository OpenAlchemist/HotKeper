#include <stdio.h>

void changeValue(int& ref){
    ref = 99;
}

void main(){
    //integer variable
    int apple = 5, ball = 0, car, door = 10; //ball and car will have same value
    car = 20; // car is now 20

    //hexadecimal number
    int hexnum = 0xF2 // 0x is used to represent hexadecimal. Memory addresses also use hexadecimal

    //print formated integer
    printf("value of apple is: %i", apple) //👉value of apple is: 5
    printf("value of hexnum in decimal is: %i", hexnum) //👉value of hexnum in decimal is: 242

    //memory address
    printf("memory address of apple is: %i", &apple); //👉memory address of apple is: 0xSOMETHING


    //integer pointer, Points to memory address of variable, that is an integer
    int* pa = &apple; //pa will point to the memory address of integer variable, apple
    int* pb = &ball, pc, pd; //pc and pd is declared but not initialized
    pc = &ball, pd = &door; //pc will point to ball and pd will point to door
    pc = &car //pc will now point to car
    pc++;  //pc will now point to memory block that comes after car


    //print pointer
    printf("memory address being pointed by pa is: %i", pa) //👉memory address being pointed by pa is: 0xSOMETHING
    printf("value at the memory address of pa is: %i", *pa) //👉value at the memory address of pa is: 5


    //use pointer
    printf("value of apple is: %i", *pa) //👉value of apple is: 5
    *pa = 30;
    printf("value of apple is: %i", apple) //👉value of apple is: 30
    (*pa)++;
    printf("value of apple is: %i", apple) //👉value of apple is: 31


    //integer reference, representative of a variable, that is an integer
    int& ra = apple; //ra will now act the same as apple

    ra++;
    printf("value of apple is: %i", apple) //👉value of apple is: 32

    ra = door;
    printf("value of apple is: %i", apple) //👉value of apple is: 10


    changeValue(ball);
    printf("value of ball is: %i", ball) //👉value of ball is: 99


}



    #include <stdio.h>

void changeValue(int& ref){
    ref = 99;
}

void main(){
//integer variable
int apple = 5, ball = 0, car, door = 10; //ball and car will have same value
car = 20; // car is now 20

//hexadecimal number
int hexnum = 0xF2 // 0x is used to represent hexadecimal. Memory addresses also use hexadecimal

//print formated integer
printf("value of apple is: %i", apple) //👉value of apple is: 5
printf("value of hexnum in decimal is: %i", hexnum) //👉value of hexnum in decimal is: 242

//memory address
printf("memory address of apple is: %i", &apple); //👉memory address of apple is: 0xSOMETHING


//integer pointer, Points to memory address of variable, that is an integer
int* pa = &apple; //pa will point to the memory address of integer variable, apple
int* pb = &ball, pc, pd; //pc and pd is declared but not initialized
pc = &ball, pd = &door; //pc will point to ball and pd will point to door
pc = &car //pc will now point to car
pc++;  //pc will now point to memory block that comes after car


//print pointer
printf("memory address being pointed by pa is: %i", pa) //👉memory address being pointed by pa is: 0xSOMETHING
printf("value at the memory address of pa is: %i", *pa) //👉value at the memory address of pa is: 5


//use pointer
printf("value of apple is: %i", *pa) //👉value of apple is: 5
*pa = 30;
printf("value of apple is: %i", apple) //👉value of apple is: 30
(*pa)++;
printf("value of apple is: %i", apple) //👉value of apple is: 31


//integer reference, representative of a variable, that is an integer
int& ra = apple; //ra will now act the same as apple

ra++;
printf("value of apple i
