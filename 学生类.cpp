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
		cout << "输入学生姓名，学号，性别，出生日期，身高，体重，高考分数，家庭住址：" << endl;
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
		cout << "学生姓名："<< name << endl;
		cout << "学号："<< num << endl;
		cout << "性别:";
		if(sex) cout << "男" << endl;
		else cout << "女" << endl;
		cout << "出生日期:" << date << endl;
		cout << "身高：" << tall <<"cm"<< endl;
		cout << "体重：" << weight << "kg"<<endl;
		cout << "分数：" << score << endl;
		cout << "住址：" <<address << endl;
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