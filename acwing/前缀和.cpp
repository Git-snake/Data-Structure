#include<iostream>
using namespace std;
const int N = 1000010;
/*作用：快速求出原数组中一段数据的和*/
int n, m;
int a[N], s[N];

/*
输入一个长度为n的整数序列。

接下来再输入m个询问，每个询问输入一对l, r。

对于每个询问，输出原序列中从第l个数到第r个数的和。
*/
int main() {
	scanf_s("%d%d", &n, &m);
	for (size_t i = 1; i <= n; i++)
	{
		scanf_s("%d",& a[i]);
		s[i] = s[i - 1] + a[i];
	}
	while (m--)
	{
		int l, r;
		scanf_s("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}