#include<iostream>
#include<cstdlib>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1
const int  MAXQSIZE = 10;

typedef int QElemType;
typedef int Status;

typedef struct {
	QElemType* base;//空间
	int front;//头指针
	int rear;//尾指针
}SqQueue;

Status InitQueue(SqQueue& Q){	
	//构建空的队列
	Q.base = new QElemType[MAXQSIZE*sizeof(QElemType)];//为rear预留一个位置
	Q.front = Q.rear = 0;
	return OK;
}

Status DestoryQueue(SqQueue& Q) {
	//销毁队列
	delete Q.base;
	Q.front = Q.rear = NULL;
	return OK;
}

Status ClearQueue(SqQueue& Q) {
	//将队列清空
	Q.front = Q.rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q) {
	//若为空队列返回OK，否则返回ERROR
	return Q.front == Q.rear ? OK : ERROR;
}

Status QueueLength(SqQueue Q) {
	//返回队列长度
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue Q, QElemType& e) {
	//用e返回队头元素
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	return OK;
}

Status EnQueue(SqQueue& Q, QElemType e) {
	//插入新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;//队列满
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e) {
	//删除并返回队头元素
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

int main()
{
	cout << endl << "\t\t\t循环队列相关操作" << endl << endl;
	cout << "1.初始化队列  \t\t2.销毁队列    \t\t3.清空队列" << endl;
	cout << "4.队列判空    \t\t5.求队列长度  \t\t6.获取队头元素" << endl;
	cout << "7.插入元素    \t\t8.删除队头元素\t\t9.输出所有元素" << endl;
	cout << "0.退出" << endl;

	SqQueue Q;
	int choose = -1;
	int in, out, head, de;
	bool flag = false;
	while (choose)
	{
		cout << "请选择相关操作：";
		cin >> choose;
		if (choose != 1)
			if (!flag)
			{
				cout << "未构建队列" << endl;
				continue;
			}
		switch (choose) {
		case 1:
			if (InitQueue(Q)) {
				cout << "初始化成功" << endl;
				flag = true;
			}
			else cout << "初始化失败" << endl;
			break;
		case 2:
			DestoryQueue(Q);
			cout << "队列已销毁" << endl;
			flag = false;
			break;
		case 3:
			ClearQueue(Q);
			cout << "队列已清空" << endl;
			break;
		case 4:
			QueueEmpty(Q) ? cout << "该队列为空队" << endl : cout << "该队列中存在数据" << endl;
			break;
		case 5:
			cout << "该队列的长度为：" << QueueLength(Q) << endl;
			break;
		case 6:
			if (GetHead(Q, head))cout << "头元素为：" << head << endl;
			else cout << "该队列为空队" << endl;
			break;
		case 7:
			cout << "请输入需要入队的元素(元素间用空格隔开，回车为结束标志)注意队列最大存储为"<<MAXQSIZE-1 << endl;
			while (1)
			{
				cin >> in;
				if (!EnQueue(Q, in))  cout << "队列已满"<<endl;
				if ('\n' == cin.get())
					break;
			}
			break;
		case 8:
			if (DeQueue(Q, de))cout << "已删除当前队首元素" << de << endl;
			else cout << "该队列中没有元素" << endl;
			break;
		case 9:
			if (QueueEmpty(Q)) cout << "该队列中没有元素";
			else
				while (Q.front != Q.rear) {
					DeQueue(Q, de);
					cout << de << " ";
				}
			cout << endl;
			break;
		}
	}
	
}