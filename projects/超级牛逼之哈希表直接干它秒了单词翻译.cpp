#include <stdio.h>
#include <string.h>

int main() {
	int nums[1005];
	memset(nums,-1,sizeof(nums));
	int s,n,input,t = 0;
	s = 3,n = 7;
	int arr[] = {1,2,1,3,1,5,6};
	//scanf("%d %d",&s,&n);
	for (int i = 0;i < n;i++) {
		//scanf("%d",&input);
		input = arr[i];
		if (nums[input] == -1) {
			t++;
		}
		else {
			if (i - nums[input] > s) {
				t++;
			}
		}
		nums[input] = i;
	}
	printf("%d",t);
}
