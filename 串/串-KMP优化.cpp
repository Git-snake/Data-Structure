#include<iostream>
#define N 100010
#define M 1000010
using namespace std;
char p[N], s[M];
int ne[10];
int n, m;
int main() {

	//����ģ�崮p����  ����ģ�崮p  ����ģʽ��S����   ����ģʽ��S
	cin >> n >> p  >> m >> s ;
	//��next�Ĺ���,Ѱ�����ͬǰ��׺��
	int i = 1, j = 0; ne[1] = 0;
	while (i < n)
	{
		if (j == 0 || p[i] == p[j])
		{
			i++; j++;
			if (p[j] != p[i])ne[i] = j;
			else ne[i] = ne[j];
		}
		else j = ne[j];
	}
	// kmpƥ�����
	for (int i = 1, j = 0; i <= m; ) {
		while (j && s[i] != p[j ])j = ne[j];
		if (s[i] == p[j + 1])j++, i++;
		if (j == n)
		{
			printf("%d ", i - n + 1);
			j = ne[j]; //ƥ��ɹ� 
		}
	}
	return 0;
}
