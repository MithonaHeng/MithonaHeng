#include<iostream>
#include<fstream>
using namespace std;
class person{
    protected:
        char name[23];
        short age;
    public:
        void getData(){
            cin.seekg(0);
            cout<<"Enter name:";cin.get(name,20);
            cout<<"Enter age:";cin.seekg(0);cin>>age;
        }
        void showData(){
            cout<<name<<"\t"<<age<<endl;
        }
};

int main(){
    person *pers;
    int num;
    fstream outin("PERSON.DAT",ios::binary | ios::out | ios::in);

    cout<<"How many student=";cin>>num;
    pers= new person[num];
    for(int i=0;i<num;i++){
        pers[i].getData();
        outin.write((char*)(&pers[i]),sizeof(person));
    }
    cout<<"Readint Student"<<endl;
    for(int i=0;i<num;i++){
        outin.read((char*)(&pers[i]),sizeof(person));
        pers[i].showData();
    }
    outin.close();
    return 0;
}