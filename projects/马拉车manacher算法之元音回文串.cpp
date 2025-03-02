#include <stdio.h>
#include <string.h>
#define min(x,y) ((x<y)?(x):(y))
#define N 100100
char tmp[N];
char chr[N*2+5];
int p[N*2+5];
int n;
int manacher()
{
	int cnt=1,ans=0,r=0,mid=0;
	chr[0]='~';
	chr[1]='|';
	for(int i=0;i<n;++i)
	{
		chr[i*2+2]=tmp[i];
		chr[i*2+3]='|';
	}
	cnt=n*2+2;
	for(int t=1;t<=cnt;++t)
	{
		if(t<=r)
			p[t]=min(p[(mid<<1)-t],r-t+1);
		while(chr[t-p[t]]==chr[t+p[t]])
			++p[t];
		if(p[t]+t>r)
		{
			r=p[t]+t-1;
			mid=t;
		}
		if(p[t]>ans)
			ans=p[t];
	}
	return ans-1;
}
int main(void)
{
	scanf("%d%s",&n,tmp);
	for(int i=0;i<n;++i)
		if(tmp[i]!='a'&&tmp[i]!='e'&&tmp[i]!='i'&&tmp[i]!='o'&&tmp[i]!='u')
			tmp[i]='b';
	printf("%d",manacher());
	return 0;
}

