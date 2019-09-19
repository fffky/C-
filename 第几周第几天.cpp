#include<iostream>
using namespace std;
#include<stdio.h>

int main()
{
	int year, month, day, i, days = 0;
	char c1, c2;
	cout << "请输入年月日（年-月-日）" << endl;
	scanf_s("%d", &year, 4);
	scanf_s("%c", &c1, 1);
	scanf_s("%d", &month, 2);
	scanf_s("%c", &c2, 1);
	scanf_s("%d", &day, 2);
	if ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
	{
		for (i = 1; i <=month-1; i++)
		{
			if (i == 4 || i == 6 || i == 9 || i == 11) days += 30;
			else if (i == 2) days += 29;
			else days += 31;
		}
		
	}
	else
	{
		for (i = 1; i <=month-1; i++)
		{
			if (i == 4 || i == 6 || i == 9 || i == 11) days += 30;
			else if (i == 2) days += 28;
			else days += 31;
		}
		
	}
	days += day;
	cout << "该天是该年的第"<<days<<"天"<< endl;
	if (month == 1 && day >= 1 && day <= 7) i = 1;
	else
	{
		i = days / 7;
		if (days % 7 != 0) i++;
	}
	cout << "该天是该年的第"<<i<<"周" << endl;
	system("pause");
	return 0;
}
