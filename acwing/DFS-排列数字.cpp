#include<iostream>
using namespace std;
/*
����һ������n��������1~n�ų�һ�ţ������кܶ������з�����

���ڣ����㰴���ֵ������е����з��������

�����ʽ
��һ�У�����һ������n��

�����ʽ
���ֵ�������������з�����ÿ������ռһ�С�

���ݷ�Χ
1��n��7
*/
const int N = 7;
int n;
int path[N];
bool st[N];//state
void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)printf("%d ", path[i]);
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			//��ԭ�ֳ�
			path[u] = 0;//��һ������ʡ�ԣ�path����
			st[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	dfs(0);
	return 0;
}