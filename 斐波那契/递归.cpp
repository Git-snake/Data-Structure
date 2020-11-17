#include<iostream>
using namespace std;
long long Fibonacci(int n);
int main()
{
	int n;
	cin >> n;
	cout << Fibonacci(n);
}
long long Fibonacci(int n)
{
	//long long int A1 = 1, A2 = 1,An;
	return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
}

