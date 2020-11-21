#include<iostream>
using namespace std;
#define OK 1 
#define ERROR 0
typedef char TElemType;
typedef int Status;
typedef enum PointerTag {Link,Thread};     //ö������ Link==0;Thread==1
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;		//���Һ���ָ��
	PointerTag LTag, RTag;					//���ұ�־
}BiThrNode, * BiThrTree;

BiThrTree pre;
Status PrintElement(TElemType e)
{
	cout << e << " ";
	return OK;
}

Status CreateBiTree(BiThrTree& T)
{
	//�������������������еĽ���ֵ(һ���ַ�).�����ַ���ʾ����,
	//������������ʾ�Ķ�����T��
	char c;
	cin >> c;
	if (c == '#')T = NULL;
	else
	{
		T = new BiTNode;
		T->data = c;
		CreateBiTree(T->lchild);
		if (T->lchild) /* ������ */
			T->LTag = Link;
		CreateBiTree(T->rchild);
		if (T->rchild) /* ������ */
			T->RTag = Link;
	}
	return OK;
}

void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (!p->lchild) { p->LTag = Thread; p->lchild = pre; }//ǰ��������
		if (!pre->rchild){pre->RTag = Thread; pre->rchild = p;}//���������
		pre = p;
		InThreading(p->rchild);
	}
}

Status InOederThreading(BiThrTree& Thrt, BiThrTree T)
{
	Thrt = new BiThrNode;
	Thrt->LTag = Link;Thrt->RTag = Thread;//��ͷ�ڵ�
	Thrt->rchild = Thrt;				  //��ָ���ָ
	if(!T)Thrt->lchild = Thrt;			  //��������Ϊ�գ�����ָ���ָ
	else
	{
		Thrt->lchild = T; pre = Thrt;
		InThreading(T);							//���������������������
		pre->rchild = Thrt; pre->RTag = Thread;	//���һ�����������
		Thrt->rchild = pre;
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
{
	BiThrTree p;
	p = T->lchild;								//pָ������
	while (p != T)								//�������߱�������ʱ��p==T
	{
		while (p->LTag == Link)p = p->lchild;
		if (!Visit(p->data))return ERROR;		//������������Ϊ�յĽ��
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild; Visit(p->data);		//���ʺ�̽��
		}
		p = p->rchild;
	}
	return OK;
}

int main()
{
	BiThrTree T;
	BiThrTree Thrt;
	cout << "Input the Threaded BinaryTree 's node:" << endl;
	CreateBiTree(T);
	InOederThreading(Thrt, T); /*��ͷ��������������*/
	cout << "InOrderTraverse_Thr:" << endl;
	InOrderTraverse_Thr(Thrt,PrintElement);   /*������������������*/
	return 0;

}