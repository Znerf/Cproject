#include <windows.h>
#include <Mmsystem.h>

void color(int ForgC)
{
     WORD wColor;
                          //We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     wColor =ForgC ;
     SetConsoleTextAttribute(hStdOut, wColor);

     return;
}



int locate(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
