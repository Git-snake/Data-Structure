#include<iostream>
#include<algorithm>
const int N = 1e6 + 10;
using namespace std;
int n,k;
int q[N];
/*
给定一个长度为n的整数数列，以及一个整数k，请用快速选择算法求出数列从小到大排序后的第k个数。

输入格式
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在1~10^9范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第k小数。
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