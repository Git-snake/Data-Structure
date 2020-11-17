constexpr auto PI = 3.14;
#include<iostream>
#include<math.h>
using namespace std;
void close()
{
	exit(0);
}
int main()
{
	int n, a, b, c, d, r, number = 0, year, score;
	float x, y;
	cout << "*********************************************" << endl;
	cout << "*               小小计算器                  *" << endl;
	cout << "*           1  加法                         *" << endl;
	cout << "*           2  减法                         *" << endl;
	cout << "*           3  乘法                         *" << endl;
	cout << "*           4  除法                         *" << endl;
	cout << "*           5  判断数字的位数               *" << endl;
	cout << "*           6  计算圆面积                   *" << endl;
	cout << "*           7  判断闰年                     *" << endl;
	cout << "*           8  成绩转换                     *" << endl;
	cout << "*           9 计算从1到输入数之间的奇数和   *" << endl;
	cout << "*          10 计算从1到输入数之间的偶数和   *" << endl;
	cout << "*          11 输出从1到输入数之间所有3的倍数*" << endl;
	cout << "*          12 求即被3整除又被5整除的数      *" << endl;
	cout << "*          13 求水仙花数                    *" << endl;
	cout << "*          14 退出                          *" << endl;
	cout << "*********************************************" << endl;
	cout << "请选择[1 2 3 4 5 6 7 8 9 10 11 12 13 14]:[  ]\b\b\b";
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
			cout << "十位是" << (c - c / 100 * 100) / 10 << "，";
		cout << "个位是" << c % 10;
		break;

	case 6:
		system("cls");
		cout << "圆面积" << endl;
		cin >> r;
		cout << "圆面积整数结果是：" << (int)PI * r * r << endl;
		cout << "圆面积是：" << fixed << PI * r * r;
		break;

	case 7:
		system("cls");
		cout << "判断闰年" << endl;
		cout << "输入一个年份(-1 to end):"; 
		cin >> year;
		while (year != -1)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				cout << year << "是闰年" << endl;
			else
				cout << year << "是平年" << endl;
			cout << "输入一个年份(-1 to end):";
			cin >> year;
		}
		break;

	case 8:
		system("cls");
		cout << "成绩转化" << endl << "请输入成绩(-1 to end):";
		cin >> score;
		while (score != -1)
		{
			if (score < 0 || score>100)
				cout << "成绩输入错误";
			else
			{
				switch (score / 10)
				{
				case 10:
				case 9:
					cout << "优秀";
					break;
				case 8:
					cout << "良";
					break;
				case 7:
					cout << "中";
					break;
				case 6:
					cout << "及格";
					break;
				default:
					cout << "不及格";
				}
			}
			cout << endl << "请输入成绩(-1 to end):" << endl;
			cin >> score;
		}
		break;
	case 9:
		system("cls");
		cout << "计算从1到输入数之间的奇数和" << endl << "请输入一个数" << endl;
		cin >> a;
		for (b = 1,c=0; b <= a; b++)
		{
			if (b % 2 == 0)
				continue;
			c += b;
		}
		cout << c;
		break;
	case 10:
		system("cls");
		cout << "计算从1到输入数之间的偶数和" << endl << "请输入一个数" << endl;
		cin >> a;
		b = 0, c = 0;
		while (b <= a)
		{
			b += 1;
			if (b % 2 == 0)
				c += b;
		}
		cout << c;
		break;
	case 11:
		system("cls");
		cout << "输出从1到输入数之间所有3的倍数" << endl << "请输入一个数" << endl;
		cin >> a;
		b = 0, c = 0;
		do 
		{
			b += 1;
			if (b % 3 == 0)
				cout << b << endl;
		} while (b < a);
		break;
	case 12:
		system("cls");
		cout << "求即被3整除又被5整除的数" << endl;
		cout << "输入两个数" << endl;
		cin >> a >> b;
		for (c = a; c <= b; c++)
		{
			if (c % 3 == 0 || c % 5 == 0)
			{
				cout << c;
				break;
			}
		}
		break;
	case 13:
		system("cls");
		cout << "水仙花数" << endl;
		for (a = 100; a < 1000; a++)
		{
			if (a == pow(a / 100, 3) + pow((a - (a / 100) * 100) / 10, 3) + pow(a % 10, 3))
				cout << a << endl;
		}
	case 14:
		close();
		break;
	}
	return 0;
}
