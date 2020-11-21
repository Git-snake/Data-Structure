#include<iostream>
using namespace std;
#define OK 1 
#define ERROR 0
typedef char TElemType;
typedef int Status;
typedef enum PointerTag {Link,Thread};     //枚举类型 Link==0;Thread==1
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;		//左右孩子指针
	PointerTag LTag, RTag;					//左右标志
}BiThrNode, * BiThrTree;

BiThrTree pre;
Status PrintElement(TElemType e)
{
	cout << e << " ";
	return OK;
}

Status CreateBiTree(BiThrTree& T)
{
	//按先序次序输入二叉树中的结点的值(一个字符).井号字符表示空树,
	//构造二叉链表表示的二叉树T。
	char c;
	cin >> c;
	if (c == '#')T = NULL;
	else
	{
		T = new BiTNode;
		T->data = c;
		CreateBiTree(T->lchild);
		if (T->lchild) /* 有左孩子 */
			T->LTag = Link;
		CreateBiTree(T->rchild);
		if (T->rchild) /* 有左孩子 */
			T->RTag = Link;
	}
	return OK;
}

void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (!p->lchild) { p->LTag = Thread; p->lchild = pre; }//前驱线索化
		if (!pre->rchild){pre->RTag = Thread; pre->rchild = p;}//后继线索化
		pre = p;
		InThreading(p->rchild);
	}
}

Status InOederThreading(BiThrTree& Thrt, BiThrTree T)
{
	Thrt = new BiThrNode;
	Thrt->LTag = Link;Thrt->RTag = Thread;//建头节点
	Thrt->rchild = Thrt;				  //右指针回指
	if(!T)Thrt->lchild = Thrt;			  //若二叉树为空，则左指针回指
	else
	{
		Thrt->lchild = T; pre = Thrt;
		InThreading(T);							//中序遍历进行中序线索化
		pre->rchild = Thrt; pre->RTag = Thread;	//最后一个结点线索化
		Thrt->rchild = pre;
	}
	return OK;
}

Status InOrderTraverse_Thr(BiThrTree T, Status(*Visit)(TElemType e))
{
	BiThrTree p;
	p = T->lchild;								//p指向根结点
	while (p != T)								//空树或者遍历结束时，p==T
	{
		while (p->LTag == Link)p = p->lchild;
		if (!Visit(p->data))return ERROR;		//访问其左子树为空的结点
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild; Visit(p->data);		//访问后继结点
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
	InOederThreading(Thrt, T); /*带头结点的中序线索化*/
	cout << "InOrderTraverse_Thr:" << endl;
	InOrderTraverse_Thr(Thrt,PrintElement);   /*遍历中序线索二叉树*/
	return 0;

}