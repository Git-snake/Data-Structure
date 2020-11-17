//cv开局
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
	//构造一个空栈S
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
	//入栈
	if (S.top - S.base >= S.stacksize) {
		//栈满，申请空间
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
	//出栈
	if (S.top == S.base) return FALSE;
	e = *--S.top;
	return TRUE;
}


SElemType Precede(SElemType a, SElemType b) {
	int i, j;
	char pre[][7] = {
		/*运算符之间的优先关系*/
	 {'>','>','<','<','<','>','>'},
	 {'>','>','<','<','<','>','>'},
	 {'>','>','>','>','<','>','>'},
	 {'>','>','>','>','<','>','>'},
	 {'<','<','<','<','<','=','0'},
	 {'>','>','>','>','0','>','>'},
	 {'<','<','<','<','<','0','='}
	};
	//寻找ab在OP中的位置
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
	//输出表中的优先级
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
	char OP[] = { '+','-','*','/','(',')','#','\0' };//定义运算符
	SqStack OPTR;		//运算符栈
	InitStack(OPTR);	Push(OPTR, '#');
	SqStack OPND;		//运算数栈
	InitStack(OPND);
	char a, b, theta, x;
	cout << "请输入表达式，以#结束:" << endl;
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
	cout << "该表达式结果为：" << GetTop(OPND) - '0' << endl;
}