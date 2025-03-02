#include <stdio.h>
#include <string.h>

int main() {
	int L,M,t = 0;
	scanf("%d %d",&L,&M);
	int arr[L+2];
	memset(arr,0,sizeof(arr));
	for (int i = 0;i < M;i++) {
		int st,en;
		scanf("%d %d",&st,&en);
		arr[st+1]+=1;
		arr[en+2]-=1;
	}
	for (int i = 1;i <= L+1;i++) {
		arr[i]+=arr[i-1];
		if (arr[i] == 0) {
			t++;
		}
	}
	printf("%d",t);
}
