#include<iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;

int main(){
    float dollar,riel,rate,bat;
    char ch,ch1;

    do
    {
        cout<<"Press D change Dollar to riel\n";
        cout<<"Press R change Riel to Dollar\n";
        cout<<"Press B change Bat to riel\n";

        ch=toupper(getch());
        switch (ch)
        {
        case 'D':
            cout<<"Enter Dollar=";cin>>dollar;
            cout<<"Enter Rate=";cin>>rate;
            riel=dollar*rate;
            cout<<"Riel ="<<riel;
            break;
        case 'R':
            cout<<"Enter Riel=";cin>>riel;
            cout<<"Enter Rate=";cin>>rate;
            dollar=riel*rate;
            cout<<"Dollar ="<<dollar;
            break;
        case 'B':
            cout<<"Enter Bat=";cin>>bat;
            cout<<"Enter Rate=";cin>>rate;
            riel=bat*rate;
            cout<<"Riel ="<<riel;
        }
        cout<<"\npress y to continue?";
        char ch1 =tolower(getch());
    }while(ch1=='y');

}