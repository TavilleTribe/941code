#include <stdio.h>

int main() {
	int arr[10] = {1,3,998,657,2,4,8,3,9,10};
	int num[1001] = {0};
	for (int i = 0;i < 10;i++) {
		num[arr[i]]+=1;
	}
	for (int i = 0;i <= 1000;i++) {
		for (int j = 1;j <= num[i];j++) {
			printf("%d ",i);
		}
	}
}
