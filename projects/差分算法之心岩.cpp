#include <stdio.h>
#include <string.h>

int main() {
	int n,t=0;
	scanf("%d",&n);
	int b[n+3];
	memset(b,0,sizeof(b));
	for (int i = 1;i <= n;i++) {
		int l;
		scanf("%d",&l);
		if (l != 0) {
			int st1 = i-l,en1 = i-1;
			if (st1 < 1) {
				st1 = 0;
			}
			if (en1 < 1) {
				en1 = 0;
			}
			b[st1] += 1;
        	b[en1+1] -= 1;
			int st2 = i+1,en2 = i+l;
			if (st2 > n) {
				st2 = n+1;
			}
			if (en2 > n) {
				en2 = n+1;
			}
        	b[st2] += 1;
        	b[en2+1] -= 1;
		}
	}
	for (int i = 1;i <= n;i++) {
		b[i] += b[i-1];
		if(b[i]>0) {
			t++;
		}
	}
	printf("%d",t);
}
