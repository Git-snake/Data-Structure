#include<iostream>
using namespace std;
typedef struct {
	int* top;
	int* base;
}SqStack;

int main()
{
	SqStack L;
	int N, out, M;
	//初始化
	L.base = new int[1e5];
	L.top = L.base;

	cout << "请输入需要转换的数和转换规则" << endl;

	cin >> N >> M;
	cout << N << "的" << M << "进制表示为：";
	while (N)
	{
		//入栈
		*L.top++ = N % M;
		N = N / M;
	}
	
	while (!(L.top == L.base))
	{
		//出栈
		cout << *--L.top;
	}
	cout << endl;

	delete L.base;
	L.top = L.base = NULL;
}