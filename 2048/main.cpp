#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
void display(int p[3][3]);
void mov_func(int p[3][3],int i0,int i1,int i2,int j0,int j1,int j2);

int main()
{
    int i, j, s, a[3][3]={{0,8,9},{7,7,9},{7,8,5}};
    char inp;
display(a);

    //Step1: Insert 2 at Random place
    srand(time(0));
    s=(rand()%9)/3;
    i=s/3; //Column value
    j=s%3; //Row value
    if(1){
        cout<<"jhj"<<s<<i << j<<endl;
    }

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
    step2: display(a);
    cout<<"\nDirection:- \n U-->Up \n R-->Right \n D-->Down \n L-->Left\n"<<endl;

    //Step3: Input decision making
    cin >> inp;
    if(!(inp=='U' || inp=='R' || inp=='D' || inp=='L' || inp=='r' || inp=='u' || inp=='d' || inp=='l' )){
        system("cls");
        cout<<"Enter a valid input\n"<<endl;
        goto step2;
    }

    system("cls");
    display(a);

    //Step4: Decision function
    if((inp=='U' || inp=='u' )){
        cout<<"up func will be executed\n"<<endl;
    }
    else if((inp=='R' || inp=='r' )){
        cout<<"r func will be executed\n"<<endl;
    }
    else if((inp=='D' || inp=='d' )){
        cout<<"d func will be executed\n"<<endl;
        mov_func(a,0,1,2,0,0,0);
    }
    else{
        cout<<"l func will be executed\n"<<endl;
    }

    //Step5: Exit condition
    cout<<"\nGame over";
    return 0;
}

void mov_func(int p[3][3],int i0,int i1,int i2,int j0,int j1,int j2){
        for(int j=0; j<=2; j++){
            int i=0;
            if(p[i+i2][j+j2]==p[i+i1][j+j1]){
                p[i+i2][j+2]=p[i+i2][j+j2]*2;
                p[i+i1][j+j1]=p[i+i0][j+j0];
                p[i+i0][j+j0]=0;
            }
            else if(p[i+i1][j+j1]==p[i+i0][j+j0]){
                p[i+i1][j+j1]=p[i+i1][j+j1]*2;
                p[i+i0][j+j0]=0;
            }
        }
        cout<<"disp"<<endl;
        display(p);
}

void display(int p[3][3]){
    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            cout << p[i][j] <<" ";
        }
        cout<<endl;
    }
}

