#include<iostream>
using namespace std;
const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

/*
����һ��n��m�е���������������q��ѯ�ʣ�
ÿ��ѯ�ʰ����ĸ�����x1, y1, x2, y2��
��ʾһ���Ӿ�������Ͻ���������½����ꡣ

����ÿ��ѯ������Ӿ������������ĺ͡�
*/
int main()
{
	scanf("%d%d%d", &n, &m,&q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d", s[x2][y2] + s[x1-1][y1-1] - s[x1-1][y2] - s[x2][y1-1]);
	}
}