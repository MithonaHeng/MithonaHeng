#include<iostream>
using namespace std;
class A
{
public:
    void say(){
        cout<<"Hello World"<<endl;
    }
};

class B:public virtual A{};
class C:public virtual A{};
class D:public virtual C{};
int main(){
    D obj;
    obj.say();
}
