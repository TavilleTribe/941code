#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int *generateRandomArray(int size) {
	int *p;
	p = (int *)malloc(size*sizeof(int));
	for (int i = 0;i < size;i++) {
		p[i] = rand()%50;
	}
	return p;
}

int main() {
	int n;
	srand(time(NULL));
	printf("Rules: if your input is bigger than the answer,it outputs >\nif your input is smaller than the answer,it outputs <\nPlease Input How many numbers:\n");
	scanf("%d",&n);
	int yours[n];
	memset(yours,0,sizeof(yours));
	int *a = generateRandomArray(n);
	printf("Correct Answer:\n");
	for (int i = 0;i < n;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	while (1) {
		int right = 0;
		for (int i = 0;i < n;i++) {
			scanf("%d",&yours[i]);
		}
		for (int i = 0;i < n;i++) {
			if (yours[i] > a[i]) {
				printf("> "); 
			}
			else if (yours[i] < a[i]) {
				printf("< ");
			}
			else {
				right++;
				printf("¡Ì ");
			}
		}
		printf("\n");
		if (right == n) {
			printf("All correct!");
			break;
		}
		else {
			printf("Have discorrect!Please input again:\n");
		}
	}
}
