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

typedef struct ArcNode {
	int adjvex;					//该弧所指向的顶点的位置
	struct ArcNode* nextarc;	//指向下一条弧的指针
	int info;					//该弧权值
}ArcNode;

typedef struct VNode {
	VertexType data;			//顶点信息
	ArcNode* firstarc;			//指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;	
	int vexnum, arcnum;			//图的当前顶点数和弧数
	int kind;					//图的种类
}ALGraph;

Status LocateVex(ALGraph G, VertexType v)		//返回该点在图中位置
{
	for (int i = 0; i < G.vexnum; i++)	//构造顶点向量
		if (v == G.vertices[i].data)
			return i;
	return -1;
}

Status visited[MAX_VERTEX_NUM + 1];//标志数组
void (*VisitFunc)(VertexType e);   //函数指针变量

Status CreateUDN(ALGraph& G)
{
	VertexType v1, v2;
	VRType w;
	ArcNode* p, * q;
	ArcNode* qt;
	cout << "请依次输入无向网G的顶点数、弧数，用空格隔开" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "请依次输入无向网G的顶点名称，用空格隔开" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;//头插赋值为空表
	}
	cout << "请依次输入无向网G每条弧依附的两顶点名称及权值，输完一组按回车" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
	A:
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);		//确定v1和v2在G中的位置	
		int j = LocateVex(G, v2);
		if (i == -1 && j == -1)
		{
			cout << "输入的顶点信息有误,请重新输入该信息" << endl;
			goto A;
		}

		/*===============头插===============*/
		p = new ArcNode;                      //生成一个新的边结点*p
		p->adjvex = j;                        //邻接点序号为j
		p->info = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;           //将新结点*p1插入顶点vi的边表头部(头插法)
		q = new ArcNode;                      //生成一个新的边结点*q
		q->adjvex = i;                        //邻接点序号为i
		q->info = w;
		q->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = q;           //将新结点*p2插入顶点vj的边表头部(头插法)
	}
	return OK;
}

int main()
{
	ALGraph G;
	CreateUDN(G);
	cout << "输出邻接表" << endl;
	ArcNode* p;
	for (int i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		cout << G.vertices[i].data << "-->";
		while (p)
		{
			cout << G.vertices[p->adjvex].data << "-" << p->info << "-->";
			p = p->nextarc;
		}
		cout << "^" << endl;
	}
	return 0;
}