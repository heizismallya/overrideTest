#include <iostream>
using namespace std;

const int& q = 1;

//const对象对const函数的调用
class X{
	int i;
public:
	X(int ii):i(ii){}
	int fun() const
	{
		return i;
	}
	int fun2()
	{
		return i;
	}
};

//mutable
class Z
{
	int i;
	mutable int j;
public:
	Z(int ii,int jj) : i(ii), j(jj){}
	void  fun () const
	{
		//i++;
		j++;
	}
};


int main()
{
	const int& q = 1;
	/*mutable 关键字修饰成员变量，表示它可以在const对象中被修改*/

	/* const对象对const函数的调用*
	X x1(2);
	const X x2(10);

	int ret1 = x1.fun2();
	int ret0 = x1.fun();//ok,非const对象可以调用const函数，和非const 函数
	int ret2 = x2.fun();
	//int ret3 = x2.fun2(); //wrong,编译器不允许const 对象调用非const的成员函数，目的是保护成员变量

	cout << "x1 = " << ret1 << endl;
	cout << "x2 = " << ret2 << endl;
	*/
	system("pause");
	return 0;
}
