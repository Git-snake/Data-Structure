#include<iostream>
#define N 10010
#define M 100010
using namespace std;
char p[N], s[M];
int ne[N];
int n, m;
int main() {
	//输入模板串p长度  输入模板串p  输入模式串S长度   输入模式串S
	cin >> n >> p + 1 >> m >> s + 1;
	for (int i = 1; i <= m; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++)
		{
			if (s[i + j - 1] != p[j]) {
				flag = false;
				break;
			}
		}
		if (flag)cout << i << " ";
	}
}