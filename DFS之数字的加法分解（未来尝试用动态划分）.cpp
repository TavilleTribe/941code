#include <stdio.h>

int a[55],n,sum,t;

void dfs(int length) {
	if (sum == n) {
		printf("%d=%d",n,a[1]);
		for (int i = 2;i < length;i++) {
			printf("+%d",a[i]);
		}
		printf("\n");
		t++;
		return;
	}
	for (int i = 1;i <= n-1;i++) {
		if (sum < n && i >= a[length-1]) {
			a[length] = i;
			sum+=i;
			dfs(length+1);
			sum-=a[length];
			a[length] = 0;
		}
	}
	return;
}

int main() {
	scanf("%d",&n);
	dfs(1);
	printf("total=%d",t);
}
