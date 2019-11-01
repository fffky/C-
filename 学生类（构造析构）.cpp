#include <iostream>
using namespace std;
#include<string>
class student
{
private:
	string name;
	int id;
	int age;
	string address;
public:
	student();
	student(string name, int id, int age, string address);
	student(const student&classmate);
	~student();
	string getName();        //获取学生姓名
	int getId();           //获取学生学号
	int getAge();          //获取学生年龄
	string getAddress();   //获取学生住址
	void setName(string name);    //修改学生姓名
	void setId(int id);         //修改学生学号
	void setAge(int age);       //修改学生年龄
	void setAddress(string address);         //修改学生地址
	void output();         //输出学生信息
};
student::student()
{

}
student::~student()
{

}
student::student(string name, int id, int age, string address)
{
	this->name = name;
	this->id = id;
	this->age = age;
	this->address = address;
}
student::student(const student &classmate)
{
	this->name = classmate.name;
	this->id = classmate.id;
	this->age = classmate.age;
	this->address = classmate.address;
}
string student::getName()
{
	return name;
}
int student::getId()
{
	return id;
}
int student::getAge()
{
	return age;
}
string student::getAddress()
{
	return address;
}
void student::setName(string name)
{
	this->name = name;
}
void student::setId(int id)
{
	this->id = id;
}
void student::setAge(int age)
{
	this->age = age;
}
void student::setAddress(string address)
{
	this->address = address;
}
void student::output()
{
	cout << "学生姓名：" << name << endl;
	cout << "学号：" << id << endl;
	cout << "年龄：" << age << endl;
	cout << "住址：" << address << endl;
}
int main()
{
	student jumao;
	student jugou("jugou", 14, 19, "gouguo");
	student chougou(jugou);
	jugou.getId();
	jugou.getAge();
	jugou.output();
	chougou.setAddress("gouwo");
	chougou.output();
	system("pause");
	return 0;
}