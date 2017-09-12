#include <iostream>
using namespace std;
//运行中多态需要满足三个条件
//1.类之间满足赋值兼容规则
//2.要声明是虚函数
//3.由成员函数来调用或者通过指针，引用来访问虚函数
class B {
public:
	B() : data(0) {
		cout << "default constructor" << endl;
	}
	~B() {
		cout << "destructed by parameter " << data << endl;
	}
	B(int i) : data(i) {
		cout << "constructed by parameter " << data << endl;
	}
	B(const B &b) {
		data = b.data;
		cout << "copyed by parameter " << data << endl;
	}
	B& operator=(const B &b) {
		data = b.data;
		cout << "assigned by parameter " << data << endl;
		return *this;
	}
private:
	int data;
};
//符合类型兼容原则（赋值兼容原则）
//1.派生类对象可以赋值给基类的对象
//2.派生类的对象可以初始化基类的对象
//3.派生类的地址可以赋值给基类的地址
B Play(B b) {
	return b;
}

int main(void) {
	Play(1);
	cout<<endl;
	B t1=Play(2);
	cout<<endl;
	B t2;
	t2=Play(3);
	cout<<endl;
	return 0;
}
#if 0
运行结果：
constructed by parameter 1
copyed by parameter 1
destructed by parameter 1
destructed by parameter 1

constructed by parameter 2
copyed by parameter 2
destructed by parameter 2

default constructor
constructed by parameter 3
copyed by parameter 3
assigned by parameter 3
destructed by parameter 3
destructed by parameter 3

destructed by parameter 3
destructed by parameter 2
#endif
