#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class person{
  protected:
    char id[20];
    char name[20];
    char sex;
};
class dob{
  protected:
    int day;
    int month;
    int year;
};
class employee:public person,public dob{
  private:
    char tel[15];
    float salary;
  public:
    char *getName(){
      return name;
    }
    void input_Data();
    void show_Data();
    float tax_Salary();
};
void employee::input_Data(){
  cout<<"Enter id = ";cin.seekg(0); cin.get(id,20);
  cout<<"Enter name = ";cin.seekg(0); cin.get(name,20);
  cout<<"Enter sex = ";cin>>sex;
  cout<<"Enter tel = ";cin.seekg(0); cin.get(tel,15);
  cout<<"Enter salary = ";cin>>salary;
}
  

void  search(employee em[],int n)
{
  int i;
  char sname[20];
  int k = 0;
  cout<<"Enter name to search = ";cin.seekg(0);
  cin.get(sname, 20);
  for(i=0;i<n;i++)
      if(strcmp(em[i].getName(),sname) == 0){
        k = k+1;
        em[i].show_Data();
    }
    if(k==0)
       cout<<"Search not found";
    
    
}
float employee::tax_Salary(){
  if(salary<300){
    return salary * 0.01;
  }
  else{
    return salary * 0.05;
  }
}
void employee::show_Data(){
  cout<<"id = "<<id<<"\tname = "<<name<<"\tsex = "<<sex<<"\ttax_salary = "<<tax_Salary()<<"\tTel = "<<tel<<endl;
}

int main(){
  int i, n;
  cout<<"Enter n = "; cin>>n;
  employee *emp = new employee[n];
  for(i=0; i<n; i++){
    emp[i].input_Data();
  }
  search(emp, n);
};