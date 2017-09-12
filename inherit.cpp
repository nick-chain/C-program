#include<iostream>
#include<string>
using namespace std;
//基类

class student{
public:
    student(string n, int a,int height):age(a),name(n),height(height){
        cout<<"------------base class-----------------"<<endl;
    }
    ~student(){
        cout<<"------------ ~~ class-----------------"<<endl;        
    }
    void get(){
        cout<<"name:"<<name<<" age:"<<age<<"height "<<height<<endl;
    }
protected:
    int height;
private:
    string name;
    int age;
};
//派生类,公有继承，基类的公有成员和保护成员的访问属性在派生类的属性不变
//即该公有的公有，该保护的保护
//基类的私有成员依旧不能直接访问
//保护继承，基类的公有成员和保护成员的访问属性在派生类中以保护成员出现
//私有继承，-------------------------在派生类中以私有成员出现
//都不能直接访问基类的私有成员

class midstudent:public student{
public:
    midstudent(string n, int a,int height, int score):student(n,a,height),score(score){
        cout<<"------------child class-----------------"<<endl;        
    }
    ~midstudent(){
        cout<<"------------ ~~ child class-----------------"<<endl;        
    }
    //只能通过基类构造函数的参数初始化列表来初始化基类的成员变量
    void getvalue(){
        get();
        cout<< "socre:"<<score<<endl;
    }
private:
    int score;
};

int main(void){
    midstudent stu("chenheng",23,170,99);
    stu.getvalue();
    return 0;
}
