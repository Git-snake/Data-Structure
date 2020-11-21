#include<iostream>
#include <queue>
using namespace std;
#define OK 1 
#define ERROR 0
#define MAX_TREE_SIZE 100					//二叉树的最大结点数
typedef char TElemType;
typedef int Status;
/*顺序存储
typedef TElemType SqBiTree[MAX_TREE_SIZE];  //0号单元存储根结点
SqBiTree bt;
*/
/*链表存储*/
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;		//左右孩子指针
}BiTNode, * BiTree;

Status PrintElement(TElemType e)
{
	cout << e << " ";
	return OK;
}

Status CreateBiTree(BiTree& T)
{
	//按先序次序输入二叉树中的结点的值(一个字符).井号字符表示空树,
	//构造二叉链表表示的二叉树T。
	char c;
	cin >> c;
	if (c == '#')T = NULL;
	else
	{
		T = new BiTNode ;
		T->data = c;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	//采用二叉链表存储结构，Visit是对结点操作的应用函数。
	//先序遍历二叉树T，对每一个结点调用函数Visti一次且仅一次。
	//一旦Visit()失败，则操作失败。
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild,Visit))
				if(PreOrderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}
	else return OK;
}

Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	//采用二叉链表存储结构，Visit是对结点操作的应用函数。
	//中序遍历二叉树T，对每一个结点调用函数Visti一次且仅一次。
	//一旦Visit()失败，则操作失败。

	if (T)
	{
		if (PreOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else return OK;
}

Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	//采用二叉链表存储结构，Visit是对结点操作的应用函数。
	//后序遍历二叉树T，对每一个结点调用函数Visti一次且仅一次。
	//一旦Visit()失败，则操作失败。

	if (T)
	{
		if (PreOrderTraverse(T->lchild, Visit))
			if (PreOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;
	}
	else return OK;
}

queue<BiTNode *>q;
Status LeveOrderTraverse(BiTree T)
{
	//采用二叉链表存储结构，Visit是对结点操作的应用函数。
	//层次遍历二叉树T，对每一个结点调用函数Visti一次且仅一次。
	//一旦Visit()失败，则操作失败。
	if (T != NULL)
	{
		q.push(T);
		while (!q.empty())
		{
			cout << q.front()->data;
			if (q.front()->lchild != NULL)
				q.push(q.front()->lchild);
			if (q.front()->rchild != NULL)
				q.push(q.front()->rchild);
			q.pop();
			cout << " ";
		}
	}
	return OK;
}

int main()
{
	BiTree A;
	cout << "按先序次序输入二叉树中的结点的值(一个字符).‘#’字符表示空树." << endl;
	CreateBiTree(A);
	cout << "先序遍历二叉树" << endl;
	PreOrderTraverse(A, PrintElement);
	cout <<endl<< "中序遍历二叉树" << endl;
	InOrderTraverse(A, PrintElement);
	cout <<endl<< "后序遍历二叉树" << endl;
	PostOrderTraverse(A, PrintElement);
	cout <<endl<< "层次遍历二叉树" << endl;
	LeveOrderTraverse(A);
}