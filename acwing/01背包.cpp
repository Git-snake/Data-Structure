#include<iostream>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];
int F[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];
    //����
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (j >= v[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            else
                f[i][j] = f[i - 1][j];
    //ת��Ϊһά����
    for (int i = 1; i <= n; i++)
        for (int j = m; j > 0; j--)
            if (j >= v[i])
                F[j] = max(F[j], F[j - v[i]] + w[i]);

    cout << f[n][m] << endl;
    cout << F[m];
    return 0;
}