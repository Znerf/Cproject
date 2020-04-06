#include<windows.h>
#include<time.h>

int level=40; //speed

int f1=0,f2=0,len;
int initial; //starting indication


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

struct timev { // provide time
    time_t   sec;
    long     nsec;
};

long int ran()// random for food
{

    long int randomnum;
    struct timev t;
    int i;
    gettimeofday(&t,NULL);

    randomnum = + (98456*t.sec) + 34568*t.nsec;
    if (randomnum<0) randomnum= -randomnum;
    return randomnum;
}

int food(int x[],int y[])
{
    if((x[1]==f1 && y[1]==f2))
    {

        int c=0; //c=0 for mis position of food
        int counter;
        do {
            f1=ran()%98; //generate random food
            f2=ran()%47;
            for(counter=1;counter<=len;counter++)
            {
                if (x[counter]==f1 && y[counter]==f2)
                {
                            c=0;
                            break;

                }
                else if(f1==0||f2==0) {
                        c=0;
                        break;
                }
                else c=1;
            }

        }while (c==0);

        locate(f1,f2);
        printf("0");
        len++;
        locate(1,49);
        printf("%d",len-1); //score

        return 1;
    }else if (initial==0) //at starting food generation
    {
        int c=0;
        while (c==0){

            f1=ran()%98;
            f2=ran()%47;

            if (f1 == 1 && f2 == 5) c=0;

            else if(f1 == 0||f2 == 0) c=0;
            else c=1;

        }

        locate(f1,f2);
        printf("0");
        initial=1;
        len++;
        locate(1,49);
        printf("%d",len-1); //score

        return 1;
    }
    else return 0;

}

void direct(int *direction) // change direction
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
                clearscreen();
                main();
                break;

        }
    }

}
void start() // main
{
    screen();
    char input;
    int direction=6,x[100],y[100],extend;
    x[1]=10; //start positoin
    y[1]=5;

    initial=0;
    len=0;
    int counterlen;

    while (1)
    {

        extend=food(x,y); //check for food

        direct(&direction); //change direction

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

        if (extend==0){ //if sanke doesnot eat food
            locate(x[0],y[0]);
            printf(" ");
        }
        locate(x[1],y[1]);
        printf("O");
        Sleep(level);

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
    Firstpage();
}
