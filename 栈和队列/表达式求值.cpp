//cv����
#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
typedef char SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack, * SNode;

Status InitStack(SqStack& S) {
	//����һ����ջS
	S.base = new  SElemType[STACK_INIT_SIZE * sizeof(SElemType)];
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return TRUE;
}

Status GetTop(SqStack& S) {
	if (S.top == S.base) return FALSE;
	return *(S.top - 1);
}

Status Push(SqStack& S, SElemType e) {
	//��ջ
	if (S.top - S.base >= S.stacksize) {
		//ջ��������ռ�
		SElemType* newbase = new  SElemType[(STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType)];
		copy(S.base, S.base + S.stacksize, newbase);
		delete[] S.base;
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return TRUE;
}

Status Pop(SqStack& S, SElemType& e) {
	//��ջ
	if (S.top == S.base) return FALSE;
	e = *--S.top;
	return TRUE;
}


SElemType Precede(SElemType a, SElemType b) {
	int i, j;
	char pre[][7] = {
		/*�����֮������ȹ�ϵ*/
	 {'>','>','<','<','<','>','>'},
	 {'>','>','<','<','<','>','>'},
	 {'>','>','>','>','<','>','>'},
	 {'>','>','>','>','<','>','>'},
	 {'<','<','<','<','<','=','0'},
	 {'>','>','>','>','0','>','>'},
	 {'<','<','<','<','<','0','='}
	};
	//Ѱ��ab��OP�е�λ��
	switch (a) {
	case '+': i = 0; break;
	case '-': i = 1; break;
	case '*': i = 2; break;
	case '/': i = 3; break;
	case '(': i = 4; break;
	case ')': i = 5; break;
	case '#': i = 6; break;
	}
	switch (b) {
	case '+': j = 0; break;
	case '-': j = 1; break;
	case '*': j = 2; break;
	case '/': j = 3; break;
	case '(': j = 4; break;
	case ')': j = 5; break;
	case '#': j = 6; break;
	}
	//������е����ȼ�
	return pre[i][j];
}


Status In(SElemType c, SElemType op[]) {
	char* p;
	p = op;
	while (*p != '\0') {
		if (c == *p)
			return TRUE;
		p++;
	}
	return FALSE;
}

SElemType Operate(SElemType a, SElemType theta, SElemType b) {
	char c;
	a = a - '0';
	b = b - '0';
	if (theta == '+') c = a + b + '0';
	if (theta == '-') c = a - b + '0';
	if (theta == '*') c = a * b + '0';
	if (theta == '/') c = a / b + '0';
	return c;
}


int main()
{
	char OP[] = { '+','-','*','/','(',')','#','\0' };//���������
	SqStack OPTR;		//�����ջ
	InitStack(OPTR);	Push(OPTR, '#');
	SqStack OPND;		//������ջ
	InitStack(OPND);
	char a, b, theta, x;
	cout << "��������ʽ����#����:" << endl;
	char c = getchar();
	while (c != '#' || GetTop(OPTR) != '#')
	{
		if (!In(c, OP)) { Push(OPND, c); c = getchar(); }
		else
			switch (Precede(GetTop(OPTR), c)){
			case '<':
				Push(OPTR, c);
				c = getchar();
				break;
			case '=':
				Pop(OPTR, x);
				c = getchar();
				break;
			case '>':
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operate(a, theta, b));
				break;
		}
		//return GetTop(OPND) - '0';	
	}
	cout << "�ñ��ʽ���Ϊ��" << GetTop(OPND) - '0' << endl;
}