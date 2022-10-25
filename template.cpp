#include<iostream>
#include<string.h>
using namespace std;

template<class T>//Template definition of swap()
void Swap(T &x, T &y)//Values passed on by reference
{
    T temp;
    temp =x;
    x=y;
    y= temp;

} 
int main(){
    int n =60, m=30 ;
    char ch1='A',ch2='D';
    double a=2.45,b=4.76;
    char *S1="Morning";//S1 and S2 are string objects
    char *S2="Evening";//their type is string
    Swap(a,b);
    Swap(ch1,ch2);
    Swap(n,m);
    Swap(S1,S2);//swapping user defined data

    cout<<" a      ="<<a<<"\tb      ="<<b<<"\n";
    cout<<"ch1      ="<<ch1<<"\tch2      ="<<ch2<<endl;
    cout<<" n      ="<<n<<"\tm       ="<<m<<"\n";
    cout<<" S1      ="<<S1<<"\tS2      ="<<S2<<endl;
}