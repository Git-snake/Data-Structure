#include<iostream>
#define N 100010
#define M 1000010
using namespace std;
char p[N], s[M];
int ne[N];
int n, m;
int main() {

	//����ģ�崮p����  ����ģ�崮p  ����ģʽ��S����   ����ģʽ��S
	cin >> n >> p + 1 >> m >> s + 1;
	//��next�Ĺ���,Ѱ�����ͬǰ��׺
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && p[i] != p[j + 1])j = ne[j]; //����
		if (p[i] == p[j + 1])j++;
		ne[i] = j;
	}
	// kmpƥ�����
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && s[i] != p[j + 1])j = ne[j];
		if (s[i] == p[j + 1])j++;
		if (j == n)
		{
			printf("%d ", i - n + 1);
			j = ne[j]; //ƥ��ɹ� 
		}
	}
	return 0;
}