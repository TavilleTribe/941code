#include <stdio.h>
#include <string.h>

int getGoodPair(int *nums,int size) {
	int j,ans = 0;
	int hash[101];
	memset(hash,0,sizeof(hash));
	for (j = 0;j < size;++j) {
		ans += hash[nums[j]];
		++hash[nums[j]];
	}
	return ans;
}

int main() {
	int size;
	scanf("%d",&size);
	int arr[size];
	for (int i = 0;i < size;i++) {
		scanf("%d",&arr[i]);
	}
	printf("%d",getGoodPair(arr,size));
}
