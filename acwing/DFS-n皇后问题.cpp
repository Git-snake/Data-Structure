#include<iostream>
using namespace std;
/*
n-皇后问题是指将 n 个皇后放在 n∗n 的国际象棋棋盘上，

使得皇后不能相互攻击到，

即任意两个皇后都不能处于同一行、同一列或同一斜线上。

现在给定整数n，请你输出所有的满足条件的棋子摆法。


n*n!
*/
const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];//行 正对角线 反对角线
void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)puts(g[i]);
		puts("");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!col[i] && !dg[u + i] && !udg[n - u + i])
		{
			g[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u][i] = '.';
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0);
	return 0;
}
