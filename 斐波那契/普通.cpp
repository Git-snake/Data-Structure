#include<iostream>
using namespace std;
void Fibonacci(int n);
int main()
{
	int n;
	cin >> n;
	Fibonacci(n);
}
void Fibonacci(int n)
{
	long long int a1 = 1, a2 = 1, a3 = 0;
	if (n == 1 || n == 2)
	{
		cout << a1;
	}
	else
	{
		for (int i = 2; i < n; i++)
		{
			a3 = a2 + a1;
			a1 = a2;
			a2 = a3;
		}
		cout << a3;
	}
}