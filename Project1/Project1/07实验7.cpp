constexpr auto PI =  3.14;
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<string>
#include<string.h>
#include<cstdlib>
using namespace std;
void execute1();void execute2();void execute3();void execute4();void execute5();
void execute6();void execute7();void execute8();void execute9();void execute10();
void execute11();void execute12();void execute13();void execute14();void execute15();
void execute16();void execute17();void execute18();void execute19();void execute20();
void execute21(); void execute22(); void execute23(); void execute24();
void close()
{
	exit(0);
}
void title()
{
	cout << "*********************************************" << endl;
	cout << "*               小小计算器                  *" << endl;
	cout << "*          01 加法                          *" << endl;
	cout << "*          02 减法                          *" << endl;
	cout << "*          03 乘法                          *" << endl;
	cout << "*          04 除法                          *" << endl;
	cout << "*          05 取模                          *" << endl;
	cout << "*          06 判断数字的位数                *" << endl;
	cout << "*          07 计算圆面积                    *" << endl;
	cout << "*          08 判断闰年                      *" << endl;
	cout << "*          09 成绩转换                      *" << endl;
	cout << "*          10 计算从1到输入数之间的奇数和   *" << endl;
	cout << "*          11 计算从1到输入数之间的偶数和   *" << endl;
	cout << "*          12 输出从1到输入数之间所有3的倍数*" << endl;
	cout << "*          13 求即被3整除又被5整除的数      *" << endl;
	cout << "*          14 求水仙花数                    *" << endl;
	cout << "*          15 求最大值                      *" << endl;
	cout << "*          16 求最大最小值                  *" << endl;
	cout << "*          17 冒泡排序                      *" << endl;
	cout << "*          18 矩阵转置                      *" << endl;
	cout << "*          19 求对角线和                    *" << endl;
	cout << "*          20 统计单词个数                  *" << endl;
	cout << "*          21 静态创建链表                  *" << endl;
	cout << "*          22 动态创建链表                  *" << endl;
	cout << "*          23 学生成绩排序                  *" << endl;
	cout << "*          24 学生成绩普涨10分              *" << endl;
	cout << "*          25 退出                          *" << endl;
	cout << "*********************************************" << endl;
}
void execute1()
{
	system("cls");
	int a, b;
	cout << "加法" << endl;
	cout << "请输入两个数" << endl;
	cin >> a >> b;
	cout << "加法结果的十进制形式是：" << a + b << endl;
	cout << "加法结果的八进制形式是：" << oct << a + b << endl;
	cout << "加法结果的十六进制形式是：" << hex << a + b;
}

void execute2()
{
	system("cls");
	int a, b;
	cout << "减法" << endl;
	cout << "请输入两个数" << endl;
	cin >> a >> b;
	cout << "减法结果的十进制形式是：" << a - b << endl;
	cout << "减法结果的八进制形式是：" << oct << a - b << endl;
	cout << "减法结果的十六进制形式是：" << hex << a - b;
}

void execute3()
{
	system("cls");
	float x, y;
	cout << "乘法" << endl;
	cout << "请输入两个数" << endl;
	cin >> x >> y;
	cout << " 乘法结果的小数形式是：" << fixed << x * y << endl;
	cout << " 乘法结果的指数形式是：" << scientific << x * y;
}

void execute4()
{
	system("cls");
	float x, y;
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
}

void execute5()
{
	system("cls");
	int a, b;
	cout << "取模运算" << endl;
	cout << "请输入两个数" << endl;
	cin >> a >> b;
	cout << "取模结果的十进制形式是：" << a % b << endl;
	cout << "取模结果的八进制形式是：" << oct << a % b << endl;
	cout << "取模结果的十六进制形式是：" << hex << a % b << endl;
}

void execute6()
{
	system("cls");
	int c, d, number = 0;
	cout << "判断数字位数" << endl << "请输入一个数" << endl;
	cin >> c;
	if (c < 0)
	{
		cout << "要求输入的数为正整数";
	}
	else if (c >= 1000)
	{
		cout << "要求输入的数为3位以内的正整数";
	}
	else
	{
		d = c;
		while (d > 0)
		{
			d /= 10;
			number += 1;
		}
		cout << "该数为" << number << "位数，";
		if (c / 100 != 0)
		{
			cout << "百位是：" << c / 100 << "，";
			if ((c - c / 100 * 100) / 10 == 0)
				cout << "十位是：0，";
		}
		if ((c - c / 100 * 100) / 10 != 0)
			cout << "十位是：" << /*(c - c / 100 * 100) / 10*/ c / 10 % 10 << "，";
		cout << "个位是：" << c % 10;
	}
}

void execute7()
{
	system("cls");
	double r;
	cout << "圆面积" << endl << "请输入圆的半径：" << endl;
	cin >> r;
	cout << "圆面积是：" << fixed << PI * r * r << endl;
	cout << "圆面积整数结果是：" << (int)(PI * r * r) << endl;
	cout << "保留两位小数" << fixed << setprecision(2) << PI * r * r;
}

void execute8()
{
	system("cls");
	int year;
	cout << "判断闰年" << endl;
	cout << "输入一个年份(-1 to end):";
	cin >> year;
	while (year != -1)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			cout << year << "是闰年" << endl;
		else
			cout << year << "是平年" << endl;
		cout << "输入一个年份(-1 to end):";
		cin >> year;
	}
}

void execute9()
{
	system("cls");
	int score;
	cout << "成绩转化" << endl << "请输入成绩(-1 to end)：";
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
		cout << endl << "请输入成绩";
		cin >> score;
	}
}

void execute10()
{
	system("cls");
	int a, b, c;
	cout << "计算从1到输入数之间的奇数和" << endl << "请输入一个数" << endl;
	cin >> a;
	for (b = 1, c = 0; b <= a; b++)
	{
		if (b % 2 == 0)
			continue;
		c += b;
	}
	cout << c;
}

void execute11()
{
	system("cls");
	int a, b, c;
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
}

void execute12()
{
	system("cls");
	int a, b, c;
	cout << "输出从1到输入数之间所有3的倍数" << endl << "请输入一个数" << endl;
	cin >> a;
	b = 0, c = 0;
	do
	{
		b += 1;
		if (b % 3 == 0)
			cout << b << endl;
	} while (b < a);
}

void execute13()
{
	system("cls");
	int a, b, c;
	cout << "求即被3整除又被5整除的数" << endl;
	cout << "输入两个数" << endl;
	cin >> a >> b;
	for (c = a; c <= b; c++)
	{
		if (c % 3 == 0 && c % 5 == 0)
		{
			cout << c;
			break;
		}
	}
}

void execute14()
{
	system("cls");
	int a;
	cout << "水仙花数" << endl;
	for (a = 100; a < 1000; a++)
	{
		if (a == pow(a / 100, 3) + pow(a / 10 % 10, 3) + pow(a % 10, 3))
			cout << a << endl;
	}
}
void execute15()
{
	system("cls");
	int a, b;
	cout << "求最大值" << endl << "请输入两个数：";
	cin >> a >> b;
	if (a > b)
		cout << "最大值为：" << a;
	else if (a < b)
		cout << "最大值为：" << b;
	else
		cout << "这两个数一样大";
}
void execute16()
{
	system("cls");
	int a, b;
	cout << "求最大最小值" << endl << "请输入两个数：";
	cin >> a >> b;
	if (a > b);
	else if (a < b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	else
		cout << "这两个数一样大";
	cout << "最大值为：" << a << "最小值为：" << b;
}

void execute17()
{
	system("cls");
	int a[10];
	cout << "请输入10个数：";
	for (size_t i = 0; i < 10; i++)
		cin >> a[i];
	for (size_t i = 0; i < 9; i++)
		for (size_t j = i + 1; j < 10; j++)
		{
			if (a[i] < a[j])
			{
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	cout << "按从大到小排序：";
	for (size_t i = 0; i < 10; i++)
		cout << a[i] << " ";
}
void execute18()
{
	system("cls");
	int a[3][4];
	cout << "请输入一个3X4的整数矩阵：" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "转置后的矩阵为：" << endl;
	for (size_t j = 0; j < 4; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			cout << a[i][j] << " ";
			if (i == 2)
				cout << endl;
		}
	}
}

void execute19()
{
	system("cls");
	int a[3][3], sum = 0;
	cout << "请输入一个3X3的矩阵：" << endl;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			cin >> a[i][j];
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
		{
			if ((i == j))
			{
				sum += a[i][j];
			}
		}
	cout << "主对角线之和为：";
	cout << sum;
}

void execute20()
{
	system("cls");
	int count = 0;
	long len;
	string str, t;
	cout << "输入一行字符(单词之间用空格分隔开):" << endl;
	getline(cin, t);
	getline(cin, str);
	len = (int)str.length();
	for (size_t i = 0; i < len; i++)
		if (str[i] == ' ')
			count++;
	cout << "单词数为：" << count + 1;
}

void execute21()
{
	typedef struct stu {
		int data;
		struct stu* nextPtr;
	}*stuPtr;
	system("cls");
	stuPtr head, p, q;
	int a[4] = { 1,2,3,4 };
	q = (stuPtr)malloc(sizeof(stu));
	q->nextPtr = NULL;
	head = q;
	q = head;
	for (size_t i = 0; i < 4; i++)
	{
		p = (stuPtr)malloc(sizeof(stu));
		if (p == NULL)
			cout << "申请内存空间失败。" << endl;
		p->data = a[i];
		p->nextPtr = NULL;
		q->nextPtr = p;
		q = p;
	}
	q = head->nextPtr;
	while (q != NULL)
	{
		cout << q->data << " ";
		q = q->nextPtr;
	}
	free(q);
	cout << endl << "   运行结束开始销毁链表" << endl << "    ↖(^ ω^)↗        ↖(^ ω^)↗" << endl;
	while (head)
	{
		p = head;
		head = head->nextPtr;
		free(p);
	}
	cout << endl << "   >_<       链表已销毁      >_<" << endl;
}

void execute22()
{
	typedef struct node {
		int data;
		struct node* nextPtr;
	} *nodePtr;
	system("cls");
	int count;
	nodePtr head, p;
	p = (nodePtr)malloc(sizeof(node));
	if (p == NULL)
		cout << "申请内存空间失败。" << endl;
	p->nextPtr = NULL;
	head = p;
	p = head;
	cout << "请输入链表数据，输入负数为截至标志：" << endl;
	while (cin >> count && count > 0)
	{
		nodePtr q = (nodePtr)malloc(sizeof(node));
		q->data = count;
		q->nextPtr = NULL;
		p->nextPtr = q;
		p = q;
	}
	cout << "输出链表：" << endl;
	p = head->nextPtr;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->nextPtr;
	}
	cout << endl << "运行结束开始销毁链表" << endl << "    ↖(^ ω^)↗        ↖(^ ω^)↗" << endl;
	while (head)
	{
		p = head;
		head = head->nextPtr;
		free(p);
	}
	cout << endl << "   >_<       链表已销毁      >_<" << endl;
}

void execute23()
{
	system("cls");
	struct student
	{
		char sno[11];
		char sname[11];
		int grand;
	}stu[10];
	int sum = 0;
	double avg = 0;
	for (size_t i = 0; i < 10; i++)
	{
		cin >> stu[i].sno;
		cin >> stu[i].sname;
		cin >> stu[i].grand;
		sum += stu[i].grand;
	}
	for (size_t i = 0; i < 9; i++)
	{
		for (size_t j = i + 1; j < 10; j++)
		{
			if (stu[i].grand > stu[j].grand)
			{
				struct student temp;
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	for (size_t i = 0; i < 10; i++)
		cout << "按成绩小到大排序" << endl << stu[i].sno << setw(9) << setfill(' ') << stu[i].sname << setw(9) << setfill(' ') << stu[i].grand << endl;
	avg = sum / 10.0;
	cout << "总成绩为：" << sum << endl << "平均成绩为:" << avg;
}

void execute24()
{

}

void welcom()
{
	int a, n;
	cout << "请选择[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25]:[  ]\b\b\b";
	cin >> n;
	do {
		switch (n)
		{
		case 1:
			execute1();
			break;
		case 2:
			execute2();
			break;
		case 3:
			execute3();
			break;
		case 4:
			execute4();
			break;
		case 5:
			execute5();
			break;
		case 6:
			execute6();
			break;
		case 7:
			execute7();
			break;
		case 8:
			execute8();
			break;
		case 9:
			execute9();
			break;
		case 10:
			execute10();
			break;
		case 11:
			execute11();
			break;
		case 12:
			execute12();
			break;
		case 13:
			execute13();
			break;
		case 14:
			execute14();
			break;
		case 15:
			execute15();
			break;
		case 16:
			execute16();
			break;
		case 17:
			execute17();
			break;
		case 18:
			execute18();
			break;
		case 19:
			execute19();
			break;
		case 20:
			execute20();
			break;
		case 21:
			execute21();
			break;
		case 22:
			execute22();
			break;
		case 23:
			execute23();
			break;
		case 24:
			execute24();
			break;
		case 25:
			close();
			break;
		}
		char str[8];
		cout << endl << endl << "是否继续输入？(yes or no)" << endl;
		cin >> str;
		if (strcmp(str, "yes") == 0)
			a = 1;
		else
			a = 0;
	} while (a);
}
int main()
{
	title();
	welcom();
	char str[8];
	cout << endl << "是否返回主菜单？(yes or no)" << endl;
	cin >> str;
	if (strcmp(str, "yes") == 0)
	{
		system("cls");
		main();
	}
	else
		close();
}