#include<iostream>
#include<fstream>
using namespace std;
int main(){
    fstream outin;
    char ch;
    outin.open("myfile.txt",ios::out | ios::in);
    while((ch=cin.get())!='$'){
        outin.put(ch);
    }
    cout<<"Reading the file"<<endl;
    outin.seekg(0,ios::beg);
    ch='\0';
    while(ch!=EOF){
        ch=outin.get();
        cout<<ch;

    }outin.close();
    return 0;
}