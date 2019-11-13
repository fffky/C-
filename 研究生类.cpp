#include<iostream>
using namespace std;
#include<string.h>
class Graduate
{
private:
	string name;//姓名
	bool gender;//性别
	int id;//学号
	double score;//入学成绩
	string research;//研究领域
	string tutor;//指导教师
public:
	static double total, n;   //total是研究生对象总分，n是研究生对象个数
	Graduate();
	Graduate(string nam, bool gd, int idd, double sco, string resa, string ttor);
	Graduate(const Graduate &gra);
	~Graduate();
	string getname();
	void getgender();
	int getid();
	double getscore();
	string getresearch();
	string gettutor();
	string getname() const;
	void getgender() const;
	int getid() const;
	double getscore() const;
	string getresearch() const;
	string gettutor() const;
	friend void evaluate(Graduate&);
};
double Graduate::total = 0;
double Graduate::n = 0;
Graduate::Graduate()
{
	total += score;
	n++;
}
Graduate::Graduate(string nam, bool gd, int idd, double sco, string resa, string ttor)
{
	name = nam;
	gender = gd;
	id = idd;
	score = sco;
	research = resa;
	tutor = ttor;
	total += score;
	n++;
}
Graduate::Graduate(const Graduate &gra)
{
	name = gra.name;
	gender = gra.gender;
	id = gra.id;
	score = gra.score;
	research = gra.research;
	tutor = gra.tutor;
	total += score;
	n++;
}
Graduate::~Graduate()
{

}
string Graduate::getname()
{
	return name;
}
void Graduate::getgender()
{
	if (gender == 1)
		cout << "男" << endl;
	else cout << "女" << endl;
}
int Graduate::getid()
{
	return id;
}
double Graduate::getscore()
{
	return score;
}
string Graduate::getresearch()
{
	return research;
}
string Graduate::gettutor()
{
	return tutor;
}
string Graduate::getname() const
{
	return name;
}
void Graduate::getgender() const
{
	if (gender == 1)
		cout << "男" << endl;
	else cout << "女" << endl;
}
int Graduate::getid() const
{
	return id;
}
double Graduate::getscore() const
{
	return score;
}
string Graduate::getresearch() const
{
	return research;
}
string Graduate::gettutor() const
{
	return tutor;
}
void evaluate(Graduate &p)
{
	if (p.score > 90) cout << "成绩等级为A" << endl;
	else if (p.score >= 80 && p.score < 90) cout << "成绩等级为B" << endl;
	else if (p.score >= 70 && p.score < 80) cout << "成绩等级为C" << endl;
	else if (p.score >= 60 && p.score < 70) cout << "成绩等级为D" << endl;
	else cout << "成绩等级为E" << endl;
}
int main()
{
	double average;
	Graduate jugou("jugou", 1, 1101, 59, "zhongdi", "sunchao");
	Graduate jumao("jumao", 0, 1199, 87, "IT", "wang");
	Graduate buou("buou", 0, 1144, 99, "IT", "zhang");
	average = Graduate::total / Graduate::n;
	cout << "多个研究生对象的平均成绩: " << average << endl;
	evaluate(jugou);
	system("pause");
	return 0;
}