//ax^2+bx+c=0;目标方程
#include<iostream>
using namespace std;
#include<math.h>
double solve(double a, double b, double c)
{
	double  x1=0,//第一个解
			x2=0,//第二个解
			dirt=0;//判别式
	if (a == 0)//当a=0，为一元一次方程
	{
		x1 = -c / b;
		cout << "answer is " << x1<< "\n";
	}
	else//当a不等于零
	{
		dirt = b * b - 4 * a*c;//判别式法求解一元二次方程
		if (dirt > 0)//判别式大于零，有两个不相等的实数根
		{
			x1 = (-b + sqrt(dirt) )/ (2.0 * a);
			x2 = (-b - sqrt(dirt)) / (2.0 * a);
			cout << "answer1=  " << x1<< "\t answer2=  " << x2<< endl;
		}
		else if (dirt == 0)//判别式等于零，有两个相等的实数根
		{
			x1 =x2= (-b) / (2.0 * b);
			cout << "answer=  " << x1 << endl;
		}
		else cout << "no answer";
	}
	return 0;
}
int main()
{
	double m, n, s;
	cout << "请输入三个数\n";
	cin >> m >> n >> s;
	solve(m, n, s);
	system("pause");
	return 0;
}