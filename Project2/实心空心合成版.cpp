#include<iostream>
using namespace std;
void Solid_Diamond(int n);
void Hollow_Diamond(int m);
int main()
{
	int n, m;
	char str[8];
loop:cout << "1.实心菱形" << endl << "2.空心菱形" << endl;
	cout << "请输入你的选择：";
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "请输入行数：(奇数)";
		cin >> m;
		Solid_Diamond(m);
		break;
	case 2:
		cout << "请输入行数：(奇数)";
		cin >> m;
		Hollow_Diamond(m);
		break;
	}
	cout << "是否重新选择？(yes or no)";
	cin >> str;
	if (strcmp(str, "yes") == 0)
		goto loop;
	else
		return 0;
}
void Solid_Diamond(int m)
{
	int i, j, k;
	m = m / 2 + 1;//上半三角形的行数
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m - (i + 1); j++)
			cout << " ";//打印空格
		for (k = 0; k < 2 * i + 1; k++)
			cout << "*";//打印星号
		cout << endl;
	}
	for (i = 0; i < m - 1; i++)//m-1为下半三角形的行数
	{
		for (j = 0; j < i + 1; j++)
			cout << " ";//打印空格
		for (k = 0; k < 2 * (m - 1) - 2 * i - 1; k++)
			cout << "*";
		cout << endl;
	}
}
void Hollow_Diamond(int n)
{
	int i, j, k;
	n = n / 2 + 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
			cout << " ";
		cout << "*";
		if (i != 0)
		{
			for (k = 0; k < 2 * i - 1; k++)
				cout << " ";
			cout << "*";
		}
		cout << endl;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < i + 1; j++)
			cout << " ";
		cout << "*";
		if (i != n - 2)
		{
			for (k = 0; k < 2 * ((n - 1) - 1) - 1 - 2 * i; k++)
				cout << " ";
			cout << "*";
		}
		cout << endl;
	}
}
