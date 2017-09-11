#include<iostream>
#include<string>
using namespace std;
//两个字符串的拼接，用到c++里面的string对象
class character{
public:
    character(string ch):str(ch){};
    character operator+(character& obj){
         return character(str+obj.str);
    }
    string getval(){return str;}
private:
    string str;
};

int main(void){
    character ch1("hello "),ch2("world");;
    character ch3 = ch1+ch2;
    cout<<ch3.getval()<<endl;

    return 0;
}
