constexpr auto PI = 3.14;
#include<iostream>
using namespace std;
int main()
{
	int n, a, b, c, r;
	float x, y;
	double t;
	cout << "**************************" << endl;
	cout << "*        СС������      *" << endl;
	cout << "*        1 �ӷ�          *" << endl;
	cout << "*        2 ����          *" << endl;
	cout << "*        3 �˷�          *" << endl;
	cout << "*        4 ����          *" << endl;
	cout << "*        5 ȡģ����      *" << endl;
	cout << "*        6 ����Բ���    *" << endl;
	cout << "**************************" << endl;
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
		cout << " ���������С����ʽ�ǣ�" << fixed << x / y << endl;
		cout << " ���������ָ����ʽ�ǣ�" << scientific << x / y;
		break;
	case 5:
		system("cls");
		cout << "ȡģ����" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << "ȡģ�����ʮ������ʽ�ǣ�" << a % b << endl;
		cout << "ȡģ����İ˽�����ʽ�ǣ�" << oct << a % b << endl;
		cout << "ȡģ�����ʮ��������ʽ�ǣ�" << hex << a % b << endl;
		break;
	case 6:
		system("cls");
		cout << "Բ���" << endl;
		cin >> r;
		cout << "Բ�����������ǣ�" << (int)PI * r * r << endl;
		cout << "Բ����ǣ�" << fixed << PI * r * r;
	}
	return 0;
}
