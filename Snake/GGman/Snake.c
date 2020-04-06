#include<windows.h>
#include<time.h>
int level=100;
int f1=0,f2=0;


void swapp(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

void screen(){ // screen outlay
    int i;
    for(i=0;i<=99;i++)
    {
        locate(i,0);
        printf("*");
        locate(i,48);
        printf("*");
    }
    for(i=0;i<=48;i++)
    {
        locate(0,i);
        printf("*");
        locate(99,i);
        printf("*");
    }
}

int food(int x[],int y[],int *len,int *initial)
{
    if((x[1]==f1 && y[1]==f2))
    {
        int c=0;
        int counter;
        do{
            srand(time(NULL));
            f1=rand()%98;
            f2=rand()%47;
            for(counter=1;counter<=*len;counter++)
            {
                if (x[counter]==f1)
                {
                    if (y[counter]==f2) c=0;
                    else c=1;
                }
                else if(f1==0||f2==0) c=0;
                else c=1;
            }
        }while (c==0);
        locate(f1,f2);
        printf("0");
        int tempo=*len;
        *len=tempo+1;
        locate(1,49);
        printf("%d",*len-1);
        return 1;
    }else if (*initial==0)
    {
        int c=0;
        int counter;
        do {

            f1=rand()%98;
            f2=rand()%47;

                if (f1==1&&f2==5)
                {
                    c=1;
                }
                else if(f1==0||f2==0) c=0;
                else c=1;

        }while (c==0);
        locate(f1,f2);
        printf("0");
        *initial=1;
        int tempo=*len;
        *len=tempo+1;

        return 1;

    }
    else return 0;
}

void direct(int *direction)
{
    char input;
    if(kbhit()){
        input=getch();

        if (input == -32){
            input = getch();
                    }

        switch(input)
        {
            case 72://up
                if (*direction!=2)
                *direction=8;
                break;
            case 80://down
                if (*direction!=8)
                *direction=2;
                break;
            case 77://right
                if (*direction!=4)
                *direction=6;
                break;
            case 75://left
                if (*direction!=6)
                *direction=4;
                break;
            case 27:
                printf("quit");
                exit(0);
                break;

        }
    }

}

void start() // main
{
    screen();
    char input;
    int direction=6,x[100],y[100],len=0,initial=0,extend;
    x[1]=1;
    y[1]=5;


    int counterlen;

    while (1)
    {

        extend=food(x,y,&len,&initial);
        direct(&direction);
        switch(direction)
        {
            case 6:
                x[0]=x[1]+1;
                y[0]=y[1];
                break;
            case 4:
                x[0]=x[1]-1;
                y[0]=y[1];
                break;
            case 8:
                x[0]=x[1];
                y[0]=y[1]-1;
                break;
            case 2:
                x[0]=x[1];
                y[0]=y[1]+1;

                break;
        }

        for (counterlen=1;counterlen<=len;counterlen++)
        {
            swapp(&x[counterlen],&x[0]);
            swapp(&y[counterlen],&y[0]);
        }
        if (extend==0){
            locate(x[0],y[0]);
            printf(" ");
        }
        locate(x[1],y[1]);
        printf("1");
        Sleep(level);

//        extend=food(x,y,&len,&initial);
//        direct(&direction);

        if (((x[1]>=0)&& (x[1]<=99)&& (y[1]==0))||((x[1]>=0)&& (x[1]<=99)&& (y[1]==48))||((y[1]>=0)&& (y[1]<=48)&& (x[1]==0))||((y[1]>=0)&& (y[1]<=48)&& (x[1]==99))) Lose(len);
        else
        {
            if(len!=1)
            {
                for(counterlen=2;counterlen<=len;counterlen++)
                {
                    if(x[counterlen]==x[1]&&y[counterlen]==y[1]) Lose(len);
                }
            }
        }


    }
}

void Lose(a)
{
    clearscreen();
    locate(1,1);
    printf("You Got Score of %d",a-1);
    getch();
    clearscreen();
    main();
}
