constexpr auto PI = 3.14;
#include<iostream>
using namespace std;
int main()
{
	int n, a, b, c, d, r, number = 0;
	float x, y;
	double t;
	cout << "***********************************" << endl;
	cout << "*          小小计算器             *" << endl;
	cout << "*          1 加法                 *" << endl;
	cout << "*          2 减法                 *" << endl;
	cout << "*          3 乘法                 *" << endl;
	cout << "*          4 除法                 *" << endl;
	cout << "*          5 判断数字的位数       *" << endl;
	cout << "*          6 计算圆面积           *" << endl;
	cout << "***********************************" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		system("cls");
		cout << "加法" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << "加法结果的十进制形式是：" << a + b << endl;
		cout << "加法结果的八进制形式是：" << oct << a + b << endl;
		cout << "加法结果的十六进制形式是：" << hex << a + b;
		break;
	case 2:
		system("cls");
		cout << "减法" << endl;
		cout << "请输入两个数" << endl;
		cin >> a >> b;
		cout << "减法结果的十进制形式是：" << a - b << endl;
		cout << "减法结果的八进制形式是：" << oct << a - b << endl;
		cout << "减法结果的十六进制形式是：" << hex << a - b;
		break;
	case 3:
		system("cls");
		cout << "乘法" << endl;
		cout << "请输入两个数" << endl;
		cin >> x >> y;
		cout << " 乘法结果的小数形式是" << fixed << x * y << endl;
		cout << " 乘法结果的指数形式是" << scientific << x * y;
		break;
	case 4:
		system("cls");
		cout << "除法" << endl;
		cout << "请输入两个数" << endl;
		cin >> x >> y;
		if (y == 0)
		{
			cout << "除数为0，无法进行除法运算" << endl;
		}
		else
		{
			cout << " 除法结果是：" << fixed << x / y << endl;
		}
		break;
	case 5:
		system("cls");
		cout << "判断数字位数" << endl << "请输入一个数" << endl;
		cin >> c;
		if (c < 0)
		{
			cout << "要求输入的数为整数";
			break;
		}
		else if (c >= 1000)
		{
			cout << "要求输入的数为3位以内的正整数";
			break;
		}
		d = c;
		while (d > 0)
		{
			d /= 10;
			number += 1;
		}
		cout << "该数为" << number << "位数，";
		if (c / 100 != 0)
			cout << "百位是" << c / 100 << "，";
		if ((c - c / 100 * 100) / 10 != 0)
			cout << "十位是" << (c - c/100 * 100) / 10 << "，";
		cout << "个位是" << c % 10;
		break;
	case 6:
		system("cls");
		cout << "圆面积" << endl;
		cin >> r;
		cout << "圆面积整数结果是：" << (int)PI * r * r << endl;
		cout << "圆面积是：" << fixed << PI * r * r;
	}
	return 0;
}
