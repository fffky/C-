#include<iostream>
using namespace std;
class base
{
public:
	int a;
	static int count;
	void print()
	{
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		cout<<"c=" << c << endl;
	}
	static int statistic()   //ͳ��������������
	{
		cout << "��������: " << count << endl;
	}
	base() { count++; cout << "1" << endl; }
	~base() { count++; cout << "2" << endl; }
	void set(int m, int n, int v)
	{
		a = m;
		b = n;
		c = v;
		count++;
	}
protected:
	int b;
private:
	int c;
};
int base::count = 0;
class derived1 :public base
{
public:
	int d;
	void setall(int z,int x,int c,int v)
	{
		set(z, x, c);
		d = v;
	}
	void showall()
	{
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;      //b��Ϊ������ı�����Ա�����Է���
		//cout << "c=" << c << endl;    //�����˽�г�Աc���ܱ�����
		cout << "d=" << d << endl;
	}
	derived1() { cout << "3" << endl; }
	~derived1() { cout << "4" << endl; }
};
class derived2 :protected base
{
public:
	int d;
	void setall(int z, int x, int c, int v)
	{
		set(z, x, c);
		d = v;
	}
	void showall()
	{
		cout << "a=" << a << endl;   //a��Ϊ������ı�����Ա�����Է���
		cout << "b=" << b << endl;   //b��Ϊ������ı�����Ա�����Է���
		//cout << "c=" << c << endl;    //�����˽�г�Աc���ܱ�����
		cout << "d=" << d << endl;
	}
};
class derived3 :private base
{
public:
	int d;
	void setall(int z, int x, int c, int v)
	{
		set(z, x, c);
		d = v;
	}
	void showall()
	{
		cout << "a=" << a << endl;      //a��Ϊ�������˽�г�Ա�����Է���
		cout << "b=" << b << endl;      //b��Ϊ�������˽�г�Ա�����Է���
		//cout << "c=" << c << endl;    //�����˽�г�Աc���ܱ�����
		cout << "d=" << d << endl;
	}
};
int main()
{
	cout<<sizeof(derived1)<<endl;
	cout<<sizeof(base)<<endl;
	derived1 obj;
	system("pause");
	return 0;
}