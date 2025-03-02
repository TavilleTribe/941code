#include<stdio.h>

int main()
{
	int n,count=0,temp=0,sign,num;
	scanf("%d",&n);
	num = n;
	if(n==0) count=1;
	sign = n<0? -1: 1;
	n*= sign;
	while(n)
	{
		temp = temp*10 + n%10;
		n/=10;
		count++;
	}	
	printf("%d\n",count);
	
	if(temp==0) printf("0");
	n = temp;
	while(temp)
	{
		printf("%d ",temp%10);
		temp/=10;
	}
	printf("\n");
	
	temp = num;
	while (temp) {
		printf("%d",temp % 10);
		temp /= 10;
	}
}
