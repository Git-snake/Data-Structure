#include<iostream>
#include<algorithm>
const int N = 1e6 + 10;
using namespace std;
int n,k;
int q[N];
/*
����һ������Ϊn���������У��Լ�һ������k�����ÿ���ѡ���㷨������д�С���������ĵ�k������

�����ʽ
��һ�а����������� n �� k��

�ڶ��а��� n ��������������������1~10^9��Χ�ڣ�����ʾ�������С�

�����ʽ
���һ����������ʾ���еĵ�kС����
*/
int quick_sort(int l, int r, int k)
{
    if (l == r)return q[l];
    int x = q[l + r >> 1], i = l - 1,j = r + 1;
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if (k <= sl)return quick_sort(l, j, k);
    return quick_sort(j + 1, r, k-sl);
}
int main()
{
    cin >> n>>k;
    for (size_t i = 0; i < n; i++)
        scanf_s("%d", &q[i]);
    cout << quick_sort(0, n - 1, k) << endl;
    return 0;
}