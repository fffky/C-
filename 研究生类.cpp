#include<iostream>
using namespace std;
#include<string.h>
class Graduate
{
private:
	string name;//����
	bool gender;//�Ա�
	int id;//ѧ��
	double score;//��ѧ�ɼ�
	string research;//�о�����
	string tutor;//ָ����ʦ
public:
	static double total, n;   //total���о��������ܷ֣�n���о����������
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
		cout << "��" << endl;
	else cout << "Ů" << endl;
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
		cout << "��" << endl;
	else cout << "Ů" << endl;
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
	if (p.score > 90) cout << "�ɼ��ȼ�ΪA" << endl;
	else if (p.score >= 80 && p.score < 90) cout << "�ɼ��ȼ�ΪB" << endl;
	else if (p.score >= 70 && p.score < 80) cout << "�ɼ��ȼ�ΪC" << endl;
	else if (p.score >= 60 && p.score < 70) cout << "�ɼ��ȼ�ΪD" << endl;
	else cout << "�ɼ��ȼ�ΪE" << endl;
}
int main()
{
	double average;
	Graduate jugou("jugou", 1, 1101, 59, "zhongdi", "sunchao");
	Graduate jumao("jumao", 0, 1199, 87, "IT", "wang");
	Graduate buou("buou", 0, 1144, 99, "IT", "zhang");
	average = Graduate::total / Graduate::n;
	cout << "����о��������ƽ���ɼ�: " << average << endl;
	evaluate(jugou);
	system("pause");
	return 0;
}