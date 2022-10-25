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
    person *Write,Read;
    int num;
    ofstream out("PERSON.DAT",ios::binary);

    cout<<"How many student=";cin>>num;
    Write=new person[num];
    for(int i=0;i<num;i++){
        Write[i].getData();
        out.write((char*)(&Write),sizeof(person));
    }
    out.close();
    ifstream in("PERSON.DAT",ios::binary);

    cout<<"Readint Student"<<endl;
    while(in.read((char*)(&Read),sizeof(Read))){
        Read.showData();
    }
    in.close();
    return 0;
}