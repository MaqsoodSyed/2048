#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void display(int p[3][3]);
void mov_func(int p[3][3],int i0,int i1,int i2,int j0,int j1,int j2,bool sw);

int main()
{
    int i, j, s, a[3][3]={{0,0,0},{0,2,0},{0,0,0}};
    char inp;

    cout<<" CONTROLS: \n\n W or 8 --> Up \n D or 6 --> Right \n S or 5 --> Down \n A or 4 --> Left\n"<<endl;
    _sleep(5000);
    system("cls");

    //Step1: Insert 2 at Random place
    step1: srand(time(0));
    s=(rand()%9)/3;
    i=s/3; //Column value
    j=s%3; //Row value
    for(int q=0; q<=2; q++)
    {
        for(int p=0; p<=2; p++)
        {
            if(a[i][j]==0){
                a[i][j]=2;
                goto step2;
            }
            j++;
            j=j%3;
        }
        i++;
        i=i%3;
    }

    //Step2: Display
    step2: system("cls");
    display(a);

    //Step3: Input decision making
    step3: cin >> inp;
    if(!(inp=='w' ||inp=='8' || inp=='d' || inp=='6' || inp=='a' || inp=='5' || inp=='u' || inp=='d' || inp=='4' )){
        cout<<"!!Enter a valid input!!\n"<<endl;
        goto step3;
    }
    system("cls");
    display(a);

    //Step4: Decision function
    if((inp=='w' || inp=='8' ))
        mov_func(a,2,1,0,0,0,0,0);
    else if((inp=='d' || inp=='6' ))
        mov_func(a,0,0,0,0,1,2,1);
    else if((inp=='s' || inp=='5' ))
        mov_func(a,0,1,2,0,0,0,0);
    else
        mov_func(a,0,0,0,2,1,0,1);

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
