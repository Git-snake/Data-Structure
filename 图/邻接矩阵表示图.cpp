#include <iostream>
using namespace std;

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define OVERFLOW -2
#define INFINITY  INT_MAX  //最大值 亦可设置为2e9
#define MAX_VERTEX_NUM  20 //最大顶点数

typedef int VRType;
typedef char InfoType;
typedef char VertexType;
typedef int Status;
typedef int Boolean;

typedef enum { DG, DN, UDG, UDN }GraphKind;	//{有向图、有向网、无向图、无向网}

typedef struct ArcCell {
	VRType  adj;							//VRType是顶点关系类型.对无权图,用1或0
											//表示相邻否,对带权图,则为权值类型 
	InfoType* info;							//该弧相关信息的指针
}ArcCell,AdjMastrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];		//顶点向量
	AdjMastrix arcs;						//邻接矩阵
	int vexnum, arcnum;						//图的当前顶点数和弧数
	GraphKind kind;							//图的种类标志
}MGraph;

typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode, * QueuePtr;
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Boolean visited[MAX_VERTEX_NUM];		//访问标志数组

Status CreateGraphUDN(MGraph& G)		//构建无向网,邻接矩阵表示方法
{
	VertexType v1, v2;
	InfoType IncInfo;
	VRType w;
	cin >> G.vexnum >> G.arcnum >> IncInfo;
	for (int i = 0; i < G.vexnum; i++)	//构造顶点向量
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)	//初始化邻接链表
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { INFINITY,NULL };
	for (int k = 0; k < G.arcnum; k++)	//构造邻接矩阵
	{							
		cin >> v1 >> v2 >> w;			//输入一条边依附的顶点及权值
		int i = LocateVex(G, v1);		//确定v1和v2在G中的位置	
		int j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;			//弧<v1,v2>的权值
		if (IncInfo)cin >> G.arcs[i][j].info;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}
Status LocateVex(MGraph G, char v)		//返回该点在图中位置
{
	for (int i = 0; i < G.vexnum; i++)	//构造顶点向量
		if (v == G.vexs[i])
			return i;
}
Status TraverseGraphUDN(MGraph G)		//输出邻接矩阵 
{

}
Status FirstAdjVex(MGraph G, int v);	//返回V的第一个邻接顶点。否则返回"空"
Status NextAdjVex(MGraph G, int v, int w); //返回V的(相对于W的)下一个邻接顶点,若W是V的最后一个邻接点,则返回"空"
Status Visit(MGraph G, int v);			//访问（打印）顶点
void DFSTraverse(MGraph G);				//对图作深度优先遍历
void DFS(MGraph G, int v);				//从第V个顶点出发递归地深度优先遍历图G
Status InitQueue(LinkQueue& Q);			//初始化队列
Status QueueEmpty(LinkQueue Q);			//判断是否为空队列
Status EnQueue(LinkQueue& Q, int e);	//插入元素,并成为新的队尾元素.
Status DeQueue(LinkQueue& Q, int& e);	//删除的对头元素.
void BFSTraverse(MGraph G);				//广度优先非递归遍历,辅助队列.
void Tips()								//功能菜单
{
	printf("******************************************************************\n");
	printf("*************************   无向网图  ****************************\n");
	printf("******************************************************************\n");
	printf("**********************     1.构建网图      ***********************\n");
	printf("**********************     2.输出邻接矩阵  ***********************\n");
	printf("**********************     3.深度优先遍历  ***********************\n");
	printf("**********************     4.广度优先遍历  ***********************\n");
	printf("**********************     5.退出          ***********************\n");
	printf("******************************************************************\n");
}
int main()
{
	int i;
	int flag = 0;
	MGraph G;
	do
	{
		system("cls");
		Tips();
		printf("请输入选择:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			CreateGraphUDN(G);
			flag = 1;
			break;
		case 2:
			if (flag)
				TraverseGraphUDN(G);
			else
				printf("未构建图.\n");
			break;
		case 3:
			if (flag)
			{
				DFSTraverse(G);
				printf("\n");
			}
			else
				printf("未构建图.\n");
			break;
		case 4:
			if (flag)
			{
				BFSTraverse(G);
				printf("\n");
			}
			else
				printf("未构建图.\n");
			break;
		case 5:
			printf("退出.\n"); exit(0);
		default:
			printf("没有该选项,请重新操作.\n"); break;
		}
		system("pause");
	} while (1);
	return OK;
}
