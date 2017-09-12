#include<iostream>
using namespace std;

class Demo{
public:
    Demo(int x):a(x){};//初始化参数列表
    //相当于Demo(int x){
    //    a=x;
    //}
    //当重载为成员函数时，函数的参数个数要比原来的参数个数少一个
    //因为第一个参数会被作为函数调用的目的对象，即隐式传递
    int operator+ (Demo& obj2){
        return this->a+obj2.a;
    }
    //当重载为非成员函数时，即声明为友元函数或者类外部的公共函数时
    //参数个数与原来的操作数相等，即显示通过函数参数传递
    friend int operator- (Demo& obj1,Demo& obj2){
        return obj1.a-obj2.a;
    }
    friend Demo& operator++(Demo& obj, int){
        obj.a+=1;
        return obj;
    }
    int getval(){return a;}
private:
    int a;
};

int main(void){
    Demo obj1(12);
    Demo obj2(21);

    cout<<obj1+obj2<<endl;
    cout<<obj1-obj2<<endl; 
    obj1++;
    cout<<obj1.getval()<<endl;   
    return 0;
}
