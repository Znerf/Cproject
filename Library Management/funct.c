#include <windows.h>
#include <Mmsystem.h>
#include<stdlib.h>

void Adjust()
{

    SetConsoleTitle("Library Management");
    COORD bufferSize = {100, 50};
    SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);


}
void clearscreen()
{
    system("cls");
}
int color(int n)
{
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
void locate(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
