#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	auto a = clock();
	auto b = clock();
	a = clock();
	for (int i = 0; i < 10000000; i++)
	{
		int j = 1000;
		while (j)j--;
	}
	b = clock();
	cout << b - a <<endl;
	a = clock();
	for (int i = 0; i < 10000000; i++)
	{
		int j = 1000;
		do { --j; } while (j);
	}
	b = clock();
	cout << b - a << endl;
	return 0;
}