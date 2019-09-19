#include<iostream>
using namespace std;
#include<math.h>
int main()
{
	double a, b, c, S, m, n;
	cout << "请输入三角形三条边大小：" << endl;
	cin >> a >> b >> c;
	if ((a + b > c) && (b + c > a) && (a + c > b))
	{
		m = a + b + c; n = m / 2.0;
		S = sqrt(n*(n - a)*(n - b)*(n - c));
		cout << "S=" << S << endl;
	}
	else cout << "error";
	system("pause");
	return 0;
}