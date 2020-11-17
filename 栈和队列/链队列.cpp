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
	QueuePtr front;		//��ͷָ��
	QueuePtr rear;		//��βָ��
}LinkQueue;

Status InitQueue(LinkQueue& Q){
	//����һ���ն���
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}

Status DestoryQueue(LinkQueue& Q){
	//���ٶ���
	while (Q.front)
	{
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue& Q) {
	//���������
	Q.front = Q.rear;
	return OK;
}

Status QueueEmpty(LinkQueue Q) {
	//��Ϊ�ն��з���OK�����򷵻�ERROR
	return Q.front == Q.rear ? OK : ERROR;
}

int QueueLength(LinkQueue Q) {
	//���ض��г���
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
	//��e���ض�ͷԪ��
	if (Q.front == Q.rear)return ERROR;
	e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue& Q, QElemType e) {
	//���
	QNode* p=new QNode;
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue& Q, QElemType& e) {
	//ɾ��Q��ͷԪ����e������ֵ
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
	cout << endl << "\t\t\t��������ز���" << endl << endl;
	cout << "1.��ʼ������  \t\t2.���ٶ���    \t\t3.��ն���"<<endl;
	cout << "4.�����п�    \t\t5.����г���  \t\t6.��ȡ��ͷԪ��" << endl;
	cout << "7.���        \t\t8.ɾ��һ��Ԫ��\t\t9.�������Ԫ��" << endl;
	cout << "0.�˳�" << endl;


	int choose = -1;
	int in, out, head, de;
	bool flag = false;
	LinkQueue Q;
	while (choose)
	{
		cout << "��ѡ����ز�����";
		cin >> choose;
		if(choose!=1)
			if (!flag)
			{
				cout << "δ��������" << endl;
				continue;
			}
		switch (choose) {
			case 1:
				if (InitQueue(Q)) {
					cout << "��ʼ���ɹ�" << endl;
					flag = true;
				}
				else cout << "��ʼ��ʧ��" << endl;
				break;
			case 2:
				DestoryQueue(Q);
				cout << "����������" << endl;
				flag = false;
				break;
			case 3:
				ClearQueue(Q);
				cout << "���������" << endl;
				break;
			case 4:
				QueueEmpty(Q) ? cout << "�ö���Ϊ�ն�" << endl : cout << "�ö����д�������" << endl;
				break;
			case 5:
				cout << "�ö��еĳ���Ϊ��" << QueueLength(Q) << endl;
				break;
			case 6:
				if (GetHead(Q, head))cout << "ͷԪ��Ϊ��" << head << endl;
				else cout << "�ö���Ϊ�ն�" << endl;
				break;
			case 7:
				cout << "��������Ҫ��ӵ�Ԫ��(Ԫ�ؼ��ÿո�������س�Ϊ������־)" << endl;
				while (1)
				{
					cin >> in;
					EnQueue(Q, in);
					if ('\n' == cin.get())
						break;
				}
				break;
			case 8:
				if (DeQueue(Q, de))cout << "��ɾ����ǰ����Ԫ��" << de << endl;
				else cout << "�ö�����û��Ԫ��" << endl;
				break;
			case 9:
				if (QueueEmpty(Q)) cout << "�ö�����û��Ԫ��";
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