#include<iostream>
using namespace std;
class Location
{
public:
	int x, y;  //类对象在二维坐标系中的坐标位置
	void move()  //移动对象的坐标位置
	{
		cout << "请输入新的横坐标：";
		cin >> x;
		cout << "请输入新的纵坐标：";
		cin >> y;
		cout << "新的坐标位置是（" << x << "," << y << ")" << endl;
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
	int r;  //圆半径
	Circle(int m, int n, int v):Point(m,n)
	{
		x = m;
		y = n;
		r = v;
	}
	void draw()
	{
		cout << "圆半径为：" << r << endl;
		cout << "圆心为：" << "(" << x << "," << y << ")" << endl;
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