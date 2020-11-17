#include<iostream>
#include<windows.h>
using namespace std;
void Hollow_Diamond(int n);
void gotoxy(int x, int y);
int main()
{
	int n;
	cout << "请输入行数(奇数)：";
	cin >> n;
	Hollow_Diamond(n);
}
void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Hollow_Diamond(int n)
{
	int i,j;
	for (i = 1, j = 0; i <= n / 2 + 1; i++, j++)
	{
		if (i == 1)
		{
			gotoxy(n / 2, i);
			cout << "*";
		}
		else
		{
			gotoxy(n / 2 - j, i);
			cout << "*";
			gotoxy(n / 2 + j, i);
			cout << "*";
		}
	}
	for (i = n / 2 + 2, j = 1; i < n; i++, j++)
	{
		if (i != n)
		{
			gotoxy(j, i);
			cout << "*";
			gotoxy(n - 1 - j, i);
			cout << "*";
		}
		else 
		{
			gotoxy(n / 2, n);
			cout << "*";
		}
	}
}
