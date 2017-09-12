#include<iostream>
using namespace std;

class base1{
public:
    int var;
    void fun(){cout<<"----------base1-----------"<<endl; }
};

class base2{
public:
    int var;
    void fun(){cout<<"----------base2-----------"<<endl; }
};

class Derived:public base1,public base2{
public:
    int var;
    void fun(){cout<<"----------Derived-----------"<<endl; }
};

int main(void){
    Derived a;
    Derived* p = &a;

    a.var = 10;//通过对象.成员名来标识，访问类成员
    a.fun();

    a.base1::var=20;//通过作用域分辨符标识，访问类成员
    a.base1::fun();

    p->base2::var=3000;//通过作用域分辨符标识
    p->base2::fun();
    
    return 0;
}
