#include<iostream>
using namespace std;
void Solid_Diamond(int n);
int main()
{
	int n;
	cin >> n;
	Solid_Diamond(n);
}
void Solid_Diamond(int n)
{
	int i, j, k;
	n = n / 2 + 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - (i + 1); j++)
			cout << " ";
		for (k = 0; k < 2 * i + 1; k++)
			cout << "*";
		cout << endl;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < i + 1; j++)
			cout << " ";
		for (k = 0; k < 2 * (n - 1) - 2 * i - 1; k++)
			cout << "*";
		cout << endl;
	}
}