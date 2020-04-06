#include<stdio.h>

#include "funct.h"
#include "snake.h"

void hovers(int position)
{
    int a=10;
    locate(25,a-5);
    printf("Main Menu");
    locate (25,a);
    printf("Start Game");
    locate (25,a+5);
    printf("Help");
    locate (25,a+5+5);
    printf("Credit");
    locate (25,a+5+5+5);
    printf("Exit");

    if (position==1){
        locate(25,11);
        printf("%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
    }if(position==2){
        locate(25,16);
        printf("%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
    }if(position==3){
        locate(25,21);
        printf("%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
    }if(position==4){
        locate(25,26);
        printf("%c%c%c%c%c%c%c%c%c%c",196,196,196,196,196,196,196,196,196,196);
    }
    locate(0,40);
}
int fscreen(){

    char b,position=1,ppos=0;
    while(1){
    b=getch();
    switch(b)
    {
    case 72:

        {
            if(position==4 ||position==2 ||position==3){
                ppos=position;
                position=position-1;
            }
            break;
        }
    case 80:

        {
            if(position==1 ||position==2 ||position==3){
                ppos=position;
                position=position+1;
            }
            break;

        }
    case 27:

        {
           exit(0);
        }
    case 13:

        {
            if (position==1){
                clearscreen();

                start();
            }
            if (position==2) {
                clearscreen();
                locate(1,1);
                printf("\tThis is Normal Snake Games. This Games does not have complex control. For running this games, we have arrow keys and other keys like Esc or others \n\n"
                       "Normal Arrow key for movement and Esc for Quit \n\n"
                       "\t Press Any keys");
                getch();
                clearscreen();


            }
            if (position==3) {
                clearscreen();
                locate(1,1);
                printf("Still Yet to be Completed");
                getch();
                clearscreen();
            }

            if (position==4) exit(0);
        }
    }

    color(0);
    hovers(ppos);
    color(7);
    hovers(position);
    }
}

void main()
{
    Adjust();//screen adjustment
    hovers(1);
    fscreen();


}



