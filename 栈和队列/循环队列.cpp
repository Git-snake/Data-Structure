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
	QElemType* base;//�ռ�
	int front;//ͷָ��
	int rear;//βָ��
}SqQueue;

Status InitQueue(SqQueue& Q){	
	//�����յĶ���
	Q.base = new QElemType[MAXQSIZE*sizeof(QElemType)];//ΪrearԤ��һ��λ��
	Q.front = Q.rear = 0;
	return OK;
}

Status DestoryQueue(SqQueue& Q) {
	//���ٶ���
	delete Q.base;
	Q.front = Q.rear = NULL;
	return OK;
}

Status ClearQueue(SqQueue& Q) {
	//���������
	Q.front = Q.rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q) {
	//��Ϊ�ն��з���OK�����򷵻�ERROR
	return Q.front == Q.rear ? OK : ERROR;
}

Status QueueLength(SqQueue Q) {
	//���ض��г���
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status GetHead(SqQueue Q, QElemType& e) {
	//��e���ض�ͷԪ��
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	return OK;
}

Status EnQueue(SqQueue& Q, QElemType e) {
	//�����µĶ�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;//������
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue& Q, QElemType& e) {
	//ɾ�������ض�ͷԪ��
	if (Q.front == Q.rear)return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

int main()
{
	cout << endl << "\t\t\tѭ��������ز���" << endl << endl;
	cout << "1.��ʼ������  \t\t2.���ٶ���    \t\t3.��ն���" << endl;
	cout << "4.�����п�    \t\t5.����г���  \t\t6.��ȡ��ͷԪ��" << endl;
	cout << "7.����Ԫ��    \t\t8.ɾ����ͷԪ��\t\t9.�������Ԫ��" << endl;
	cout << "0.�˳�" << endl;

	SqQueue Q;
	int choose = -1;
	int in, out, head, de;
	bool flag = false;
	while (choose)
	{
		cout << "��ѡ����ز�����";
		cin >> choose;
		if (choose != 1)
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
			cout << "��������Ҫ��ӵ�Ԫ��(Ԫ�ؼ��ÿո�������س�Ϊ������־)ע��������洢Ϊ"<<MAXQSIZE-1 << endl;
			while (1)
			{
				cin >> in;
				if (!EnQueue(Q, in))  cout << "��������"<<endl;
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
					cout << de << " ";
				}
			cout << endl;
			break;
		}
	}
	
}