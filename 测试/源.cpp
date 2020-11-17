#include<iostream>
int main()
{
	int a, b = 0;
	while (std::cin >> a)
		b = b + a;
	std::cout << b;
}