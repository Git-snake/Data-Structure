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
    cout << "ѧ������:" << name << "  ѧ��:" << card << endl << "���Ƴɼ�����Ϊ:" << endl;
    for (i; i < sizeof; i++) {
        cout << grade[i] << endl;
    }
    for (j; j < sizeof; j++) {
        temp += grade[i];
    }
    cout << "ƽ���ɼ�Ϊ:" << (double)temp / sizeof << endl;
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
    cout << "�밴һ���Ĵ���ֱ�¼��10λѧ����������ѧ���Լ����Ƴɼ�" << endl;
    for (int i = 0; i < 10; i++)
    {
        student[i].set(x, y, z[sizeof]);
    }
    for (int i = 0; i < 10; i++)
    {
        student[i].Print;
    }
    cout << "�������������Ϊ��" << Record() << endl;
    return 0;
}
