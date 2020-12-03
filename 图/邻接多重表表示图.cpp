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

typedef enum { unvisited,visited }VisitIf;

typedef struct EBox {
	VisitIf mark;					//���ʱ��
	int   ivex, jvex;				//�ñ����������������λ��
	struct  EBox* ilink, * jlink;	//�ֱ�ָ�������������������һ����
	InfoType* info;					//�ñ���Ϣָ��
}EBox;
typedef struct VerBox {
	VertexType data;
	EBox* firstedge;				//ָ���һ�������ö���ı�
}VexBox;
typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum;			//����ͼ�ĵ�ǰ�������ͱ���
}AMLGraph;

