#include <iostream>
#include<algorithm>
constexpr auto SIZE = 100;
using namespace std;
void Intersection(int a[], int n, int b[], int m); //交集函数
void Union(int a[], int n, int b[], int m );       //并集函数
void Difference(int a[], int n, int b[], int m);  //差集函数

void title()                        //输出标题
{
    cout << "1-- - 输入集合A和B" << endl << "2-- - 求集合A交B" << endl;
    cout << "3-- - 求集合A并B" << endl << "4-- - 求集合A - B" << endl;
    cout << "5-- - 退出" << endl;
}
int _input(int C[ ])
{
    int number, count = 0;
    do
    {
        cin >> number;
        if (number < 0)
        {
            break;
        }
        for (size_t i = 0; i < count; i++)
        {
            if (C[i] == number)
            {
                cout << "当前元素与第" << i + 1 << "位元素重复，请重新输入" << endl;
                cin >> number;
            }
        }
        C[count] = number;
        count++;
        if (count==100)
        {
            cout << "已达到数组输入最高上限" << endl;
            break;
        }
    } while (1);
    return count;
}

void output(int c[])
{

}
void welcom()
{
    char n;
    int  num_a = 0, num_b = 0, A[SIZE], B[SIZE];
    do {
        cout << "请选择[1 2 3 4 5 ]:[ ]\b\b";
        cin >> n;
        while (n < '1' || n>'5')
        {
            cout << "输入错误,请重新输入" << endl;
            cin >> n;
        }
        switch (n)
        {
        case '1':
            cout << "请输入集合A(输入负数停止):" << endl;
            num_a=_input(&A[0]);
            cout << "请输入集合B(输入负数停止):" << endl;
            num_b=_input(&B[0]);
            break;

        case '2':
            Intersection(A, num_a, B, num_b);
            break;

        case '3':
            Union(A, num_a, B, num_b);
            break;

        case '4':
            Difference(A, num_a, B, num_b);
            break;
        }
    } while (n != '5');
}

int main()
{
    title();
    welcom();
}

void Intersection(int a[], int n, int b[], int m )
{
    int counter = 0,c[SIZE];
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (a[i] == b[j])
            {   
               // cout << counter<<" ";
                c[counter] = a[i];
                counter++;
               // cout << c[counter-1]<<" ";          
            }
    //cout << counter << " ";
    sort(c, c + counter);
    cout << "A交B={";
    for (unsigned i = 0; i < counter-1; i++)
        cout << c[i] << ",";
    cout << c[counter-1] << "}" << endl;
}

void Union(int a[], int n, int b[], int m)
{
    int counter = 0, flag = 0,c[SIZE*2];
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            if (a[i] == b[j])
                flag = 1;
        if (flag == 0)
            c[counter++] = a[i];
    }   
    for (size_t j = 0; j < m; j++) c[counter++] = b[j];
    sort(c, c + counter);
    cout << "A并B={";
    for (int i = 0; i < counter - 1; i++)
        cout << c[i] << ",";
    cout << c[counter-1] << "}" << endl;
}

void Difference(int a[], int n, int b[], int m)
{
    int counter = 0, flag = 1, c[SIZE * 2];
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (a[i] == b[j])
                flag = 0;
        }
        if (flag)
            c[counter++] = a[i];
    }
    sort(c, c + counter);
    cout << "A-B={";
    for (int i = 0; i < counter - 1; i++)
        cout << c[i] << ",";
    cout << c[counter-1] << "}" << endl;
}
