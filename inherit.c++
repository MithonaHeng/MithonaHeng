#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class person
{
private:
    char *name;
    int age;
    char sex;

public:
    void input();
    void output();
    char *getName(){return name;}

};
 class Hospital{
    private:
    int roomNo;
    int bedNo;
    char illnes[40];
    public:
        void input ();
        void output();

 };
 class Patient:private Hospital
 {
 private:
   int day;
   int month;
   int year;

 public:
    void input();
    void output();
 };
 void person::input(){
    cout<<"Enter Name:";name=new char[20];
    cin.seekg(0);cin.get(name,20);
    cout<<"Enter sex:";cin.seekg(0);cin.sex;
    cout<<"Enter age:";cin>>age;
 }
 void person::output(){
    cout<<name<<"\t";
     cout<<sex<<"\t";
      cout<<age<<"\t";
 }
 void Hospital::input(){
    cout<<"Room number:<<"cin>>roomNo;
    cout<<"Bed number:<<"cin>>bedNo;
    cout<<"Nature of the illnes:"cin.seekg(0);cin.get(illnes,40);

 }
 void Hospital::output(){
       cout<<roomNo<<"\t";
     cout<<bedNo<<"\t";
      cout<<illnes<<"\t";
 }
void Patient::input(){
person::input();
Hospital::input();
cout<<"Date of the patient entry:"<<endl;
cout<<"day:";cin>>day;
cout<<"month:";cin>>month;
cout<<"yaer:";cin>>year;
}
void Patient::output(){
    person::output;
    Hospital::output;
    cout.setf(ios:right);cout.fill('0');
    cout.width(2):cout<<day<<"/";
    cout.width(2):cout<<month<<"/";
    cout.width(4):cout<<year;cout.fill(' ');
    cout<<endl;

}
void search(Patient a[],int n,char *m);
void main(){
    int n;
    char na[20];
    cout<<"Number of Patient:";cin>>n;
    Patient *p=new Patient[n];
    cout<<"Input Data of Student:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Patient "<<(i+1)<<":";
        p[i].input();
    }
    cout<<"\nDisplay data of patient:"<<endl;
    cout<<"Name\t\tSex\tAge\tRoom\tBed\tIllness\tDate\n";
    for (int i = 0; i < n; i++)
    {
         
    }
    
};