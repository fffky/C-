#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
class triangle
{
private:
	double a, b, c;
public:
	void set(double, double, double);
	void form();
	void perimeter();
	void area();
	void type();
};
void triangle::set(double side1, double side2, double side3)
{
	a = side1;
	b = side2;
	c = side3;
}
void triangle::form()
{
	if (a+ b >c&&b + c > a&&a + c > b)
		cout << "�����ܹ���������" << endl;
	else 
		cout << "���߲��ܹ���������" << endl;
}
void triangle::perimeter()
{
	double length;
	length= a + b + c;
	cout << "�������ܳ�Ϊ��" << length << endl;
}
void triangle::area()
{
	double S;
	S = (sqrt((a + b + c)*(a + b - c)*(a - b + c)*(b + c - a)))/4;
	cout << "���������Ϊ��" << S << endl;
}
void triangle::type()
{
	double max,one,two;
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
		cout << "�����������������" << endl;
	if (one*one + two * two == max*max)
		cout << "��������ֱ��������" << endl;
	if (one*one + two * two < max*max)
		cout << "�������Ƕ۽�������" << endl;
}
void main()
{
	triangle sanjiao;
	sanjiao.set(3,4,5);
	sanjiao.form();
	sanjiao.perimeter();
	sanjiao.area();
	sanjiao.type();
	system("pause");
}