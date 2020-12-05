#include<iostream>
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

typedef struct ArcCell {
	VRType  adj;							//VRType是顶点关系类型.对无权图,用1或0
											//表示相邻否,对带权图,则为权值类型 
	InfoType* info;							//该弧相关信息的指针
}ArcCell, AdjMastrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];		//顶点向量
	AdjMastrix arcs;						//邻接矩阵
	int vexnum, arcnum;						//图的当前顶点数和弧数
}MGraph;

struct closedge {
	VertexType adjvex;
	VRType lowcost;
}closedge[MAX_VERTEX_NUM];

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

int minimum(MGraph  G, struct closedge* closedg)
{
	int min, loc;

	min = INFINITY;   //最大值 亦可设置为2e9
		
	for (int i = 1; i < G.vexnum; i++)
	{
		if (min > closedg[i].lowcost && closedg[i].lowcost != 0)
		{
			min = closedg[i].lowcost;
			loc = i;
		}
	}
	return loc;
}

void MiniSpanTree_PRIM(MGraph G, VertexType u)
{
	int k = LocateVex(G, u);
	for (int j = 0; j < G.vexnum; j++)
		if (j != k)closedge[j] = { u,G.arcs[k][j].adj };
	closedge[k].lowcost = 0;
	for (int i = 1; i < G.vexnum; i++) {
		k = minimum(G, closedge);
		cout << closedge[k].adjvex << "->" << G.vexs[k] << endl;
		closedge[k].lowcost = 0;
		for (int j = 0; j < G.vexnum; j++)
			if (G.arcs[k][j].adj < closedge[j].lowcost)
				closedge[j] = { G.vexs[k],G.arcs[k][j].adj };
	}
}

int main()
{
	VertexType u;
	MGraph G;
	CreateGraphUDN(G);
	cout << "打印矩阵元素" << endl;
	TraverseGraphUDN(G);

	printf("请输入起始点：");
	cin >> u;
	cout << "PRIM:" << endl;
	MiniSpanTree_PRIM(G, u);

	return 0;
}