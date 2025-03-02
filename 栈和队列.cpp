#include <stdio.h>

struct quene {
	int data[101];
	int head;
	int tail;
}; 

struct stack {
	int data[101];
	int top;
};

int main() {
	struct stack s;
	s.top = 0;
	int length;
	scanf("%d",&length);
	for (int i = 0;i < length;i++) {
		scanf("%d",&s.data[i]);
	}
	for (int i = 0;i < length;i++) {
		printf("%d",s.data[i]);
		s.top=s.top+1;
	}
}
