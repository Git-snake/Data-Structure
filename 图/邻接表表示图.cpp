#include <iostream>
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

typedef struct ArcNode {
	int adjvex;					//�û���ָ��Ķ����λ��
	struct ArcNode* nextarc;	//ָ����һ������ָ��
	int info;					//�û�Ȩֵ
}ArcNode;

typedef struct VNode {
	VertexType data;			//������Ϣ
	ArcNode* firstarc;			//ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;	
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͻ���
	int kind;					//ͼ������
}ALGraph;

Status LocateVex(ALGraph G, VertexType v)		//���ظõ���ͼ��λ��
{
	for (int i = 0; i < G.vexnum; i++)	//���춥������
		if (v == G.vertices[i].data)
			return i;
	return -1;
}

Status visited[MAX_VERTEX_NUM + 1];//��־����
void (*VisitFunc)(VertexType e);   //����ָ�����

Status CreateUDN(ALGraph& G)
{
	VertexType v1, v2;
	VRType w;
	ArcNode* p, * q;
	ArcNode* qt;
	cout << "����������������G�Ķ��������������ÿո����" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "����������������G�Ķ������ƣ��ÿո����" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;//ͷ�帳ֵΪ�ձ�
	}
	cout << "����������������Gÿ�������������������Ƽ�Ȩֵ������һ�鰴�س�" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
	A:
		cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);		//ȷ��v1��v2��G�е�λ��	
		int j = LocateVex(G, v2);
		if (i == -1 && j == -1)
		{
			cout << "����Ķ�����Ϣ����,�������������Ϣ" << endl;
			goto A;
		}

		/*===============ͷ��===============*/
		p = new ArcNode;                      //����һ���µı߽��*p
		p->adjvex = j;                        //�ڽӵ����Ϊj
		p->info = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;           //���½��*p1���붥��vi�ı߱�ͷ��(ͷ�巨)
		q = new ArcNode;                      //����һ���µı߽��*q
		q->adjvex = i;                        //�ڽӵ����Ϊi
		q->info = w;
		q->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = q;           //���½��*p2���붥��vj�ı߱�ͷ��(ͷ�巨)
	}
	return OK;
}

int main()
{
	ALGraph G;
	CreateUDN(G);
	cout << "����ڽӱ�" << endl;
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