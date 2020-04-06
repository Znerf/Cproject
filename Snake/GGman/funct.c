#include <windows.h>
#include <Mmsystem.h>
#include<stdlib.h>

void Adjust()
{

    SetConsoleTitle("Snake");
    COORD bufferSize = {100, 50};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);


}
void clearscreen()
{
    int i,j;
    for (i=0;i<=99;i++)
    {
        for(j=0;j<=49;j++)
        {
            locate(i,j);
            printf(" ");
        }
    }

}

int color(int ForgC)
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ForgC);
}



void locate(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
