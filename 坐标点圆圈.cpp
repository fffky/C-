#include<iostream>
using namespace std;
class Location
{
public:
	int x, y;  //������ڶ�ά����ϵ�е�����λ��
	void move()  //�ƶ����������λ��
	{
		cout << "�������µĺ����꣺";
		cin >> x;
		cout << "�������µ������꣺";
		cin >> y;
		cout << "�µ�����λ���ǣ�" << x << "," << y << ")" << endl;
	}
	Location(int m, int n)
	{
		x = m;
		y = n;
	}
};
class Point :public Location
{
public:
	Point(int m, int n):Location(m, n)
	{
		x = m;
		y = n;
	}
};
class Circle :public Point
{
public:
	int r;  //Բ�뾶
	Circle(int m, int n, int v):Point(m,n)
	{
		x = m;
		y = n;
		r = v;
	}
	void draw()
	{
		cout << "Բ�뾶Ϊ��" << r << endl;
		cout << "Բ��Ϊ��" << "(" << x << "," << y << ")" << endl;
	}
};
int main()
{
	Circle one(0,0,1);
	one.draw();
	one.move();
	one.draw();
	system("pause");
	return 0;
}