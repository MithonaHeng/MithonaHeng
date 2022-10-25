#include<iostream>
using namespace std;
class base{
	public:
		virtual void who(void){
			cout<<"Base \n";
		}
};
class first_d: public base{
	public:
		void who (void){
			cout<<"First derivation\n";
		}
};
class second_d :public base{
//	who not defined

};
int main(){
	base bobj;
	base *p;
	first_d first_obj;
	second_d second_obj;
	p=&bobj;
	p->who();
	p=&first_obj;
	p->who();
	p=&second_obj;
	p->who();
	
}
