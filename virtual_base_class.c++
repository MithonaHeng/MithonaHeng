#include<iostream>
class base{
    protected:float x;
    public:
    base (float xx){this->x=xx;}
    void input(){cout<<"x=";cin>>x;}
    void output(){cout<<"x"<<x<<endl;}

};
class derive1:public virtual base{
    protected: float y;
    public:
        derive1(float xx,float yy);
        base(xx){this->y=yy;}
        void input1(){cout<<"y=";cin>>y;}
        void input(){base::input(); input1();}
        void output1(){cout<<"y="<<y<<endl;}
        void output(){base::output(); output1();}

};
class derive2:public virtual base{
        protected: float t;
    public:
        derive1(float xx,float tt);
        base(xx){this->t=tt;}
        void input2(){cout<<"t=";cin>>t;}
        void input(){base::input(); input2();}
        void output2(){cout<<"y="<<y<<endl;}
        void output(){base::output(); output2();}
};
class derive3:public derive1, public derive2
{

public:
    derive3(float xx,float yy,float tt);
    base(xx),derive1(xx,yy),derive2();
    ...........
    ...........
    void input(){
        base::input();
            derive1::input();
            derive2::input();
    }
    void output(){
        base::output();
            derive1::output();
            derive2::output();
    }
};
void main(){
    derive3 obj(12,22,32);
    cout<<"\n obj data:"<<endl;
    obj.output;
    .........
    .
    ........
}
