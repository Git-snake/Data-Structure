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
	cout << "*               СС������                  *" << endl;
	cout << "*          01 �ӷ�                          *" << endl;
	cout << "*          02 ����                          *" << endl;
	cout << "*          03 �˷�                          *" << endl;
	cout << "*          04 ����                          *" << endl;
	cout << "*          05 ȡģ                          *" << endl;
	cout << "*          06 �ж����ֵ�λ��                *" << endl;
	cout << "*          07 ����Բ���                    *" << endl;
	cout << "*          08 �ж�����                      *" << endl;
	cout << "*          09 �ɼ�ת��                      *" << endl;
	cout << "*          10 �����1��������֮���������   *" << endl;
	cout << "*          11 �����1��������֮���ż����   *" << endl;
	cout << "*          12 �����1��������֮������3�ı���*" << endl;
	cout << "*          13 �󼴱�3�����ֱ�5��������      *" << endl;
	cout << "*          14 ��ˮ�ɻ���                    *" << endl;
	cout << "*          15 �����ֵ                      *" << endl;
	cout << "*          16 �������Сֵ                  *" << endl;
	cout << "*          17 ð������                      *" << endl;
	cout << "*          18 ����ת��                      *" << endl;
	cout << "*          19 ��Խ��ߺ�                    *" << endl;
	cout << "*          20 ͳ�Ƶ��ʸ���                  *" << endl;
	cout << "*          21 ��̬��������                  *" << endl;
	cout << "*          22 ��̬��������                  *" << endl;
	cout << "*          23 ѧ���ɼ�����                  *" << endl;
	cout << "*          24 ѧ���ɼ�����10��              *" << endl;
	cout << "*          25 �˳�                          *" << endl;
	cout << "*********************************************" << endl;
}
void execute1()
{
	system("cls");
	int a, b;
	cout << "�ӷ�" << endl;
	cout << "������������" << endl;
	cin >> a >> b;
	cout << "�ӷ������ʮ������ʽ�ǣ�" << a + b << endl;
	cout << "�ӷ�����İ˽�����ʽ�ǣ�" << oct << a + b << endl;
	cout << "�ӷ������ʮ��������ʽ�ǣ�" << hex << a + b;
}

void execute2()
{
	system("cls");
	int a, b;
	cout << "����" << endl;
	cout << "������������" << endl;
	cin >> a >> b;
	cout << "���������ʮ������ʽ�ǣ�" << a - b << endl;
	cout << "��������İ˽�����ʽ�ǣ�" << oct << a - b << endl;
	cout << "���������ʮ��������ʽ�ǣ�" << hex << a - b;
}

void execute3()
{
	system("cls");
	float x, y;
	cout << "�˷�" << endl;
	cout << "������������" << endl;
	cin >> x >> y;
	cout << " �˷������С����ʽ�ǣ�" << fixed << x * y << endl;
	cout << " �˷������ָ����ʽ�ǣ�" << scientific << x * y;
}

void execute4()
{
	system("cls");
	float x, y;
	cout << "����" << endl;
	cout << "������������" << endl;
	cin >> x >> y;
	if (y == 0)
	{
		cout << "����Ϊ0���޷����г�������" << endl;
	}
	else
	{
		cout << " ��������ǣ�" << fixed << x / y << endl;
	}
}

void execute5()
{
	system("cls");
	int a, b;
	cout << "ȡģ����" << endl;
	cout << "������������" << endl;
	cin >> a >> b;
	cout << "ȡģ�����ʮ������ʽ�ǣ�" << a % b << endl;
	cout << "ȡģ����İ˽�����ʽ�ǣ�" << oct << a % b << endl;
	cout << "ȡģ�����ʮ��������ʽ�ǣ�" << hex << a % b << endl;
}

void execute6()
{
	system("cls");
	int c, d, number = 0;
	cout << "�ж�����λ��" << endl << "������һ����" << endl;
	cin >> c;
	if (c < 0)
	{
		cout << "Ҫ���������Ϊ������";
	}
	else if (c >= 1000)
	{
		cout << "Ҫ���������Ϊ3λ���ڵ�������";
	}
	else
	{
		d = c;
		while (d > 0)
		{
			d /= 10;
			number += 1;
		}
		cout << "����Ϊ" << number << "λ����";
		if (c / 100 != 0)
		{
			cout << "��λ�ǣ�" << c / 100 << "��";
			if ((c - c / 100 * 100) / 10 == 0)
				cout << "ʮλ�ǣ�0��";
		}
		if ((c - c / 100 * 100) / 10 != 0)
			cout << "ʮλ�ǣ�" << /*(c - c / 100 * 100) / 10*/ c / 10 % 10 << "��";
		cout << "��λ�ǣ�" << c % 10;
	}
}

void execute7()
{
	system("cls");
	double r;
	cout << "Բ���" << endl << "������Բ�İ뾶��" << endl;
	cin >> r;
	cout << "Բ����ǣ�" << fixed << PI * r * r << endl;
	cout << "Բ�����������ǣ�" << (int)(PI * r * r) << endl;
	cout << "������λС��" << fixed << setprecision(2) << PI * r * r;
}

void execute8()
{
	system("cls");
	int year;
	cout << "�ж�����" << endl;
	cout << "����һ�����(-1 to end):";
	cin >> year;
	while (year != -1)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			cout << year << "������" << endl;
		else
			cout << year << "��ƽ��" << endl;
		cout << "����һ�����(-1 to end):";
		cin >> year;
	}
}

void execute9()
{
	system("cls");
	int score;
	cout << "�ɼ�ת��" << endl << "������ɼ�(-1 to end)��";
	cin >> score;
	while (score != -1)
	{
		if (score < 0 || score>100)
			cout << "�ɼ��������";
		else
		{
			switch (score / 10)
			{
			case 10:
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "��";
				break;
			case 7:
				cout << "��";
				break;
			case 6:
				cout << "����";
				break;
			default:
				cout << "������";
			}
		}
		cout << endl << "������ɼ�";
		cin >> score;
	}
}

void execute10()
{
	system("cls");
	int a, b, c;
	cout << "�����1��������֮���������" << endl << "������һ����" << endl;
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
	cout << "�����1��������֮���ż����" << endl << "������һ����" << endl;
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
	cout << "�����1��������֮������3�ı���" << endl << "������һ����" << endl;
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
	cout << "�󼴱�3�����ֱ�5��������" << endl;
	cout << "����������" << endl;
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
	cout << "ˮ�ɻ���" << endl;
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
	cout << "�����ֵ" << endl << "��������������";
	cin >> a >> b;
	if (a > b)
		cout << "���ֵΪ��" << a;
	else if (a < b)
		cout << "���ֵΪ��" << b;
	else
		cout << "��������һ����";
}
void execute16()
{
	system("cls");
	int a, b;
	cout << "�������Сֵ" << endl << "��������������";
	cin >> a >> b;
	if (a > b);
	else if (a < b)
	{
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	else
		cout << "��������һ����";
	cout << "���ֵΪ��" << a << "��СֵΪ��" << b;
}

void execute17()
{
	system("cls");
	int a[10];
	cout << "������10������";
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
	cout << "���Ӵ�С����";
	for (size_t i = 0; i < 10; i++)
		cout << a[i] << " ";
}
void execute18()
{
	system("cls");
	int a[3][4];
	cout << "������һ��3X4����������" << endl;
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "ת�ú�ľ���Ϊ��" << endl;
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
	cout << "������һ��3X3�ľ���" << endl;
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
	cout << "���Խ���֮��Ϊ��";
	cout << sum;
}

void execute20()
{
	system("cls");
	int count = 0;
	long len;
	string str, t;
	cout << "����һ���ַ�(����֮���ÿո�ָ���):" << endl;
	getline(cin, t);
	getline(cin, str);
	len = (int)str.length();
	for (size_t i = 0; i < len; i++)
		if (str[i] == ' ')
			count++;
	cout << "������Ϊ��" << count + 1;
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
			cout << "�����ڴ�ռ�ʧ�ܡ�" << endl;
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
	cout << endl << "   ���н�����ʼ��������" << endl << "    �I(^ ��^)�J        �I(^ ��^)�J" << endl;
	while (head)
	{
		p = head;
		head = head->nextPtr;
		free(p);
	}
	cout << endl << "   >_<       ����������      >_<" << endl;
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
		cout << "�����ڴ�ռ�ʧ�ܡ�" << endl;
	p->nextPtr = NULL;
	head = p;
	p = head;
	cout << "�������������ݣ����븺��Ϊ������־��" << endl;
	while (cin >> count && count > 0)
	{
		nodePtr q = (nodePtr)malloc(sizeof(node));
		q->data = count;
		q->nextPtr = NULL;
		p->nextPtr = q;
		p = q;
	}
	cout << "�������" << endl;
	p = head->nextPtr;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->nextPtr;
	}
	cout << endl << "���н�����ʼ��������" << endl << "    �I(^ ��^)�J        �I(^ ��^)�J" << endl;
	while (head)
	{
		p = head;
		head = head->nextPtr;
		free(p);
	}
	cout << endl << "   >_<       ����������      >_<" << endl;
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
		cout << "���ɼ�С��������" << endl << stu[i].sno << setw(9) << setfill(' ') << stu[i].sname << setw(9) << setfill(' ') << stu[i].grand << endl;
	avg = sum / 10.0;
	cout << "�ܳɼ�Ϊ��" << sum << endl << "ƽ���ɼ�Ϊ:" << avg;
}

void execute24()
{

}

void welcom()
{
	int a, n;
	cout << "��ѡ��[1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25]:[  ]\b\b\b";
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
		cout << endl << endl << "�Ƿ�������룿(yes or no)" << endl;
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
	cout << endl << "�Ƿ񷵻����˵���(yes or no)" << endl;
	cin >> str;
	if (strcmp(str, "yes") == 0)
	{
		system("cls");
		main();
	}
	else
		close();
}