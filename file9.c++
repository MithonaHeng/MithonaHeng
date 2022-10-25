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
int main(){
    student stu;
    ifstream fin("stu.bin",ios::binary |ios::in |ios::ate);
    cout<<"All student backward\n";
    student::heading();
    long n=fin.tellg()/sizeof(student);
    for (int i=n;i>0;i--){
        fin.seekg((i-1)*sizeof(student),ios::beg);
        fin.read((char*)&stu,sizeof(student));
        stu.output();
    }
    fin.close();
    return 1;
}