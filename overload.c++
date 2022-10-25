#include<iostream>
#include<conio.h>
using namespace std;
int sum(int a,int b){
    return a+b;
}
float sum(float a,float b){
    return a+b;
}
int sum(int a,int b,int c){
    return a+b+c;
}
void main(){
    int a=1,b=2,c=3;
    float m=90.00,n=66,50;
    cout<<"sum(a,b)"=<<sum(a,b)<<endl;
    cout<<"sum(m,n)"=<<sum(m,n)<<endl;
    cout<<"sum(a,b,c)"=<<sum(a,b,c)<<endl;
    getch();
}