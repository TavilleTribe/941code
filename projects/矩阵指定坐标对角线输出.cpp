#include <stdio.h>

void getHeightExtension(int n,int x,int y) {
	int tx = x,ty = y;
	while (tx > 1 && ty > 1) {
		tx--;ty--;
	}
	while (tx <= n && ty <= n) {
		printf("(%d,%d) ",tx,ty);
		tx++;ty++;
	}
	printf("\n");
}

void getWidthExtension(int n,int x,int y) {
	int tx = x,ty = y;
	while (tx < n && ty > 1) {
		tx++;ty--;
	}
	while (tx >= 1 && ty <= n) {
		printf("(%d,%d) ",tx,ty);
		tx--;ty++;
	}
	printf("\n"); 
}

int main() {
	int n,px,py;
	scanf("%d %d %d",&n,&px,&py);
	for (int g = 0;g < n;g++) {
		printf("(%d,%d) ",px,g+1);
	}
	printf("\n");
	for (int i = 0;i < n;i++) {
		printf("(%d,%d) ",i+1,py);
	}
	printf("\n");
	getHeightExtension(n,px,py);
	getWidthExtension(n,px,py);
}
