#include <iostream>
using namespace std;
#include<math.h>
class Point     //�������
{
private:
	double x;   //������
	double y;   //������
	
public:
	Point()
	{

	}
	Point(double a, double b)
	{
		this->x = a;
		this->y = b;
	}
	Point(const Point& r)
	{
		x = r.x;
		y = r.y;
	}
	~Point()
	{

	}
	double GetX(); //��ȡ������
	double GetY(); //��ȡ������
	void SetX(double ax); //�޸ĺ�����
	void SetY(double bx); //�޸�������
	void SwapAxis(double *xa,double *xb); //��������ֵ
	friend double GetLength(Point& A, Point& B);//�����������
};

double Point::GetX()
{
	return x;
}
double Point::GetY()
{
	return y;
}
void Point::SetX(double ax)
{
	this->x = ax;
}
void Point::SetY(double bx)
{
	this->y = bx;
}
void SwapAxis(double *xa,double *xb)
{
	double t;
	t = *xa;
	*xa = *xb;
	*xb = t;
}
double GetLength(Point& A, Point& B)
{
	double s;
	s = sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
	cout << "���룺" << s<<endl;
	return s;
}
int main()
{
	Point *p; int i; 
	Point array_stack[10] = {Point(1,3),Point(9,3) ,Point(4,3) ,Point(5,1) ,Point(6,2.4) ,Point(1.4,3.9) ,Point(4.56,3) ,Point(4.5,4.5) ,Point(0,3.8) ,Point(1,0) };
	Point *p1 = array_stack;
	Point *array_heap = new Point[10]{ Point(4,9),Point(5,9.4) ,Point(1.6,9) ,Point(7,4) ,Point(2,3) ,Point(0,1) ,Point(1,0) ,Point(5.5,6) ,Point(4.8,9) ,Point(0,1) };
    for (p = array_stack,i=0; p < array_stack + 10; p++,i++)
	{
		GetLength(array_stack[i], array_heap[i]);
	}
	delete []array_heap;
	system("pause");
	return 0;
}