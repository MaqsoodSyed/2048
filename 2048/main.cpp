#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void display(int p[3][3]);
void mov_func(int p[3][3],int i0,int i1,int i2,int j0,int j1,int j2,bool sw);

int main()
{
    int i, j, s, a[3][3]={{0,0,0},{0,2,0},{0,0,0}};
    char inp;

    cout<<"Controls: \n\n\n  \t ^  \n\n <\t v  \t > \n"<<endl;
    _sleep(1500);
    system("cls");

    //Step1: Insert 2 at Random place
    step1: srand(time(0));
    s=(rand()%9)/3;
    i=s/3; //Column value
    j=s%3; //Row value
    for(int j=0; j<=2; j++)
    {
        for(int i=0; i<=2; i++)
        {
            if(a[i][j]==0){
                a[i][j]=2;
                goto step2;
            }
        }
    }

    //Step2: Display
    step2: system("cls");
    display(a);

    //Step3: Input direction

        int c = 0;
        c=getch();
        switch(c) {
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            mov_func(a,2,1,0,0,0,0,0);
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            mov_func(a,0,1,2,0,0,0,0);
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            mov_func(a,0,0,0,2,1,0,1);
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            mov_func(a,0,0,0,0,1,2,1);
            break;
        }


    //Step5: Exit condition
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if(a[i][j]==0){
                goto step1;
            }
        }
    }
    cout<<"\nGame over";
    cout<<"\n\n\t-by SYED MAQSOOD\n\n";

    _sleep(3000);
    return 0;
}

void display(int p[3][3]){
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            cout << p[i][j] <<"\t";
        }
        cout<<"\n"<<endl;
    }
}

void mov_func(int p[3][3],int i0,int i1,int i2,int j0,int j1,int j2,bool sw){
    for(int j=0; j<=2; j++){
        int i=0;
        if(sw==1){
            int temp=i;
            i=j;
            j=temp;
        }

        //addition comnditions
        if(p[i+i2][j+j2]==p[i+i1][j+j1]){
            p[i+i2][j+j2]=p[i+i2][j+j2]*2;
            p[i+i1][j+j1]=p[i+i0][j+j0];
            p[i+i0][j+j0]=0;
        }
        else if(p[i+i1][j+j1]==p[i+i0][j+j0]){
            p[i+i1][j+j1]=p[i+i1][j+j1]*2;
            p[i+i0][j+j0]=0;
        }
        if(p[i+i1][j+j1]==0){
            if(p[i+i2][j+j2]==p[i+i0][j+j0]){
                p[i+i2][j+j2]=p[i+i2][j+j2]*2;
                p[i+i0][j+j0]=0;
            }
        }

        //moving conditions
        if(p[i+i2][j+j2]==0){
            if(p[i+i1][j+j1]==0){
                p[i+i1][j+j1]= p[i+i0][j+j0];
                p[i+i0][j+j0]=0;
            }
            p[i+i2][j+j2]= p[i+i1][j+j1];
            p[i+i1][j+j1]=p[i+i0][j+j0];
            p[i+i0][j+j0]=0;
        }
        else if(p[i+i1][j+j1]==0){
            p[i+i1][j+j1]=p[i+i0][j+j0];
            p[i+i0][j+j0]=0;
        }

        if(sw==1){
            int temp=i;
            i=j;
            j=temp;
        }
    }
}
