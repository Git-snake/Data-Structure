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
	//��ʼ��
	L.base = new int[1e5];
	L.top = L.base;

	cout << "��������Ҫת��������ת������" << endl;

	cin >> N >> M;
	cout << N << "��" << M << "���Ʊ�ʾΪ��";
	while (N)
	{
		//��ջ
		*L.top++ = N % M;
		N = N / M;
	}
	
	while (!(L.top == L.base))
	{
		//��ջ
		cout << *--L.top;
	}
	cout << endl;

	delete L.base;
	L.top = L.base = NULL;
}