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
	cout << "*               СС������                  *" << endl;
	cout << "*           1  �ӷ�                         *" << endl;
	cout << "*           2  ����                         *" << endl;
	cout << "*           3  �˷�                         *" << endl;
	cout << "*           4  ����                         *" << endl;
	cout << "*           5  �ж����ֵ�λ��               *" << endl;
	cout << "*           6  ����Բ���                   *" << endl;
	cout << "*           7  �ж�����                     *" << endl;
	cout << "*           8  �ɼ�ת��                     *" << endl;
	cout << "*           9 �����1��������֮���������   *" << endl;
	cout << "*          10 �����1��������֮���ż����   *" << endl;
	cout << "*          11 �����1��������֮������3�ı���*" << endl;
	cout << "*          12 �󼴱�3�����ֱ�5��������      *" << endl;
	cout << "*          13 ��ˮ�ɻ���                    *" << endl;
	cout << "*          14 �˳�                          *" << endl;
	cout << "*********************************************" << endl;
	cout << "��ѡ��[1 2 3 4 5 6 7 8 9 10 11 12 13 14]:[  ]\b\b\b";
	cin >> n;
	switch (n)
	{
	case 1:
		system("cls");
		cout << "�ӷ�" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << "�ӷ������ʮ������ʽ�ǣ�" << a + b << endl;
		cout << "�ӷ�����İ˽�����ʽ�ǣ�" << oct << a + b << endl;
		cout << "�ӷ������ʮ��������ʽ�ǣ�" << hex << a + b;
		break;

	case 2:
		system("cls");
		cout << "����" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << "���������ʮ������ʽ�ǣ�" << a - b << endl;
		cout << "��������İ˽�����ʽ�ǣ�" << oct << a - b << endl;
		cout << "���������ʮ��������ʽ�ǣ�" << hex << a - b;
		break;

	case 3:
		system("cls");
		cout << "�˷�" << endl;
		cout << "������������" << endl;
		cin >> x >> y;
		cout << " �˷������С����ʽ��" << fixed << x * y << endl;
		cout << " �˷������ָ����ʽ��" << scientific << x * y;
		break;

	case 4:
		system("cls");
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
		break;

	case 5:
		system("cls");
		cout << "�ж�����λ��" << endl << "������һ����" << endl;
		cin >> c;
		if (c < 0)
		{
			cout << "Ҫ���������Ϊ����";
			break;
		}
		else if (c >= 1000)
		{
			cout << "Ҫ���������Ϊ3λ���ڵ�������";
			break;
		}
		d = c;
		while (d > 0)
		{
			d /= 10;
			number += 1;
		}
		cout << "����Ϊ" << number << "λ����";
		if (c / 100 != 0)
			cout << "��λ��" << c / 100 << "��";
		if ((c - c / 100 * 100) / 10 != 0)
			cout << "ʮλ��" << (c - c / 100 * 100) / 10 << "��";
		cout << "��λ��" << c % 10;
		break;

	case 6:
		system("cls");
		cout << "Բ���" << endl;
		cin >> r;
		cout << "Բ�����������ǣ�" << (int)PI * r * r << endl;
		cout << "Բ����ǣ�" << fixed << PI * r * r;
		break;

	case 7:
		system("cls");
		cout << "�ж�����" << endl;
		cout << "����һ�����(-1 to end):"; 
		cin >> year;
		while (year != -1)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				cout << year << "������" << endl;
			else
				cout << year << "��ƽ��" << endl;
			cout << "����һ�����(-1 to end):";
			cin >> year;
		}
		break;

	case 8:
		system("cls");
		cout << "�ɼ�ת��" << endl << "������ɼ�(-1 to end):";
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
			cout << endl << "������ɼ�(-1 to end):" << endl;
			cin >> score;
		}
		break;
	case 9:
		system("cls");
		cout << "�����1��������֮���������" << endl << "������һ����" << endl;
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
		break;
	case 11:
		system("cls");
		cout << "�����1��������֮������3�ı���" << endl << "������һ����" << endl;
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
		cout << "�󼴱�3�����ֱ�5��������" << endl;
		cout << "����������" << endl;
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
		cout << "ˮ�ɻ���" << endl;
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
