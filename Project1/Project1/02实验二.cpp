constexpr auto PI = 3.14;
#include<iostream>
using namespace std;
int main()
{
	int n ,a , b , c , r ;
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
		cout << a << "+" << b << "=" << a + b;
		break;
	case 2:
		system("cls");
		cout << "����" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << a << "-" << b << "=" << a - b;
		break;
	case 3:
		system("cls");
		cout << "�˷�" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << a << "*" << b << "=" << a * b;
		break;
	case 4:
		system("cls");
		cout << "����" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << a << "/" << b << "=" << a / b;
		break;
	case 5:
		system("cls");
		cout << "ȡģ����" << endl;
		cout << "������������" << endl;
		cin >> a >> b;
		cout << a << "%" << b << "=" << a % b;
	case 6:
		system("cls");
		cout << "Բ���" << endl; 
		cin >> r;
		cout << "Բ�����������ǣ�" << (int)PI * r * r << endl;
		cout << "Բ����ǣ�" << fixed << PI * r * r;
	}
	return 0;
}