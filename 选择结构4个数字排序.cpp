/*输入4个整数，要求按由小到大的顺序输出*/
#include <stdio.h>
int main(){
	int a,b,c,d,t;
	while (scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF) {
		if(a>b){
			t = a;
			a = b;
			b = t;
		}
		if(a>c){
			t = a;
			a = c;
			c = t;
		}
		if(a>d){
			t = a;
			a = d;
			d = t;
		}
		if(b>c){
			t = b;
			b = c;
			c = t;
		}
		if(b>d){
			t = b;
			b = d;
			d = t;
		}
		if(c>d){
			t = c;
			c = d;
			d = t;
		}
		printf("%d %d %d %d\n",a,b,c,d);
	}
}

