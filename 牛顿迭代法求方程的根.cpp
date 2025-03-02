#include<stdio.h>
#include<math.h>
int main()
{
	int i=0;
	double x1=1.5,x2=0;//迭代初值
	while (fabs(x2-x1)>=1e-5)
	{
		x1=x1-(2*x1*x1*x1-4*x1*x1+3*x1-6)/(6*x1*x1-8*x1+3);
		x2=x1-(2*x1*x1*x1-4*x1*x1+3*x1-6)/(6*x1*x1-8*x1+3);
		
		i++;
		printf("第%d次迭代  x1=%9.8f\tx2=%9.8f\n",i,x1,x2);
	}
	printf("\nx=%9.8f\t共迭代:%d次\n",x2,i);
	return 0;
}
