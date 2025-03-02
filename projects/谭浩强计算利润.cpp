#include <stdio.h>

int main()
{
	double r1=0.015,r2=0.021,r3=0.0275,r5=0.03,r=0.0035;
	double p1,p2,p3,p4,p5,m;
	scanf("%lf",&m);
	
	p1 = m*r5*5 + m;
	p2 = m*r2*2 + (m*r2*2 + m)*r3*3 + m;
	p3 = m*r3*3 + (m*r3*3 + m)*r2*2 + m;
	p4 = m*(1+r1)*(1+r1)*(1+r1)*(1+r1)*(1+r1);
	p5 = 1;
	for(int i=1; i<=20; i++)
	{
		p5 = p5*(1+r/4);	
	}
	p5 = p5 * m;
	
	printf("p1=%lf\n",p1);
	printf("p2=%lf\n",p2);
	printf("p3=%lf\n",p3);
	printf("p4=%lf\n",p4);
	printf("p5=%lf",p5);
	
    return 0;
}
