#include<stdio.h>
#include<string.h>

const int maxn=1e6+100;
int prime[maxn],num[maxn];
int k,t;

int check(int x)
{
    for(int i=1;i<=k;i++)
    {
	    int pn=0,n=x;
	    while(n)
	    {
	    	pn+=n/prime[i];
	    	n/=prime[i];
	    }
	    if(pn<num[i]) return 0;
    }
    return 1;
}
void printOutAns(int p)
{
	k=0;
  	for(int i=2;i*i<=p;i++)
  	{
      	if(p%i==0)
      	{
          	prime[++k]=i;
          	while(p%i==0)
          	{
            	num[k]++;
            	p/=i;
          	}
      	}
  	}
  	if(p>1) prime[++k]=p,num[k]++;
  	int l=1,r=1e9,mid,ans;
  	while(l<=r)
  	{
      	mid=(l+r)/2;
      	if(check(mid))r=mid-1,ans=mid;
      	else l=mid+1;
  	}
  	memset(prime,0,sizeof prime);
  	memset(num,0,sizeof num);
  	printf("%d",ans);
}

int main()
{
	int p;
   	scanf("%d",&p);
    printOutAns(p);
}

