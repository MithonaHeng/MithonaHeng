#include<iostream>
using namespace std ;
class teacher {
  private :
    int id ;
    char name [20];
    char sex ;
  public :
    virtual void input();
    virtual void output();
    
};
void teacher ::input(){
  cout<<"Input ID =" ; cin>>id;cin.seekg(0);
  cout<<"Input Name="; cin.get(name,20);
  cin.seekg(0);
  cout<<"Input Sex ="; cin >> sex;
}
void teacher::output()
{
  cout<<id<<"\t";
  cout<<name<<"\t";
  cout<<sex<<endl;
}
class student::public teacher(){
  private:
    float DS,DB,C;
  public :
    void input();
    void output();
    float total();
    float avg();
};
void student::input(){
  teacher :: input();
  cout<<"Enter DataStruct="; cin>>DS;
  cout<<"Enter DataBase="; cin>>DB;
  cout<<"Enter C++="; cin>>C;
}
void student::output(){
  teacher :: output();
  cout<<total()<<"\t";
  cout<<avg()<<endl;
  
}
float student::total(){
  return DS+DB+C;
}
float student :: avg(){
  return total()/3.0;
}
int main(){
  teacher *pt;
  student obs;
  pt=&obs;
  (*pt).input();
  cout<<"ID\tName\tTotal\tAverage\n";
  (*pt).output();
};
