#include<iostream>
using namespace std;

#define OK 1
#define TRUE 1
#define ERROR 0
#define FALSE 0
#define OVERFLOW -2
#define INFINITY  INT_MAX  //���ֵ �������Ϊ2e9
#define MAX_VERTEX_NUM  20 //��󶥵���

typedef int VRType;
typedef char InfoType;
typedef char VertexType;
typedef int Status;

typedef struct ArcCell {
	VRType  adj;							//VRType�Ƕ����ϵ����.����Ȩͼ,��1��0
											//��ʾ���ڷ�,�Դ�Ȩͼ,��ΪȨֵ���� 
	InfoType* info;							//�û������Ϣ��ָ��
}ArcCell, AdjMastrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];		//��������
	AdjMastrix arcs;						//�ڽӾ���
	int vexnum, arcnum;						//ͼ�ĵ�ǰ�������ͻ���
}MGraph;

struct closedge {
	VertexType adjvex;
	VRType lowcost;
}closedge[MAX_VERTEX_NUM];

Status LocateVex(MGraph G, char v)		//���ظõ���ͼ��λ��
{
	for (int i = 0; i < G.vexnum; i++)	//���춥������
		if (v == G.vexs[i])
			return i;
	return -1;

}

Status CreateGraphUDN(MGraph& G)		//����������,�ڽӾ����ʾ����
{
	VertexType v1, v2;
	InfoType IncInfo;
	VRType w;
	cout << "����������������G�Ķ�����������,�����Ƿ���������Ϣ����������1����������0���ո����" << endl;
	cin >> G.vexnum >> G.arcnum >> IncInfo;
	cout << "����������������G�Ķ������ƣ��ÿո����" << endl;
	for (int i = 0; i < G.vexnum; i++)	//���춥������
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)	//��ʼ���ڽ�����
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = { INFINITY,NULL };
	cout << "����������������Gÿ�������������������Ƽ�Ȩֵ������һ�鰴�س�" << endl;
	for (int k = 0; k < G.arcnum; k++)	//�����ڽӾ���
	{
		cin >> v1 >> v2 >> w;			//����һ���������Ķ��㼰Ȩֵ
		int i = LocateVex(G, v1);		//ȷ��v1��v2��G�е�λ��	
		int j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;			//��<v1,v2>��Ȩֵ
		//if (IncInfo)cin >> G.arcs[i][j].info;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

Status TraverseGraphUDN(MGraph G)		//����ڽӾ��� 
{
	//������ϽǶ���Ŀհ� 
	printf("      ");
	//����ڽӾ���������꣨ȫ�����㣩 
	for (int i = 0; i < G.vexnum; i++)
		printf(" %3c ", G.vexs[i]);//for 

	printf("\n");

	//������ϽǶ���Ŀհ� 
	printf("     +");

	//���һ������
	for (int i = 0; i < G.vexnum; i++)
		printf("-----");//for 
	printf("\n");
	//����ڽӾ���������꣨ȫ�����㣩������ 
	for (int i = 0; i < G.vexnum; i++) {
		//����ڽӾ�����ߵ�����
		printf(" %3c |", G.vexs[i]);
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[i][j].adj == INFINITY) {
				printf("  �� ");
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

	min = INFINITY;   //���ֵ �������Ϊ2e9
		
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
	cout << "��ӡ����Ԫ��" << endl;
	TraverseGraphUDN(G);

	printf("��������ʼ�㣺");
	cin >> u;
	cout << "PRIM:" << endl;
	MiniSpanTree_PRIM(G, u);

	return 0;
}