#include<iostream>
#include<fstream>
//#include <cstdio>    
//#include <cstring> 
#include <cstdlib> 

using namespace std;

typedef struct Student
{
    int num;         	//ѧ�� 
    string name; 		//����  
    int score;			//���� 
}Stu;

typedef struct StuArr
{
    Stu* data;
    int length;
}StuArr;

void InitArr(StuArr& L)		//��ʼ������  
{
    int i = 0;
    ifstream fin;
    fin.open("data.txt");
    L.data = (Stu*)malloc(sizeof(Stu) * i);
    while (!fin.eof())
    {
        L.data = (Stu*)realloc(L.data, sizeof(Stu) * (i + 1));
        fin >> L.data[i].num;
        cout << L.data[i].num << " ";
        fin >> L.data[i].name;
        //getline(fin,L.data[i].name, ' ');
        cout << L.data[i].name << " ";
        fin >> L.data[i].score;
        cout << L.data[i].score << " ";
        i++;
    }
    L.length = i;
}

int main()
{
    StuArr L;
    InitArr(L);
    return 0;
}