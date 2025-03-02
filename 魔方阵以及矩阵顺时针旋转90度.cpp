#include<stdio.h>
int main() {
	//幻方阵
	int n;
	scanf("%d",&n);
	int arr[20][20] = {0};
	int x=0;
	int y=n/2;
	int num=1;
	arr[x][y]=num;
	while(num<n*n) {
		num++;
		int x1=x,y1=y;
		x=(x+1)%n;
		y=(y+(n-2))%n;
		if(arr[x][y]==0) {
			arr[x][y]=num;
		}
		else {
			x=(x1+1)%n;
			y=y1;
			arr[x][y]=num;
		}
	}
	printf("原来：\n");
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
	printf("旋转后：\n");
	for(int i=0;i<n;i++) {
		for(int j=n-1;j>=0;j--) {
			printf("%5d",arr[j][i]);
		}
		printf("\n");
	}
	return 0;
}
	
