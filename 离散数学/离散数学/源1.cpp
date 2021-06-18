#include<iostream>
#include<fstream>
//#include <cstdio>    
//#include <cstring> 
#include <cstdlib> 

using namespace std;

typedef struct Student
{
    int num;         	//学号 
    string name; 		//姓名  
    int score;			//分数 
}Stu;

typedef struct StuArr
{
    Stu* data;
    int length;
}StuArr;

void InitArr(StuArr& L)		//初始化链表  
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