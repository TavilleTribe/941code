#include <stdio.h>

int main() {
	int c = 0;
	int array[100];
	for (int i = 0;;i++) {
		scanf("%d",&array[i]);
		c++;
		if (getchar() == '\n') {
			break;
		}
	}
	for (int i = c - 1;i >= 0;i--) {
		printf("%d ",array[i]);
	}
}
