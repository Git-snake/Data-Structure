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

bool visited[MAX_VERTEX_NUM];		//访问标志数组

Status LocateVex(MGraph G, char v)		//返回该点在图中位置
{
	for (int i = 0; i < G.vexnum; i++)	//构造顶点向量
		if (v == G.vexs[i])
			return i;
	return -1;

}

Status CreateGraphUDN(MGraph& G)		//构建无向网,邻接矩阵表示方法
{
	VertexType v1, v2;
	InfoType IncInfo;
	VRType w;
	cout << "请依次输入无向网G的顶点数，弧数,弧上是否存在相关信息（存在输入1不存在输入0）空格隔开" << endl;
	cin >> G.vexnum >> G.arcnum >> IncInfo;
	cout << "请依次输入无向网G的顶点名称，用空格隔开" << endl;
	for (int i = 0; i < G.vexnum; i++)	//构造顶点向量
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)	//初始化邻接链表
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { INFINITY,NULL };
	cout << "请依次输入无向网G每条弧依附的两顶点名称及权值，输完一组按回车" << endl;
	for (int k = 0; k < G.arcnum; k++)	//构造邻接矩阵
	{							
		cin >> v1 >> v2 >> w;			//输入一条边依附的顶点及权值
		int i = LocateVex(G, v1);		//确定v1和v2在G中的位置	
		int j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;			//弧<v1,v2>的权值
		//if (IncInfo)cin >> G.arcs[i][j].info;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

Status TraverseGraphUDN(MGraph G)		//输出邻接矩阵 
{
	//输出左上角多余的空白 
	printf("      ");
	//输出邻接矩阵的上坐标（全部顶点） 
	for (int i = 0; i < G.vexnum; i++) 
		printf(" %3c ", G.vexs[i]);//for 

	printf("\n");

	//输出左上角多余的空白 
	printf("     +");

	//输出一条横线
	for (int i = 0; i < G.vexnum; i++) 
		printf("-----");//for 
	printf("\n");
	//输出邻接矩阵的左坐标（全部顶点）和内容 
	for (int i = 0; i < G.vexnum; i++) {
		//输出邻接矩阵左边的坐标
		printf(" %3c |", G.vexs[i]);
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j].adj == INFINITY) {
				printf("  ∞ ");
			}//if 
			else {
				printf(" %3d ", G.arcs[i][j].adj);
			}//else
		}//for 
		printf("\n     |\n");
	}//for 
	return OK;
}
Status FirstAdjVex(MGraph G, char v)	//返回V的第一个邻接顶点。否则返回"空"
{
	int k;
	k = LocateVex(G, v);
		for (int j = 0, t = INFINITY; j < G.vexnum; j++)
			if (G.arcs[k][j].adj != t)
				return j;
	return -1;
}
Status NextAdjVex(MGraph G, char v, char w) //返回V的(相对于W的)下一个邻接顶点,若W是V的最后一个邻接点,则返回"空"
{
	int j = INFINITY;
	int k1 = LocateVex(G, v);
	int k2 = LocateVex(G, w);

	for (int i = k2 + 1; i < G.vexnum; ++i)
		if (G.arcs[k1][i].adj != j)
			return i;
	return -1;
}
Status Visit(MGraph G, char v)	//访问（打印）顶点
{
	printf(" %3c ", v);
	//操作成功 
	return OK;
}
void DFS(MGraph G, int v)				//从第V个顶点出发递归地深度优先遍历图G
{
	visited[v] = TRUE; Visit(G,G.vexs[v] );
	for (auto w = FirstAdjVex(G,G.vexs[v]); w >= 0; w = NextAdjVex(G, G.vexs[v], G.vexs[w]))
		if (!visited[w]) DFS(G, w);
}
void DFSTraverse(MGraph G)				//对图作深度优先遍历
{
	for (int v = 0; v < G.vexnum; ++v)  visited[v] = FALSE;
	for (int v = 0; v < G.vexnum; ++v)
		if (!visited[v])
			DFS(G, v);
}

Status InitQueue(LinkQueue& Q)			//初始化队列
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
Status QueueEmpty(LinkQueue Q)			//判断是否为空队列
{
	return Q.front == Q.rear ? OK : ERROR;
}
Status EnQueue(LinkQueue& Q, int e)	  //插入元素,并成为新的队尾元素.
{
	QNode* p = new QNode;
	p->data = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue& Q, int& e)	//删除的对头元素.
{
	if (Q.front == Q.rear)return ERROR;
	QNode* p = new QNode;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	delete p;
	return OK;
}
void BFSTraverse(MGraph G)				//广度优先非递归遍历,辅助队列.
{
	int u;
	//广度优先遍历使用到遍历 
	LinkQueue Q;
	//预置标志数组visited所有值为FALSE 
	for (int v = 0; v < G.vexnum; ++v) visited[v] = FALSE;
	//for 
	//初始化辅助队列Q，得到一个空队列 
	InitQueue(Q);
	//广度优先遍历主循环 
	for (int v = 0; v < G.vexnum; ++v) {
		//v尚未访问
		if (!visited[v]) {
			//设置v已经被访问 
			visited[v] = TRUE;
			//访问第v顶点
			Visit(G, G.vexs[v]);
			//v入队列
			EnQueue(Q, v);
			//队列不空 
			while (!QueueEmpty(Q)) {
				//队头元素出队并置为u
				DeQueue(Q, u);
				//依次访问第u顶点的邻接顶点 
				for (int w = FirstAdjVex(G, G.vexs[u]); w >= 0;
					w = NextAdjVex(G, G.vexs[u], G.vexs[w])) {
					//w为v尚未访问的邻接顶点
					if (!visited[w]) {
						//设置第w顶点已被访问 
						visited[w] = TRUE;
						//访问第w顶点
						Visit(G, G.vexs[w]);
					}//if 
				}//for 
			}//while 
		}//if
	}//for 

	//销毁循环队列 
	//DestoryQueue(Q);
}
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
		scanf_s("%d", &i);
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
