#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
/*
    ������һ������Ϊn���������С�
    ����ʹ�ÿ��������������а��մ�С�����������
    �����ź�������а�˳�������

    �����ʽ
    ���빲���У���һ�а�������n��
    �ڶ��а���n������(������������1~10^6��Χ��)����ʾ�������С�

    �����ʽ
    ��������У�����n����������ʾ�ź�������С�
*/
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);

}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}