#include<iostream>
#define N 10010
#define M 100010
using namespace std;
char p[N], s[M];
int ne[N];
int n, m;
int main() {

	//����ģ�崮p����  ����ģ�崮p  ����ģʽ��S����   ����ģʽ��S
	cin >> n >> p + 1 >> m >> s + 1;
	int i = 1, j = 1;//����Ϊ1��ԭ�򣺶���ʱ��P[1]��ʼ�� 
	while (i <= m && j <= n)
	{
		if (s[i] == p[j]) {
			i++, j++;
		}
		else {
			i = i - (j - 1) + 1;
			j = 1;
		}
		if (j == n + 1)
		{
			cout << i - j + 1 << " ";
			i = i - j + 2;
			j = 1;
		}

	}
}