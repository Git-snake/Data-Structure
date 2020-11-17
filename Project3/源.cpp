#include<iostream>
#define sizeof 3
using namespace std;
class Cstudent
{
public:
    double Print();
    int record();
    void set(string a, int b, int c[sizeof]) {
        name = a;
        card = b;
        for (int i = 0; i < sizeof; i++)
        {
            grade[i] = c[i];
        }
    };
private:
    string name;
    int card;
    int grade[sizeof];
} student[10];
double Cstudent::Print()
{
    int i = 0;
    int j = 0;
    int temp = 0;
    cout << "学生姓名:" << name << "  学号:" << card << endl << "单科成绩依次为:" << endl;
    for (i; i < sizeof; i++) {
        cout << grade[i] << endl;
    }
    for (j; j < sizeof; j++) {
        temp += grade[i];
    }
    cout << "平均成绩为:" << (double)temp / sizeof << endl;
}
int Cstudent::record()
{
    int l = 0, x = 0;
    for (l; l < sizeof; l++)
    {
        if (grade[l] < 60)
            x = 1;
        else x = 0;
    }
    return x;
}
int Record()
{
    int t = 0, s = 0;
    for (s; s < 10; s++)
    {
        t += student[s].record();
    }
    return t;
}
int main()
{
    string x;
    int y;
    int* z[sizeof];
    cout << "请按一定的次序分别录入10位学生的姓名，学号以及各科成绩" << endl;
    for (int i = 0; i < 10; i++)
    {
        student[i].set(x, y, z[sizeof]);
    }
    for (int i = 0; i < 10; i++)
    {
        student[i].Print;
    }
    cout << "不及格的总人数为：" << Record() << endl;
    return 0;
}
