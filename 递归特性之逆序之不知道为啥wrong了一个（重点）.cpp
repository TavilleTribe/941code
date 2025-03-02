//失败的方法，最后一个wrong了，通过全局数组的方式存储然后逆序，不知道为什么错了 
/*
#include <stdio.h>

int arr[100];
int c = 0;

void initArray() {
	for (int i = 0;i < 100;i++) {
		arr[i] = -1;
	}
}

void getScale(int demical,int scale) {
	if (demical / scale != 0) {
		arr[c++] = demical % scale;
		getScale(demical / scale,scale);
	}
	else {
		arr[c] = demical % scale;
	}
}

int len(int a[100]) {
	int l = 0;
	for (int i = 0;a[i] != -1;i++) {
		l++;
	}
	return l;
}

char getHex(int demical) {
	return demical + 55;
}

int main() {
	int d,s;
	initArray(); 
	scanf("%d %d",&d,&s);
	getScale(d,s);
	for (int i = len(arr) - 1;i >= 0;i--) {
		if (arr[i] >= 10 && s == 16) {
			printf("%c",getHex(arr[i]));
		}
		else {
			printf("%d",arr[i]);
		}
	}
}

*/

//成功的方法，通过深度了解递归的原理，得知想要在递归中逆序，就要将输出放到最后，这样就会出现，每次递归结束后才会进行下一次递归，所以最里头的会最先输出！ 
#include <stdio.h>

char getHex(int demical) {
	return demical + 55;
}

//递归中的逆序输出法。后一次递归结束前前一次都会滞留在那一处，无法达到最后，以达成逆序输出的目的。 
void getScale(int demical,int scale) {
	if (demical / scale != 0) {
		getScale(demical / scale,scale);
	}
	else {
		;
	}
	if (demical % scale >= 10) {
		printf("%c",getHex(demical % scale));
	}
	else {
		printf("%d",demical % scale);
	}	
}

int main() {
	int d,s;
	scanf("%d %d",&d,&s);
	getScale(d,s);
}
