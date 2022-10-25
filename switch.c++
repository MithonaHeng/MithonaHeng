#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int a,b;
    char ch;
    cout<<"Press + for sum\n";
    cout<<"Press - for sub\n";
    cout<<"Press * for mult\n";

    ch=getchar();
    switch (ch)
    {
    case '+':
        cout<<"Enter a:";cin>>a;
        cout<<"Enter b:";cin>>b;
        cout<<"Sum ="<<a+b;
        break;
        
    case '-':
        cout<<"Enter a:";cin>>a;
        cout<<"Enter b:";cin>>b;
        cout<<"Sum ="<<a-b;
        break;
    
    case '*':
        cout<<"Enter a:";cin>>a;
        cout<<"Enter b:";cin>>b;
        cout<<"Sum ="<<a*b;
        break;
    }
    return 0;
};