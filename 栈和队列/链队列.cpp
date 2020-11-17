#include<iostream>
#include<cstdlib>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int QElemType;
typedef int Status;

typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;		//队头指针
	QueuePtr rear;		//队尾指针
}LinkQueue;

Status InitQueue(LinkQueue& Q){
	//构造一个空队列
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status DestoryQueue(LinkQueue& Q){
	//销毁队列
	while (Q.front)
	{
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue& Q) {
	//将队列清空
	Q.front = Q.rear;
	return OK;
}

Status QueueEmpty(LinkQueue Q) {
	//若为空队列返回OK，否则返回ERROR
	return Q.front == Q.rear ? OK : ERROR;
}

int QueueLength(LinkQueue Q) {
	//返回队列长度
	int length = 0;
	QNode* p = Q.front->next;
	while (p)
	{
		p = p->next;
		length++;
	}
	return length;
}

Status GetHead(LinkQueue Q, QElemType& e) {
	//用e返回队头元素
	if (Q.front == Q.rear)return ERROR;
	e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue& Q, QElemType e) {
	//入队
	QNode* p=new QNode;
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue& Q, QElemType& e) {
	//删除Q的头元素用e返回其值
	if (Q.front == Q.rear)return ERROR;
	QNode* p = new QNode;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	delete p;
	return OK;
}


int main()
{
	cout << endl << "\t\t\t链队列相关操作" << endl << endl;
	cout << "1.初始化队列  \t\t2.销毁队列    \t\t3.清空队列"<<endl;
	cout << "4.队列判空    \t\t5.求队列长度  \t\t6.获取队头元素" << endl;
	cout << "7.入队        \t\t8.删除一个元素\t\t9.输出所有元素" << endl;
	cout << "0.退出" << endl;


	int choose = -1;
	int in, out, head, de;
	bool flag = false;
	LinkQueue Q;
	while (choose)
	{
		cout << "请选择相关操作：";
		cin >> choose;
		if(choose!=1)
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
				cout << "请输入需要入队的元素(元素间用空格隔开，回车为结束标志)" << endl;
				while (1)
				{
					cin >> in;
					EnQueue(Q, in);
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
						cout << de<<" ";
					}
				cout << endl;
				break;
		}
	}
}