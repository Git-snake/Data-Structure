#include<iostream>
using namespace std;
const int N = 1000010;
/*���ã��������ԭ������һ�����ݵĺ�*/
int n, m;
int a[N], s[N];

/*
����һ������Ϊn���������С�

������������m��ѯ�ʣ�ÿ��ѯ������һ��l, r��

����ÿ��ѯ�ʣ����ԭ�����дӵ�l��������r�����ĺ͡�
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