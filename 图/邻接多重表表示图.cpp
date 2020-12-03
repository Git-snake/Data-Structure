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

typedef enum { unvisited,visited }VisitIf;

typedef struct EBox {
	VisitIf mark;					//访问标记
	int   ivex, jvex;				//该边依附的两个顶点的位置
	struct  EBox* ilink, * jlink;	//分别指向依附这两个顶点的下一条边
	InfoType* info;					//该边信息指针
}EBox;
typedef struct VerBox {
	VertexType data;
	EBox* firstedge;				//指向第一条依附该顶点的边
}VexBox;
typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum;			//无向图的当前顶点数和边数
}AMLGraph;

