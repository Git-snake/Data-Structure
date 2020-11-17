#include<iostream>
using namespace std;
int execute(int x, int y);
int main()
{
	int m, n;
	cin >> m >> n;
	if (m < n)
	{
		m = m ^ n;
		n = m ^ n;
		m = m ^ n;
	}
	cout << execute(m, n);
}
int execute(int x, int y)
{
	if (x <= 0 || y <= 0)
		return 0;
	if (x % y == 0)
		return y;
	else
		execute(y, x % y);
}