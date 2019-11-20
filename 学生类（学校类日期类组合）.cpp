#include<iostream>
using namespace std;
#include<string>
#include<cstdlib>
#include<time.h>
class school
{
public:
	string address;//所在学校地址
	school(string add)
	{
		address = add;
	}
	~school()
	{

	}
};
class date
{
public:
	int year;
	int month;
	int day;

	date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
class student
{
private:
	string name;
	bool gender;
	double GPA;//绩点
	school a1;
	date b1;
public:
	static int total;
	student(string nam, bool gend, string add, int y, int m, int d) :a1(add), b1(y, m, d)
	{
		srand((int)time(NULL));
		name = nam;
		gender = gend;
		GPA = (rand() % 401 + 0) / 100;
		total++;

	}
	~student()
	{

	}
	void display()const
	{
		cout << b1.year << "-" << b1.month << "-" << b1.day << endl;
		cout << "当前年龄:" << 2020 - b1.year << endl;
	}
	void show()const
	{
		cout << a1.address << endl;
	}
};
int student::total = 0;
int main()
{

	student jumao("jumao", 1, "sdnu", 2000, 7, 28);
	student jugou("jugou", 0, "sdau", 1999, 6, 27);
	jumao.display();
	jumao.show();
	cout << "当前已构建的学生类对象的个数：" << student::total << endl;
	system("pause");
	return 0;
}