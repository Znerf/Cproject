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

void sort(char addr[50])
{
    FILE *fp;
    fp=fopen(addr,"ab+");
    int num=1;
    while(!feof(fp))
    {
        num++;
        fread(&adds[num],sizeof(struct bookentry),1,fp);
    }
    num--;
    fclose(fp);

    int i,j;

    char tem2[25];

    for(i=2;i<=num;i++)
    {
        for(j=i+1;j<=num;j++)
        {

            if ((strcasecmp(adds[i].bookname,&adds[j].bookname))>=0)
            {
                struct bookentry temp;
                temp=adds[i];
                adds[i]=adds[j];
                adds[j]=temp;
            }
        }

    }

    fp=fopen("data/library/temp.dat","ab+");
    for (i=2;i<=num;i++)
    {
        fwrite(&adds[i],sizeof(struct bookentry),1,fp);
    }
    fclose(fp);

    remove(addr);
    rename("data/library/temp.dat",addr);
    remove("data/library/temp.dat");


}


void Firstpage() // shows ffroint page
{
    int a=10;
    locate(23,a-4);
    printf("Main Menu");
    color(1);
    locate (25,a);
    printf("Search");
    color(7);
    locate (25,a+4);
    printf("Add");
    locate (25,a+4*2);
    printf("Book list");
    locate (25,a+4*3);
    printf("Change password");
    locate (25,a+4*4);
    printf("Credit");
    locate (25,a+4*5);
    printf("Exit");

    int position =10;
    while(1)
    {
        char input=getch();
        if (input == -32){
            input = getch();
        }
        switch(input)
        {
            case 71:
            case 103:
                clearscreen();
                start();
                break;
            case 72://up
                if (a!=10)
                {
                    position=a;
                    a=a-4;
                }
                break;
            case 80://down
                if (a!=30)
                {
                    position =a;
                    a=a+4;

                }
                break;
            case  27:
                exit(0);
                break;
            case 13:
                if ((a-10)/4==0) {
                        clearscreen();
                        promain();

                }else if ((a-10)/4==1) {
                    FILE *fp;
                    fp=fopen("data/library/book.dat","ab+");
                    bookadd(fp);
                    fclose(fp);

                    clearscreen();
                    Firstpage();
                  //  booklist();

                }else if ((a-10)/4==2) {
                    clearscreen();
                    showbook();

                }else if ((a-10)/4==3) {
                    chauthority();
                    Firstpage();

                }else if ((a-10)/4==4) {
                    clearscreen();
                    printf("\t This is a small project on Library Management coded by the student Electronics and Computer Engineering Department of Thapathali Engineering Campus."
                           " This project shows how to manage Library File in a computerized manner. It shows students Book information and is a perfect repalcement for Library Card \n"
                           "\t We would like to thanks Our Programming teacher Er. Dipendra Rauniyar for giving us such a oppurnunity to code in C and helping us to develop programming skills. We would like to thanks our seniors "
                           "brother and sister for helping us in this project. This project will helps someone who is willing to get thorough inforamtion on C-programming. At last, We want to"
                           " thanks our college friends who have been cooperative throughout this project \n"
                           "\t\t\t Thank you \n"
                           "\t\t\t\t\t\t\t\t\t Sagar Shrestha \n"
                           "\t\t\t\t\t\t\t\t\t Niraj Pokharel \n"
                           "\t\t\t\t\t\t\t\t\t Jibit Khanal\n"
                           "\t\t\t\t\t\t\t\t\t Gokul Raj Adhikari\n");

                    getch();
                    clearscreen();
                    Firstpage();

                }else if ((a-10)/4==5) {
                    exit(0);
                }
                break;
        }

        color(7);
        locate(25,position);
        show((position-10)/4);
        color(1);
        locate(25,a);
        show((a-10)/4);
        color(7);


    }
}

 void show(int a) // part of front page
 {
    if (a==0) printf("Search");
    if(a==1) printf("Add");
    if(a==2) printf("Book list");
    if(a==3) printf("Change password");
    if (a==4)printf("Credit");
    if(a==5)printf("Exit");
 }




 void showbook()//list all file
 {
    sort("data/library/book.dat");

    FILE *fp;
    clearscreen();

    fp=fopen("data/library/book.dat","ab+");

    int booklen=0;
    if (fp!=NULL){
        int booklene =1;
        while(!feof(fp)){
            booklen++;
            fread(&adds[booklen],sizeof(struct bookentry),1,fp);

        }
    }else{
        printf("No file found");
        exit(0);
    }
    booklen--;
    fclose(fp);

    int i,change;

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
    int n,dif=0;
    if (booklen<49) n=booklen;
    else n=48;
    while (1){
        int s=0;
        for(i=dif+1;i<=n;i++)
        {
                locate(10,i-dif);
                puts(adds[i].bookname);
                locate(50,i-dif);
                puts(adds[i].authur);
                locate(80,i-dif);
                printf("%d",adds[i].price);
                locate(0,i-dif);
                printf(" %d",adds[i].booknum);
                locate(90,i-dif);
                printf(" %d",adds[i].client);
        }

        int hov=1;
        color(1);
        locate(0,hov);
        printf(" %d",adds[1].booknum);
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
                    if ((hov+dif)!=1){
                        if (hov%48==1 ) {
                            n=n+change-48;
                            dif=dif-48;
                            s=1;
                            clearscreen();
                            break;
                        }
                        color(7);
                        locate(0,hov);
                        printf(" %d",adds[hov+dif].booknum);
                        hov--;
                        color(1);
                        locate(0,hov);
                        printf(" %d",adds[hov+dif].booknum);
                        color(7);
                    }
                    break;
                case 83:
                    authorize();
                    clearscreen();
                    del("data/library/book.dat",adds[hov+dif].booknum);
                    showbook();
                case 13:
                    authorize();
                    clearscreen();
                    printf("Enter Student Roll number this book given to::");
                    int rol;
                    scanf("%d",&rol);

                    amend(adds[hov+dif].booknum,rol);
                    clearscreen();
                    showbook();
                case 80://down
                    if ((hov+dif)!=booklen){
                        if (hov%48==0 ) {
                            n=n+48;
                            if (booklen<=n)
                                {
                                    change=n-booklen;
                                    n=booklen;
                                }
                            dif=dif+48;
                            s=1;
                            clearscreen();
                            break;
                        }
                        color(7);
                        locate(0,hov);
                        printf(" %d",adds[hov+dif].booknum);
                        hov++;
                        color(1);
                        locate(0,hov);
                        printf(" %d",adds[hov+dif].booknum);
                        color(7);
                    }
                    break;
                case  27:
                    clearscreen();
                    Firstpage();
                    break;


            }
            if (s==1) break;
        }
    }
 }

 void bookadd(FILE *fp)
 {
     int n=0, borrower=0;
     authorize();
     clearscreen();

    int num=1;
    while(!feof(fp)){
        fread(&adds[num],sizeof(struct bookentry),1,fp);
        num++;

    }

    int cot;//counter
    int s= adds[2].booknum;

    for(cot=2;cot<num-1;cot++)
    {
        if (s<adds[cot].booknum) s=adds[cot].booknum;
    }
    num=s; //assign max book num for new book entry

    rewind(fp);
    Sleep(100);

    if (fp!=NULL){
        printf("Book Name::");
        scanf("%s",adds[0].bookname);
        printf("Authur::");
        scanf("%s",adds[0].authur);
        printf("Price::");
        scanf("%d",&adds[0].price);
        num++;
        adds[0].booknum =num;
        adds[0].client=0;
        fwrite(&adds[0],sizeof(struct bookentry),1,fp);

    }else{
        printf("Sorry for error");
        getch();
        clearscreen();
        main();
    }

}

void amend(int i, int sym) //for borrowing of book ADN RETURNING
{

    FILE *fp;

    int booklen=1,j=0;
    fp=fopen("data/library/book.dat","ab+");

    if (fp!=NULL){
        while(!feof(fp)){
            booklen++;
            fread(&adds[booklen],sizeof(struct bookentry),1,fp);
            if (adds[booklen].booknum==i)
            {
                j=booklen;
            }
        }
    }else{
        printf("No file found");
        exit(0);
    }
    booklen--;
    fclose(fp);


    adds[j].client=sym;
    fp=fopen("data/library/temp.dat","ab+");
    for (i=2;i<=booklen;i++)
    {
        fwrite(&adds[i],sizeof(struct bookentry),1,fp);
    }
    fclose(fp);

    remove("data/library/book.dat");
    rename("data/library/temp.dat","data/library/book.dat");

}


void del(char addr[50], int i) //deleting book from library
{
    FILE *fp;
    int booklen=1,j;
    fp=fopen(addr,"ab+");

    if (fp!=NULL){
        while(!feof(fp)){
            booklen++;
            fread(&adds[booklen],sizeof(struct bookentry),1,fp);
            if (adds[booklen].booknum==i)
            {
                j=booklen;
            }
        }
    }else{
        printf("No file found");
        exit(0);
    }
    booklen--;
    fclose(fp);
    fp=fopen("data/library/temp.dat","ab+");
    for (i=2;i<=booklen;i++)
    {
        if (j!=i) fwrite(&adds[i],sizeof(struct bookentry),1,fp);
    }
    fclose(fp);

    remove(addr);
    rename("data/library/temp.dat",addr);

}
