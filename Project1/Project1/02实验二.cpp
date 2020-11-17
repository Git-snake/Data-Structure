constexpr auto PI = 3.14;
#include<iostream>
using namespace std;
int main()
{
	int n ,a , b , c , r ;
	double t;
	cout << "**************************" << endl;
	cout << "*        小小计算器      *" << endl;
	cout << "*        1 加法          *" << endl;
	cout << "*        2 减法          *" << endl;
	cout << "*        3 乘法          *" << endl;
	cout << "*        4 除法          *" << endl;
	cout << "*        5 取模运算      *" << endl;
	cout << "*        6 计算圆面积    *" << endl;
	cout << "**************************" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		system("cls");
		cout << "加法" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << a << "+" << b << "=" << a + b;
		break;
	case 2:
		system("cls");
		cout << "减法" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << a << "-" << b << "=" << a - b;
		break;
	case 3:
		system("cls");
		cout << "乘法" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << a << "*" << b << "=" << a * b;
		break;
	case 4:
		system("cls");
		cout << "除法" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << a << "/" << b << "=" << a / b;
		break;
	case 5:
		system("cls");
		cout << "取模运算" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << a << "%" << b << "=" << a % b;
	case 6:
		system("cls");
		cout << "圆面积" << endl; 
		cin >> r;
		cout << "圆面积整数结果是：" << (int)PI * r * r << endl;
		cout << "圆面积是：" << fixed << PI * r * r;
	}
	return 0;
}