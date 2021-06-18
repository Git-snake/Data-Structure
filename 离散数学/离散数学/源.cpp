#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
class Relation
{
	int p[20][20];
public:
	Relation()
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				p[i][j] = 0;
	}
	Relation(char* a)
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				p[i][j] = 0;
		for (unsigned int i = 0; i < strlen(a);)
		{
			int M, N;//分别用来临时记录关系的前分量和后分量
			if ((a[i] >= '0' && a[i] <= '9') && (a[i + 1] >= '0' && a[i + 1] <= '9'))//如果前分量是两位数
			{
				M = (a[i] - '0') * 10 + a[i + 1] - '0';
				i += 3;
				if ((a[i] >= '0' && a[i] <= '9') && (a[i + 1] >= '0' && a[i + 1] <= '9'))//如果后分量是两位数
				{
					N = (a[i] - '0') * 10 + a[i + 1] - '0'; i += 3;
				}
				else if ((a[i] >= '0' && a[i] <= '9') && (a[i + 1] <= '0' || a[i + 1] >= '9'))//如果后分量是一位数
				{
					N = a[i] - '0'; i += 2;
				}
			}
			else if ((a[i] >= '0' && a[i] <= '9') && (a[i + 1] <= '0' || a[i + 1] >= '9'))//如果前分量是一位数
			{
				M = a[i] - '0';
				i += 2;
				if ((a[i] >= '0' && a[i] <= '9') && (a[i + 1] >= '0' && a[i + 1] <= '9'))//如果后分量是两位数
				{
					N = (a[i] - '0') * 10 + a[i + 1] - '0'; i += 3;
				}
				else if ((a[i] >= '0' && a[i] <= '9') && (a[i + 1] <= '0' || a[i + 1] >= '9'))//如果后分量是一位数
				{
					N = a[i] - '0'; i += 2;
				}
			}
			p[M - 1][N - 1] = 1;//MN有关系
		}
	}
	void composite()
	{
		Relation r1;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
			{
				for (int k = 0; k < 20; k++)
					r1.p[i][j] += p[i][k] * p[k][j];
				if (r1.p[i][j] > 0)
					r1.p[i][j] = 1;
			}
		r1.output();
	}
	void inverse()
	{
		Relation r2;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				r2.p[i][j] = p[j][i];
		r2.output();
	}
	void reflexivity()
	{
		Relation r;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				r.p[i][j] = p[i][j];
		for (int i = 0; i < 20; i++)
			r.p[i][i] = 1;
		r.output();
	}
	void symmetry()
	{
		Relation s;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
			{
				s.p[i][j] = p[i][j] + p[j][i];
				if (s.p[i][j] > 0)
					s.p[i][j] = 1;
			}
		s.output();
	}
	void transmit()
	{
		Relation t;
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				t.p[i][j] = p[i][j];
		for (int k = 0; k < 20; k++)
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
				{
					t.p[i][j] += t.p[i][k] * t.p[k][j];
					if (t.p[i][j] > 0)
						t.p[i][j] = 1;
				}
		t.output();
	}
	void output()
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
				cout << p[i][j] << " ";
			cout << endl;
		}
	}
	void print()
	{
		int count1 = 0, count2 = 1;
		cout << '{';
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
				if (p[i][j] == 1) count1++;

		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 20; j++)
			{
				if (p[i][j] == 1 && count2 < count1)
				{
					cout << '<' << i + 1 << ',' << j + 1 << '>' << ',';
					count2++;
				}
				else if (p[i][j] == 1 && count2 >= count1)
				{
					cout << '<' << i + 1 << ',' << j + 1 << '>';
					count2++;
				}
			}

		cout << '}';
	}

};
int main()
{
	char s[2000];
	cin.getline(s, 2000);
	Relation A(s);
	A.output();
	A.print();
	cout << endl;

	A.inverse();

	A.composite();

	A.reflexivity();

	A.symmetry();

	A.transmit();
	return 0;
}