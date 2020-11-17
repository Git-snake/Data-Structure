#include<iostream>
#define N 100010
#define M 1000010
using namespace std;
char p[N], s[M];
int ne[N];
int n, m;
int main() {

	//输入模板串p长度  输入模板串p  输入模式串S长度   输入模式串S
	cin >> n >> p + 1 >> m >> s + 1;
	//求next的过程,寻找最长相同前后缀
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && p[i] != p[j + 1])j = ne[j]; //回退
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}
	// kmp匹配过程
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && s[i] != p[j + 1])j = ne[j];
		if (s[i] == p[j + 1])j++;
		if (j == n)
		{
			printf("%d ", i - n + 1);
			j = ne[j]; //匹配成功 
		}
	}
	return 0;
}