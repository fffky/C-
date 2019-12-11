#include<iostream>
using namespace std;
class Triangle
{
private:
	double a, b, c;   //�����������߳�
public:
	double s;  //���
	double l;  //�ܳ�
	Triangle(double aa = 3,double bb = 4, double cc = 5)
	{
		a = aa;
		b = bb;
		c = cc;
	}
	Triangle(const Triangle &sanjiao)
	{
		a = sanjiao.a;
		b = sanjiao.b;
		c = sanjiao.c;
	}
	void area()  //�����
	{
		double half = (a + b + c) / 2;
		s = sqrt(half*(half - a)*(half - b)*(half - c));
		cout << "���������Ϊ��" << s << endl;
	}
	void circulate()  //���ܳ�
	{
		l = a + b + c;
		cout << "�������ܳ�Ϊ��" << l << endl;
	}
	double operator+(Triangle &m)
	{
		double ss;
		ss = this->s + m.s;
		cout << "���֮�ͣ�" << ss << endl;
		return ss;
	}
	Triangle operator=(Triangle &m)
	{
		this->a = m.a;
		this->b = m.b;
		this->c = m.c;
		return *this;
	}
	friend	ostream & operator<< (ostream & out, Triangle &);
};
ostream & operator<< (ostream & out, Triangle & obj)
{
	out << obj.a;
	out << endl;
	out << obj.b;
	out << endl;
	out << obj.c;
	out << endl;
	out << obj.s;
	out << endl;
	out << obj.l;
	out << endl;
	return out;
}
int main()
{
	Triangle jumao(6, 8, 10), jugou;
	jumao.area();
	jumao.circulate();
	jugou.area();
	jugou.circulate();
	cout<<jumao ;
	cout << jugou;
	jumao = jugou;
	jumao.area();
	jumao.circulate();
	cout << jumao;
    jumao + jugou;
	system("pause");
	return 0;
}