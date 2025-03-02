#include <iostream>			//输入输出流
#include <math.h>
using namespace std;			//名空间

typedef struct
{
	double real;				//复数的实部
	double imag;				//复数的虚部 
} Complex;

//初始化复数，即为复数分配存储空间
void InitComplex(Complex *&z)
{
	z=new Complex;			//z=(Complex *)malloc(sizeof(Complex));
} 

//构造复数
void AssignComplex(Complex *&z,double v1,double v2) 				//引用型形参 
{
	z->real=v1;
	z->imag=v2;
}

//输出复数
void DispComplex(Complex *z) 
{
	if(z->real!=0){
		if(z->imag>0) {
			cout<<z->real<<"+"<<z->imag<<"i";
		}
		else if(z->imag==0) {
			cout<<z->real;
		}
		else {
			cout<<z->real<<z->imag<<"i";
		}
	}
	else {
		if(z->imag!=0) {
			cout<<z->imag<<"i";
		}
		else {
			cout<<0;
		}
	}
}//需要对输出函数进一步优化，能正确输出  6，-i, 0,8+i......

//求复数的和
void AddComplex(Complex *v1,Complex *v2,Complex *&s) 
{
	s->real=v1->real+v2->real;
	s->imag=v1->imag+v2->imag;
}

void MinusComplex(Complex *v1,Complex *v2,Complex *&s) {
	s->real=v1->real-v2->real;
	s->imag=v1->imag-v2->imag;
}

void MultiplyComplex(Complex *v1,Complex *v2,Complex *&s) {
	s->real=v1->real*v2->real+v1->imag*v2->imag;
	s->imag=v1->real*v2->imag+v1->imag*v2->real;
}

int DivideComplex(Complex *v1,Complex *v2,Complex *&s) {
	if (v2->real == 0&& v2->imag==0) {
		return 0;
	}
	s->real=(v1->real*v2->real+v1->imag*v2->imag)/(v2->real*v2->real+v2->imag*v2->imag);
	s->imag=(v1->imag*v2->real+v1->real*v2->imag)/(v2->real*v2->real+v2->imag*v2->imag);
	return 1;
}

double ModComplex(Complex *z) {
	return sqrt(z->real*z->real+z->imag*z->imag);
}

//销毁复数
void DestroyComplex(Complex *&z)
{
	delete z;
} 

int main()
{
	double a,b;
	cout<<"请输入第一个复数的实部:";cin>>a;
	cout<<"请输入第一个复数的虚部:";cin>>b;
	
	Complex *z1;InitComplex(z1);
	AssignComplex(z1,a,b);
	cout<<"第一个复数为:";DispComplex(z1);cout<<endl;
	cout<<"第一个复数的模为:"<<ModComplex(z1)<<endl;
	
	double c,d;
	cout<<"请输入第二个复数的实部:";cin>>c;
	cout<<"请输入第二个复数的虚部:";cin>>d;
	
	Complex *z2;InitComplex(z2);
	AssignComplex(z2,c,d);
	cout<<"第二个复数为:";DispComplex(z2);cout<<endl;
	cout<<"第二个复数的模为:"<<ModComplex(z2)<<endl;
	
	Complex *sum;InitComplex(sum);
	AddComplex(z1,z2,sum);
	cout<<"复数的和为:";DispComplex(sum);cout<<endl;
	MinusComplex(z1,z2,sum);
	cout<<"复数的差为:";DispComplex(sum);cout<<endl;
	MultiplyComplex(z1,z2,sum);
	cout<<"复数的积为:";DispComplex(sum);cout<<endl;
	int flag = DivideComplex(z1,z2,sum);
	if (flag == 0) {
		cout<<"复数的商不合法";cout<<endl;
	} else {
		cout<<"复数的商为:";DispComplex(sum);cout<<endl;
	}
	
	return 0;
 } 
