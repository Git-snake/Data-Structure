constexpr auto PI = 3.14;
#include<iostream>
using namespace std;
int main()
{
	int n, a, b, c, d, r, number = 0, year, score;
	float x, y;
	double t;
	cout << "***********************************" << endl;
	cout << "*          СС������             *" << endl;
	cout << "*          1 �ӷ�                 *" << endl;
	cout << "*          2 ����                 *" << endl;
	cout << "*          3 �˷�                 *" << endl;
	cout << "*          4 ����                 *" << endl;
	cout << "*          5 �ж����ֵ�λ��       *" << endl;
	cout << "*          6 ����Բ���           *" << endl;
	cout << "*          7 �ж�����             *" << endl;
	cout << "*          8 �ɼ�ת��             *" << endl;
	cout << "***********************************" << endl;
	cout << "��ѡ��[1 2 3 4 5 6 7 8]:[ ]\b\b";
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
		cout << "����һ�����:";
		cin >> year;
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			cout << year << "������" << endl;
		else
			cout << year << "��ƽ��" << endl;
		break;

	case 8:
		system("cls");
		cout << "�ɼ�ת��" << endl;
		cin >> score;
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
	
	}
	return 0;
}
