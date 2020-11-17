#include<iostream>
using namespace std;
class CComplex
{
public:
	CComplex()
	{
		real = 0.0;
		imag = 0.0;
	}
	CComplex(float x, float y)
	{
		real = x;
		imag = y;
	}
	CComplex operator + (CComplex & obj1)
	{
		CComplex obj2;
		obj2.real = this->real + obj1.real;
		obj2.imag = this->imag + obj1.imag;
		return obj2;
	}
	CComplex operator++()
	{
		CComplex temp;
		temp.real = this->real + 1.0f;
		temp.imag = this->imag + 1.0f;
		return temp;
	}
	void print()
	{
		cout << real << "+" << imag << "i" << endl;
	}
	CComplex operator--();
private:
	float real;
	float imag;
};
CComplex CComplex:: operator--()
{
	CComplex x;
	x.real = this->real - 1.0f;
	x.imag = this->imag - 1.0f;
	return x;
}
int main()
{
	CComplex obj1(2.1f,3.2f);
	CComplex obj2(3.6f,2.5f);
	cout << "obj1=";
	obj1.print();
	cout << "obj2=";
	obj2.print();
	CComplex obj3 = obj1 + obj2;
	cout << "before++,obj3=";
	obj3.print();
	obj3=++obj3;
	cout << "after++,obj3=";
	obj3.print();
	obj3=--obj3;
	cout << "after--,obj3=";
	obj3.print();
	CComplex obj4 = ++obj3;
	cout << "obj4=";
	obj4.print();
}