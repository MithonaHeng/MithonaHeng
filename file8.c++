#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class student{
    private:
        int id;
        char name;
        float av;
    public:
        void input();
        void output();
        static void heading();
    
};
void student::input(){
    cout<<"Input id:";cin>>id;cin.clear();cin.seekg(0,ios::end);
    cout<<"Input name:";cin.get(name,23);
    cout<<"Input av:";cin>>av;
}
void student::output(){
    cout<<id<<'\t';
    cout.setf(ios::left|ios::fixed|ios::showpoint);
    cout.width(10);
    cout<<name<<'\t';
    cout.precision(2);
    cout<<av<<'\t';
    cout<<endl;
}
void student::heading(){
    cout<<"\nID\tNAME\t\tAverage\n";
    cout<<"===========================";
    cout<<endl;
}
int main(){
        student stu[23];
        for(int i=0;i<5;i++){
            stu[i].input();
            cout<<endl;
        }

        cout<<"\n Save to file\n";
    ofstream out("stu.bin",ios::binary);
        if(out.fail()){
            cout<<"Error in opening file\n";
            return;
        }
        out.write((char*)&stu,5*sizeof(student));
        out.close();
    ifstream fin("stu.bin",ios::binary|ios::in|ios::ate);
        cout<<"All student \n";
        student::heading();
        fin.seekg(0,ios::beg);
        for(int i=0;i<5;i++){
            fin.read((char *)&stu[i],sizeof(student));
            stu[i].output();
    }
    fin.close();
    return 0;
}