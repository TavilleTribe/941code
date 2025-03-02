#include <stdio.h>
#include <string.h>

int main() {
    int n,m,k,t = 0;
    scanf("%d %d %d",&n,&m,&k);
    int b[n+1];
    memset(b,0,sizeof(b));
    for (int i = 1;i <= k;i++) {
        int st,en;
        scanf("%d %d",&st,&en);
        b[st] += 1;
        b[en+1] -= 1;
    }
    for (int i = 1;i <= n;i++) {
        b[i] += b[i-1];
        if(b[i] == 0) {
        	t++;
		}
    }
    printf("%d",t);
}
