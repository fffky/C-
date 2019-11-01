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
	string getName();        //��ȡѧ������
	int getId();           //��ȡѧ��ѧ��
	int getAge();          //��ȡѧ������
	string getAddress();   //��ȡѧ��סַ
	void setName(string name);    //�޸�ѧ������
	void setId(int id);         //�޸�ѧ��ѧ��
	void setAge(int age);       //�޸�ѧ������
	void setAddress(string address);         //�޸�ѧ����ַ
	void output();         //���ѧ����Ϣ
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
	cout << "ѧ��������" << name << endl;
	cout << "ѧ�ţ�" << id << endl;
	cout << "���䣺" << age << endl;
	cout << "סַ��" << address << endl;
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