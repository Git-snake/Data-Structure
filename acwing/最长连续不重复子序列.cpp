#include<iostream>
using namespace std;
const int N = 100010;
int n;
int a[N], S[N];

int main()
{
	cin >> n;
	for (size_t i = 0; i < n; i++)cin >> a[i];
	int res = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		S[a[i]]++;
		while (S[a[i]] > 1)
		{
			S[a[i]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	cout << res;
	return 0;
}