#include<iostream>
using namespace std;
const int N = 1000010;
/*���ٰ�ԭ����ĸ��������е���������+C*/
int n, m;
int a[N], b[N];
/*
����һ������Ϊn���������С�

����������m��������ÿ������������������l, r, c����ʾ��������[l, r]֮���ÿ��������c��

����������������в���������С�
*/
void insert(int l, int r, int c)
{
	b[l] += c;
	b[r+1] -= c;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		insert(i, i, a[i]);
	}
	while (m--)
	{
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] += b[i - 1];
		printf("%d ", b[i]);
	}
}