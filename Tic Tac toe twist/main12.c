#include <stdio.h>
#include<stdlib.h>
#include "loc.c"



void screen1();
void hover(int posi)
{
    int i=0,j=0,x1=0,y1=0,j1=0,i1=0;

    if (posi==7) //7
    {
        i1=1,j1=1,x1=24,y1=10;
        //i=2,j1=2,x1=24,y1=11;
    }else if(posi==8){//8
        i1=1,j1=28,x1=50,y1=10;
        //i=2,j1=29,x1=50,y1=11;
    }else if(posi==9){//8
        i1=1,j1=54,x1=78,y1=10;
    }else if (posi==1){ //1
        i1=27,j1=1,x1=24,y1=37;
    }else if(posi==2){//2
        i1=27,j1=28,x1=50,y1=37;
    }else if(posi==3){//3
        i1=27,j1=54,x1=78,y1=38;
    }else if (posi==4){ //4
        i1=14,j1=1,x1=24,y1=23;
    }else if(posi==5){//5
        i1=14,j1=28,x1=50,y1=23;
    }else if(posi==6){//6
        i1=14,j1=53,x1=78,y1=23;
    }

    j=j1;
    i=i1;
    for(;j<x1-1;j++)
    {
        locate(j+1,i);
        printf("%c",196);
        locate(j+1,y1);
        printf("%c",196);
    }
    j=j1;
    for(;i<y1-1;i++)
    {
        locate(j,i+1);
        printf("%c",179);
        locate(x1,i+1);
        printf("%c",179);
    }
    locate(0,40);


}
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

void player(int posi,int a)
{
    a=7;
    int i=0,j1=0,x1=0,y1=0,j=0;
    if (posi==7) //7
    {
        i=2,j1=2,x1=24,y1=11;
    }else if(posi==8){//8
        i=2,j1=29,x1=50,y1=11;
    }else if(posi==9){//8
        i=2,j1=55,x1=78,y1=11;
    }else if (posi==1){ //1
        i=28,j1=2,x1=24,y1=38;
    }else if(posi==2){//2
        i=28,j1=29,x1=50,y1=38;
    }else if(posi==3){//3
        i=28,j1=55,x1=78,y1=38;
    }else if (posi==4){ //4
        i=15,j1=2,x1=24,y1=24;
    }else if(posi==5){//5
        i=15,j1=29,x1=50,y1=24;
    }else if(posi==6){//6
        i=15,j1=54,x1=78,y1=24;
    }
    for (;i<y1;i++)
            {
                j=j1;
                for(;j<x1;j++)
                {
                locate(j,i);
                color(a);
                printf("%c",178);
                color(7);


                }

            }
            locate(0,40);

            //printf("%d %d",i,j);

}

int fscreen(){
    char b,position=1,ppos=0;
    while(1){
    b=getch();
    switch(b)
    {
    case 'w':
    case'W':
        {
            if(position==4 ||position==2 ||position==3){
                ppos=position;
                position=position-1;
            }
            break;
        }
    case 's':
    case'S':
        {
            if(position==1 ||position==2 ||position==3){
                ppos=position;
                position=position+1;
            }
            break;

        }
    case 'Q':
    case'q':
        {
           return 0;
        }
    case 'e':
    case'E':
        {
            if (position==1){
                system("cls");
                return 1;
            }
            if (position==2) {
                system("cls");
                printf("\tThis is Normal Multiplayer Game of Tic Tac Toe. There are 9 space available.These available space can be used by the help of w,a,s,d,e,q for both user"
                       "\n a- Left\n d-Right \n w- Up\n s- Down \n e- Enter for mark \n q- Quit \n"
                       "\t Controls are given to player turn by turn leaving mark at the spaces. The one who makes mark succesicely 3 times in row, column or diagonal wins the game");
                getch();
                system("cls");

            }
            if (position==3) {
                system("cls");
                printf("\tThis is small Project from the student of first semester of BE on Electronic and communication of Thapathali Campus,Kathamandu. This program is created for the sharpening of C skills and learn more about C"
                       "This program can help someone who is first in programming and still stumbling with codes. This program can help someone who is willing to want to know about c programs and how to write a simple game"
                       "\n\t I would like to thanks our C programming Teachers D.R., Sayera and Robotics and Automation Club for providing us such wonderful environment to code. "
                       "I would like to thanks Department of Thapathali for giving us such a opportunity to sharpen my skills. At last I would like to thank all the friends,Seniors and juniors who have helped me dirctly and indirectly even by "
                       "motivating me to start doing this small project which have given me confidence to start new one.");
                getch();
                system("cls");
            }

            if (position==4) return 0;
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
while(1){

    int a,tur=1,recall=0;
    hovers(1);
    int z=fscreen();
    if (z==0) return 0;

    char p1name[15],p2name[15];

    printf("Enter the name");
    gets(p1name);

    printf("Enter the name");
    gets(p2name);
    system("cls");

while(1){
    screen1();
    int posi=7;
    hover(posi);

    char ke;
    int position=7,p1[10],p2[10],ppos=0,counter=0;
    p1[0]=1;
    p2[0]=2;
    for (;counter<=9;counter++)
    {
        p1[counter]=0;
        p2[counter]=0;
    }
    while (1)
    {
        ke=getch();
        switch (ke)
        {
            case 'a':
            case 'A'://left
            {
                if(position==2 ||position==3||position==5||position==6 ||position==8 ||position==9){
                    ppos=position;
                    position--;

                }
                break;
            }
            case 'W':
            case'w'://up
            {
               if(position==2 ||position==3||position==1||position==4 ||position==5 ||position==6){
                    ppos=position;
                    position=position+3;
                }
            }
                break;
            case 'd':
            case'D'://right
            {
                if(position==2 ||position==1||position==5||position==7 ||position==8 ||position==4){
                    ppos=position;
                    position++;
                }
                break;

            }
            case 'S':
            case 's'://down
            {
                if(position==7 ||position==8||position==9||position==4 ||position==5 ||position==6){
                    ppos=position;
                    position=position-3;
                }
                break;
            }
            case 'e':
            case 'E'://ENTER
            {
                if (tur==1 && p1[position]!=1 &&p2[position]!=1){
                    p1[position]=1;
                    player(position,7);
                    tur=2;
                    if (((p1[1] ==1||p2[1]==1) && (p1[2] ==1 ||p2[2]==1)&&(p1[3] ==1||p2[3]==1)||
                        ((p1[4] ==1||p2[4]==1) && (p1[5] ==1||p2[5]==1) &&(p1[6] ==1||p2[6]==1))||
                        ((p1[7] ==1||p2[7]==1) && (p1[8] ==1 ||p2[8]==1)&& (p1[9] ==1||p2[9]==1))||
                        ((p1[1] ==1||p2[1]==1) && (p1[5] ==1 ||p2[5])==1)&&(p1[9] ==1||p2[9]==1))||
                        ((p1[3] ==1||p2[3]==1) && (p1[5] ==1 ||p2[5]==1)&&(p1[7] ==1||p2[7]==1))||
                        ((p1[1] ==1 ||p2[1]==1)&& (p1[4] ==1||p2[4]==1) &&(p1[7] ==1||p2[7]==1))||
                        ((p1[2] ==1 ||p2[2]==1)&& (p1[5] ==1 ||p2[5]==1)&&(p1[8] ==1||p2[8]==1))||
                        ((p1[9] ==1 ||p2[9]==1)&& (p1[6] ==1||p2[6]==1) &&(p1[3] ==1||p2[3]==1)) ) {
                            locate(0,40);
                            printf("%s lose",p1name);
                            getch();
                        system("cls");
                        printf("%s lose",p1name);
                        recall=1;
                        getch();
                        break;
                    }
                }
                else if(tur==2&&p2[position]!=1 && p1[position]!=1){
                        p2[position]=1;
                        player(position,2);
                        tur=1;

                    if (((p1[1] ==1||p2[1]==1) && (p1[2] ==1 ||p2[2]==1)&&(p1[3] ==1||p2[3]==1)||
                        ((p1[4] ==1||p2[4]==1) && (p1[5] ==1||p2[5]==1) &&(p1[6] ==1||p2[6]==1))||
                        ((p1[7] ==1||p2[7]==1) && (p1[8] ==1 ||p2[8]==1)&& (p1[9] ==1||p2[9]==1))||
                        ((p1[1] ==1||p2[1]==1) && (p1[5] ==1 ||p2[5])==1)&&(p1[9] ==1||p2[9]==1))||
                        ((p1[3] ==1||p2[3]==1) && (p1[5] ==1 ||p2[5]==1)&&(p1[7] ==1||p2[7]==1))||
                        ((p1[1] ==1 ||p2[1]==1)&& (p1[4] ==1||p2[4]==1) &&(p1[7] ==1||p2[7]==1))||
                        ((p1[2] ==1 ||p2[2]==1)&& (p1[5] ==1 ||p2[5]==1)&&(p1[8] ==1||p2[8]==1))||
                        ((p1[9] ==1 ||p2[9]==1)&& (p1[6] ==1||p2[6]==1) &&(p1[3] ==1||p2[3]==1)) ) {
                        locate(0,40);
                        printf("%s lose",p2name);
                        getch();
                        system("cls");
                        printf("%s lose",p2name);
                        recall=1;
                        getch();
                        break;
                    }
                    }

                    break;
            }
            case 'q':
            case 'Q':
             return 0;
        }
        if (recall==1) break;
                    color(0);
                    hover(ppos);
                    color(7);
                    hover(position);
            if((p1[1]==1||p2[1]==1)&&(p1[2]==1||p2[2]==1)&&(p1[3]==1||p2[3]==1)&&(p1[4]==1||p2[4]==1)&&(p1[5]==1||p2[5]==1)&&(p1[6]==1||p2[6]==1)&&(p1[7]==1||p2[7]==1)&&(p1[8]==1||p2[8]==1)&&(p1[9]==1||p2[9]==1)) break;
    }
    system("cls");
    if (recall==1) break;
    }
}
}


void screen1()
{
    //80 horizontal 61 vertical
    int i;
    for (i=0;i<40;i++){
    //horizontal
        locate(26,i);
        printf("%c",179);
        locate(52,i);
        printf("%c",179);
    }
    for (i=0;i<80;i++){
    //vertical
        locate(i,13);
        printf("%c",196);
        locate(i,26);
        printf("%c",196);
    }
    locate(26,13);
    printf("%c",197);
    locate(52,13);
    printf("%c",197);
    locate(26,26);
    printf("%c",197);
    locate(52,26);
    printf("%c",197);
    locate(0,40);
}
