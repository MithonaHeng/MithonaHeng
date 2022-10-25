#include<iostream>
#include<windows.h>
using namespace std;
    void gotoxy(short x,short y){
        COORD pos={x,y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    }
int main(){
    int a,b;
    for(a=1;a<=12;a++){
        gotoxy(40-a,3+a);
        for(b=1;b<=2*a-1;b++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 1;
}