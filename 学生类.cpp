#include<iostream>
#include<string>
using namespace std;
class student
{
private:
	string name;
	int num;
	bool sex;
	string date;
	double tall, weight, score;
	string address;
public:
	void init()
	{
		string names; 
		int number;
		bool gender;
		string ymd;
		double high, weigh, grade; 
		string add;
		cout << "����ѧ��������ѧ�ţ��Ա𣬳������ڣ���ߣ����أ��߿���������ͥסַ��" << endl;
		cin >> names >> number >> gender >> ymd >> high >> weigh >> grade >> add;
		name = names; 
		num = number; 
		sex = gender;
		date = ymd; 
		tall = high; 
		weight = weigh;
		score = grade; 
		address = add;
	}
	void output()
	{
		cout << "ѧ��������"<< name << endl;
		cout << "ѧ�ţ�"<< num << endl;
		cout << "�Ա�:";
		if(sex) cout << "��" << endl;
		else cout << "Ů" << endl;
		cout << "��������:" << date << endl;
		cout << "��ߣ�" << tall <<"cm"<< endl;
		cout << "���أ�" << weight << "kg"<<endl;
		cout << "������" << score << endl;
		cout << "סַ��" <<address << endl;
	}
	void setName(string names)
	{
		cin >> names;
		name = names;
	}
	void setNum(int number)
	{
		cin >> number;
		num=number;
	}
	void setSex(bool gender)
	{
		cin >> gender;
		sex= gender;
	}
	void setDate(string ymd)
	{
		cin >> ymd;
		date = ymd;
	}
	void setTall(double high)
	{
		cin >> high;
		tall=high;
	}
	void setWeight(double weigh)
	{
		cin >> weigh;
		weight = weigh;
	}
	void setScore(double grade)
	{
		cin >> grade;
		score = grade;
	}
	void setAddress(string add)
	{
		cin >> add;
		address = add;
	}
};void main()
{
	student jumao;
	string namess;
	jumao.init();
	jumao.output();
	jumao.setName(namess);
	jumao.output();
	system("pause");
}