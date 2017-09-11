#include<iostream>
using namespace std;

template<class T,typename T1>
T func(T a,T1 b){
    return a+b;
}
/*
template<class T,int T1>//非模板函数
T func(T a,T1 b){
    return a+b;
}*/
template<class T>
class Demo{
public:
    //Demo(T x):value(x){}
    Demo(T x);
    T getval();
    
private:
    T value;
    static int q;
};

template <class T>
Demo<T>::Demo(T x){
    value = x;
}

template<class T>
T Demo<T>::getval(){
    return value;
}
int main(void){
    //cout<<func<int,double>(21.,34.322432)<<endl;
    Demo<int> obj(10);
    cout<<obj.getval()<<endl;
    cout<<a<<endl;
    return 0;
}
