#include <stdio.h>

int main() {
	int n;
	scanf("%d",&n);
	int nums[2*n+1];
	for (int i = 0;i < 2*n + 1;i++) {
		scanf("%d",&nums[i]);
	}
	int ori = nums[0];
	for (int i = 1;i < 2*n + 1;i++) {
		ori ^= nums[i];
	}
	printf("%d",ori);
}

