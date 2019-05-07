#include <iostream>
using namespace std;

class Base
{
public:
	//下面3个fun是重载，重载是在同一个类里，参数，返回值都可以不同，函数名相同
	void fun()
	{
		cout << "Base::fun1" << endl;
	};

	void fun(int i)
	{
		cout << "Base::fun2" << endl;
	};

	int fun(int i, int j)
	{
		cout << "base::fun3" << endl;
		return 0;
	};
	//这里编译出错，因为编译器不能判定返回值来区别函数，与第一个void fun()分不清
	/*int fun()
	{
		cout << "base::fun4" << endl;
		return 0;
	}*/

	//over write test
	virtual int fun1()
	{
		cout <<"base::fun5"<<endl;
		return 0;
	}

};

class Child : public Base
{
public:
	//over write,重写父类的函数，发生在继承里
	int fun(int i, int j)
	{
		cout << "child::fun3"<< endl;
		return 1;
	}

	//为了保证多态，虚机制，这里的返回值绝对不能变
	//int fun1()
	//{
	//	cout << "child::fun5"<< endl;
	//	return 1;
	//}
	//子类内部重载，并不影响虚机制
	int fun1(int i)
	{
		cout << "child::fun6"<<endl;
		return 2;
	}
};


int main(void)
{
	//overload test
	Base b ;
	Base* base = &b;
	base->fun(1,2);
	base->fun();
	base->fun(1);
	//int a= fun();
	//over write test
	Child c;
	Child* child = &c;
	child->fun(1,3);
	child->fun1();
	//多态,基类指针指向子类对象，调用虚函数，实现子类动作
	Base* base1 = &c;
	base1->fun1();
	//这里子类对象向上转型，发生切片，基类根本没有带参数的fun1,所以这里编译报错
	//base1->fun1(1);
	//子类内部重载，不影响虚机制
	child->fun1(5);
	//redefine 子类重定义基类的重载函数后，基类其他的重载函数被隐藏，这里就不能调用基类的fun1无参的
	//child->fun1();


	system("pause");
	return 0;
}
