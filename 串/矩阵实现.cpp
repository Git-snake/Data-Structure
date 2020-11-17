#include<iostream>
#include<cstdarg>
using namespace std;
#define OK 1
#define ERROR 0
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType* base;	//Ԫ�ػ�ַ
	int dim;		//ά��
	int* bounds;	//ά���ַ
	int* constants;	//ӳ������ַ
}Array;

Status InitArry(Array& A, int dim, ...)
{
	//������Ӧ������
	if (dim <1 || dim>MAX_ARRAY_DIM)
		return ERROR;
	A.dim = dim;
	A.bounds = new int[dim * sizeof(int)];
	if (A.bounds)exit(OVERFLOW);	//�׳�������ֵΪ3
	int  elemtotal = 1;
	va_list ap;
	va_start(ap, dim);
	for (size_t i = 0; i < dim; i++)
	{
		A.bounds[i] = va_arg(ap, int);
		if (A.bounds[i] < 0)return UNDERFLOW;	//����ֵΪ4
		elemtotal *= A.bounds[i];
	}
	va_end(ap);
	A.base = new ElemType[elemtotal * sizeof(int)];
	if (!A.base)exit(OVERFLOW);
	A.constants = new int[dim * sizeof(int)];
	for (size_t i = dim - 2; i >= 0; --i)
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
	return OK;
}

Status  DestroyArray(Array& A)
{
	//�ݻ�����
	if (!A.base)return ERROR;
	delete A.base;
	A.base = NULL;
	if (!A.bounds) return ERROR;
	delete A.bounds; A.bounds = NULL;
	if (!A.constants)return ERROR;
	delete A.constants; A.constants = NULL;
	return OK;
}

Status Locate(Array A, va_list ap, int& off)
{	
	//���ظ�Ԫ�ص���Ե�ַoff
	off = 0;
	int ind;
	for (size_t i = 0; i < A.dim; ++i)
	{
		ind = va_arg(ap, int);
		if (ind < 0 || ind >= A.bounds[i])return OVERFLOW;
		off += A.constants[i] * ind;
	}
	return OK;
}

Status Value(Array A, ElemType& e, ...)
{
	//��e����A��Ԫ��ֵ
	va_list ap;
	Status result;
	int off;
	va_start(ap, e);
	if ((result = Locate(A, ap, off)) <= 0)return result;
	e = *(A.base + off);
	return OK;
}

Status Assign(Array& A, ElemType e, ...)
{
	//��e��ֵ��ֵ��A
	va_list ap;
	Status result;
	int off;
	va_start(ap, e);
	if ((result = Locate(A, ap, off)) <= 0)return result;
	*(A.base + off) = e;
	return OK;
}

int main()
{
	Array A;
}

