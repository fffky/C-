#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
class triangle
{
private:
	double a, b, c;
public:
	void set(double, double, double);    //初始化三角形三条边
	void form();                         //判断能不能构成三角形
	void perimeter();                    //求三角形周长
	void area();                         //求三角形面积
	void type();                         //判断三角形类型
	void size();                         //输出各成员变量的长度
	void where();                        //输出各成员变量的地址
};
void triangle::set(double side1, double side2, double side3)
{
	a = side1;
	b = side2;
	c = side3;
}
void triangle::form()
{
	if (a + b > c&&b + c > a&&a + c > b)
		cout << "三边能构成三角形" << endl;
	else
		cout << "三边不能构成三角形" << endl;
}
void triangle::perimeter()
{
	double length;
	length = a + b + c;
	cout << "三角形周长为：" << length << endl;
}
void triangle::area()
{
	double S;
	S = (sqrt((a + b + c)*(a + b - c)*(a - b + c)*(b + c - a))) / 4;
	cout << "三角形面积为：" << S << endl;
}
void triangle::type()
{
	double max, one, two;
	if (a >= b)
	{
		if (c > a)
		{
			max = c;
			one = a; two = b;
		}
		else
		{
			max = a;
			one = b; two = c;
		}
	}
	else
	{
		if (c > b)
		{
			max = c;
			one = a; two = b;
		}
		else
		{
			max = b;
			one = a; two = c;
		}
	}
	if (one*one + two * two > max*max)
		cout << "三角形是锐角三角形" << endl;
	if (one*one + two * two == max * max)
		cout << "三角形是直角三角形" << endl;
	if (one*one + two * two < max*max)
		cout << "三角形是钝角三角形" << endl;
}
void triangle::size()
{
	cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << endl;
}
void triangle::where()
{
	cout << "当前对象a对象的起始地址：" << &this->a << endl;
	cout << "当前对象b对象的起始地址：" << &this->b << endl;
	cout << "当前对象c对象的起始地址：" << &this->c << endl;
}
int main()
{
	triangle sanjiao, jumao, buou, hu, xiong, gou;
	sanjiao.set(3, 4, 5);
	sanjiao.form();
	sanjiao.perimeter();
	sanjiao.area();
	sanjiao.type();
	sanjiao.size();
	cout << sizeof(sanjiao) << endl;     //输出对象的长度
	cout << &sanjiao << " " << &jumao << " " << &buou << " " << &hu << " " << &xiong << " " << &gou << endl;  //输出每个对象的地址
	sanjiao.where();           //输出sanjiao该对象的各成员变量的地址
	system("pause");
	return 0;
}