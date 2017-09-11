#include<iostream>
using namespace std;
//一旦在类里面生命为友元函数，即为该类非成员函数了，即共享函数
class A{
public:
    void display(){cout<<x<<endl;}
    int getx(){return x;}
    friend class B; //B是A的有元类
private:
     static int x;
};
int A::x=2;//要初始化
class B{
public:
    void set(int i);
    //void display();
private:
     A a;
};

void B::set(int i){
    a.x = i;
}

class Demo{
public:
    Demo(int i):x(i){}
    friend Demo operator+(Demo& obj1, Demo& obj2){
    /*    Demo obj3(100);
        obj3.x = obj1.x+obj2.x;*/
        return Demo(obj1.x+obj2.x);
    }
    friend Demo operator++(Demo &a,int){
        a.x = a.x+1;
        return a;
    }
     friend Demo& operator++(Demo &a){
        a.x = a.x+1;
        return a;
    }
    int getvuale(){
        return x;
    }
    /*int operator+(Demo &obj){
        return x+obj.x;//运算符的重载
    }*/
private:
    int x;
};

int main(void){
    /*B obj1,obj3;
    A obj2;
    obj2.display();
    obj1.set(10);
    obj3=obj1;
    obj2.display();
    cout<<obj2.getx()<<endl;
*/
    Demo a(10),b(40);
    Demo c=a+b;
    //cout<<a+b<<endl;//相当于a.operator+(b);
    a++;
    ++a;
    cout<<a.getvuale()<<endl;
    cout<<c.getvuale()<<endl;
    return 0;
}





