#include<iostream>
#include <iomanip>
using namespace std;
#define MAXSIZE 12500
typedef  int ElemType;
typedef int Status;
typedef struct {
	int i, j;
	ElemType e;
}Triple;

typedef struct {
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;

void T_puts(TSMatrix const A)
{
	int index = 1;
	for (size_t i = 1; i <= A.mu; i++)
	{
		for (size_t j = 1; j <= A.nu; j++)
		{
			if (i == A.data[index].i && j == A.data[index].j)
				cout << setw(3) << A.data[index++].e << " ";
			else
				cout << setw(3) << 0 << " ";
		}
		puts("");
	}
}
void TransposeSMatrix(TSMatrix M, TSMatrix& T) {
	T.mu = M.nu; T.nu = M.mu; T.tu = M.tu;
	if (T.tu)
	{
		int* num = new int[M.nu * sizeof(int)]; int* cpot = new int[M.nu * sizeof(int)];
		for (int col = 1; col <= M.nu; ++col)num[col] = 0;
		for (int t = 1; t <= M.tu; t++)++num[M.data[t].j];
		cpot[1] = 1;
		for (int col = 2; col <= M.nu; col++) cpot[col] = cpot[col - 1] + num[col - 1];
		for (int p = 1; p <= M.tu; p++)
		{
			int col = M.data[p].j;
			int q = cpot[col];
			T.data[q].i = M.data[p].j; T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e; ++cpot[col];
		}
	}
}

int main()
{
	TSMatrix M;
	cout << "请输入该稀疏矩阵的<<行数 列数 非零元素的个数>>：" << endl;
	cin >> M.mu >> M.nu >> M.tu;
	cout << "请输入非零元素所在的<<行 列 数值>>(请确保输入的数据合法)：" << endl;
	for (size_t i = 1; i <= M.tu; i++)
		cin >> M.data[i].i >> M.data[i].j >> M.data[i].e;	

	cout << "该稀疏矩阵为:" << endl;
	T_puts(M);
	//转置
	TSMatrix T;
	TransposeSMatrix(M, T);
	cout << "该稀疏矩阵转置后为：" << endl;
	T_puts(T);
}
