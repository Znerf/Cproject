#include<stdio.h>
#include<string.h>

struct bookentry{       //stores struct
        int booknum;
        char bookname[30];
        char authur[30];
        int price;
        int client;
};
struct bookentry adds[100]; // make a adds struct as global


void promain() // Enter symbol no of student
{
    clearscreen();
    int symbol;
    clearscreen();
    locate (1,1);
    printf("Enter student symbol no::");
    scanf("%d",&symbol);
    check(symbol);
}

void check(int sym) //check which books is taken
{
    clearscreen();
    struct bookentry sy[12]; // for book taken only

    FILE *fp;
    fp=fopen("data/library/book.dat","ab+");
    int num=1,len=0; // len for book taken

    while(!feof(fp))
    {
        num++;
        fread(&adds[num],sizeof(struct bookentry),1,fp);
        if(adds[num].client == sym)
        {
            len++;
            strcpy(sy[len].authur,adds[num].authur);
            strcpy(sy[len].bookname,adds[num].bookname);
            sy[len].booknum=adds[num].booknum;
            sy[len].client=adds[num].client;
            sy[len].price= adds[num].price;

        }
    }
    fclose(fp);
    int booktoadd; // variable for book add to symbol
    if(len==0){
            clearscreen();
            printf("No book added \n");
            printf("Press ESC TO escape\n");
            char key=getch();
            if (key==27) {
                    clearscreen();
                    Firstpage();
            }

            printf("Enter book num you want to add::");
            scanf(" %d",&booktoadd);
            amend(booktoadd,sym);
            clearscreen();
            check(sym);

    }

    int i;
    locate(0,0);
    printf("Book No.");
    locate(10,0);
    printf("Book Name");
    locate(50,0);
    printf("Authur");
    locate(80,0);
    printf("Price");
    locate(90,0);
    printf("Borrower");
    for(i=1;i <= len ; i++)
    {
            locate(10,i);
            puts(sy[i].bookname);
            locate(50,i);
            puts(sy[i].authur);
            locate(80,i);
            printf("%d",sy[i].price);
            locate(0,i);
            printf(" %d",sy[i].booknum);
            locate(90,i);
            printf(" %d",sy[i].client);
            Sleep(100);
    }

    int hov=1;
    color(1);
    locate(0,hov);
    printf(" %d",sy[1].booknum);
    color(7);
    while(1)
    {

        char input=getch();

        if (input == -32){
            input = getch();
                    }
        switch(input)
        {
            case 72://up
                if (hov!=1) {
                    color(7);
                    locate(0,hov);
                    printf(" %d",sy[hov].booknum);
                    hov--;
                    color(1);
                    locate(0,hov);
                    printf(" %d",sy[hov].booknum);
                    color(7);
                }
                break;
            case 80://down
                if (hov!=len){
                    color(7);
                    locate(0,hov);
                    printf(" %d",sy[hov].booknum);
                    hov++;
                    color(1);
                    locate(0,hov);
                    printf(" %d",sy[hov].booknum);
                    color(7);
                }
                break;
            case 83:
                authorize();
                amend(sy[hov].booknum,0);
                clearscreen();
                check(sym);
            case 13:
                if(len!=10){
                    authorize();
                    clearscreen();
                    locate(1,1);

                    printf("Enter book num you want to add::");
                    scanf("%d",&booktoadd);
                    amend(booktoadd,sym);
                    clearscreen();
                    check(sym);
                }
            case  27:
                clearscreen();
                Firstpage();
                break;

        }
    }
 }


int strcom(char a[],char b[])
{
    if (strlen(a)==strlen(b))
    {
        int i;
        for (i=0;i<strlen(a);i++)
        {
            if (a[i]!=b[i]) return 0;
        }
    }
    else return 0;
    return 1;
}

void authorize() //protection
{
    clearscreen();
    char pass[50]; // user input
    char key; // single key
    int i=0,position=9; // for positioning password

    locate (0,0);
    printf("Password::");
    while (key!= 13){

        key=getch();
        locate (1,1);
        if (key >=32 && key <= 126)
        {
            position++;
            locate(position,0);
            printf("*");
            pass[i]=key;
            i++;
        }else if (key== 13)
        {
            pass[i]='\0';
        }
        else if(key== 8)
        {
            if (position!=9){
                locate(position,0);
                printf(" ");
                position--;
                i--;
            }
        }
    }

    FILE *fp;

    char pa[50],k;
    fp=fopen("a.dat","rb");
    int len=0;
    while (!feof(fp)) //retriving password
    {
        k=fgetc(fp);
        pa[len]=k;
        len++;
    }
    fclose(fp);
    pa[len-1]='\0';


    if (strcom(pa,pass)==1)
    {

    }else{
        printf("Wrong Password");
        getch();
        clearscreen();
        main();
    }




}


void chauthority() //change password
{
    clearscreen();
    char pass[50]; //check old password
    char key;
    int i=0,position=9;

    locate (0,0);
    printf("Password::");
    while (key!= 13){

        key=getch();
        locate (1,1);
        if (key >=32 && key <= 126)
        {
            position++;
            locate(position,0);
            printf("*");
            pass[i]=key;
            i++;
        }else if (key== 13)
        {
            pass[i]='\0';
        }
        else if(key== 8)
        {
            if (position!=9){
                locate(position,0);
                printf(" ");
                position--;
                i--;
            }
        }
    }

    FILE *fp;

    char pa[50],k;
    fp=fopen("a.dat","rb");
    int len=0;
    while (!feof(fp))
    {
        k=fgetc(fp);
        pa[len]=k;
        len++;
    }
    fclose(fp);
    pa[len-1]='\0';


    if (strcom(pa,pass)==1)
    {

    }else{
        printf("Wrong Password");
        getch();
        clearscreen();
        main();
    }


    key=56;//initalizing for change of content
    i=0;position=9;
    locate (0,1);
    printf("Password::");
    while (key!= 13){

        key=getch();
        locate (1,1);
        if (key >=32 && key <= 126)
        {
            position++;
            locate(position,1);
            printf("*");
            pass[i]=key;
            i++;
        }else if (key== 13)
        {
            pass[i]='\0';
        }
        else if(key== 8)
        {
            if (position!=9){
                locate(position,1);
                printf(" ");
                position--;
                i--;
            }
        }
    }

    fp=fopen("a.dat","wb+");
    fputs(pass,fp);
    fclose(fp);
    clearscreen();



}
