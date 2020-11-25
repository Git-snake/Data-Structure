#include<iostream>
using namespace std;
/*
n-皇后问题是指将 n 个皇后放在 n∗n 的国际象棋棋盘上，

使得皇后不能相互攻击到，

即任意两个皇后都不能处于同一行、同一列或同一斜线上。

现在给定整数n，请你输出所有的满足条件的棋子摆法。

2^(2^n)
*/
const int N = 20;
int n;
char g[N][N];
bool row[N],col[N], dg[N], udg[N];//行 列 正对角线 反对角线
void dfs(int x,int y,int s)
{
	if (y == n)y = 0, x++;
	if (x == n)
	{
		if (s == n)
		{
			for (int i = 0; i < n; i++)puts(g[i]);
			puts("");
		}
		return;
	}
	//不放皇后
	dfs(x, y + 1, s);
	//放皇后
	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
	{
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
		dfs(x, y + 1, s + 1);
		g[x][y] = '.';
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = '.';
	dfs(0, 0, 0);
	return 0;
}
