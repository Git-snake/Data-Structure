#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack,*SNode;


Status InitStack(SqStack& S){
	//构造一个空栈S
	S.base = new  SElemType[STACK_INIT_SIZE * sizeof(SElemType)];
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestoryStack(SqStack& S) {
	//销毁栈S,S不在存在
	delete S.base;
	S.top = S.base = NULL;
	S.stacksize = 0;
	return OK;
}

Status ClearStack(SqStack& S) {
	//把栈S置为空栈
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack S) {
	//判断是否为空栈
	return S.top == S.base ? OK : ERROR;
}

int StackLength(SqStack S) {
	//返回栈的长度
	return S.top-S.base;
}

Status GetTop(SqStack& S, SElemType& e) {
	//用e返回栈顶元素
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack& S, SElemType e) {
	//入栈
	if (S.top - S.base >= S.stacksize) {
		//栈满，申请空间
		SElemType * newbase= new  SElemType[(STACK_INIT_SIZE+STACKINCREMENT) * sizeof(SElemType)];
		copy(S.base, S.base + S.stacksize, newbase);
		delete[] S.base;
		S.base = newbase;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack& S, SElemType& e) {
	//出栈
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

Status StackTraverse(SqStack& S, SqStack(*visit) (void const*)) {
	//用visit遍历栈
		while (S.top != S.base)
			visit(S.top--);
		return OK;
	
}

void welcom() {
	cout << "\n\t\t  *************************************" << endl;
	cout << "\n\t\t\t    顺序栈的实现" << endl;;
	cout << "\n\t\t  1.构建顺序栈\t\t 2.销毁顺序栈" << endl;
	cout << "\t\t  3.清空顺序栈\t\t 4.入栈" << endl;
	cout << "\t\t  5.顺序栈是否为空\t 6.顺序栈的长度" << endl;
	cout << "\t\t  7.出栈\t\t 8.打印栈顶元素" << endl;
	cout << "\t\t  0.退出\n" << endl;
}
	

void title()
{
	SElemType e, in, out, top;
	SqStack S;
	int flag = 1, counter = 0;
	int choose = -1;
	while (choose != 0) {
		cout << "请选择相关操作：";
		cin >> choose;
		if (choose != 1)
			if (flag) {
				cout << "未构建顺序栈" << endl;
				continue;
			}
		switch (choose)
		{
		case 1:
			if (InitStack(S)) {
				cout << "构建成功" << endl;
				flag = 0;
				counter++;
			}
			else cout << "构建失败" << endl;
			break;
		case 2:
			DestoryStack(S);
			flag = 1;
			cout << "销毁成功" << endl;
			break;
		case 3:
			ClearStack(S);
			cout << "栈已置空" << endl;
			break;
		case 4:
			cout << "请输入需要入栈的元素(用空格隔开，输入回车结束)" << endl;
			while (1)
			{
				cin >> in;
				Push(S, in);
				if ('\n' == cin.get())
					break;
			}
			break;
		case 5:
			StackEmpty(S) ? cout << "该栈为空栈" << endl : cout << "该栈中存在数据" << endl;
			break;
		case 6:
			cout << "该栈长度为" << StackLength(S) << endl;
			break;
		case 7:
			while (Pop(S, out))
			{
				cout << out << " ";
			}
			cout << endl << "栈内已没有元素" << endl;
			break;
		case 8:
			if (GetTop(S, top))
				cout << top << endl;
			else cout << "栈内没有元素" << endl;
			break;
		}
	}
}

int main() {
	welcom();
	title();
}
