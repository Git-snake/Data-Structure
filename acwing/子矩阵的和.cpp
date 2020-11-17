#include<iostream>
using namespace std;
const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

/*
输入一个n行m列的整数矩阵，再输入q个询问，
每个询问包含四个整数x1, y1, x2, y2，
表示一个子矩阵的左上角坐标和右下角坐标。

对于每个询问输出子矩阵中所有数的和。
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