#include <stdio.h>

int digit;

//将一个整数，用数组的方式进行储存 
int fj(int a[],int n) {
	int i;
	for (i = 0;n!=0;i++) {
		a[i]=n%10;    //数组元素等于整数n的一个数字 
		n/=10;
	}
	return i;
}

void display(int a[],int m) {
	for (int i = m-1;i >= 0;i--) {
		printf("%d",a[i]);
	}
}

int hx(int a[],int m) {
	for (int i = 0;i <= m / 2;i++) {
		if (a[i] != a[m-1-i]) {
			return 0;
		}
	}
	return 1;
}

void copy(int a[],int b[],int m) {
	for (int i = 0;i < m;i++) {
		b[m-1-i] = a[i];
	}
}

void add(int a[],int b[],int m) {
	for (int i = 0;i < m;i++) {
		if (a[i] + b[i] >= 10) {
			a[i] = (a[i] + b[i])%10;
			a[i+1]+=1;
			if (i+1 >= digit) {
				digit++;
			}
		}
		else {
			a[i]=a[i]+b[i];
		}
	}
}

int main() {
	int n,t = 0;
	scanf("%d",&n);
	int a[1000] = {0},b[1000] = {0};
	digit = fj(a,n);
	while(!hx(a,digit)) {
		t++;
		copy(a,b,digit);
		//printf("第%d次: ",t);
		display(a,digit);printf("+");display(b,digit);printf("=");
		add(a,b,digit);
		display(a,digit);printf("\n");
	}
	printf("%d",t);
	return 0;
}
