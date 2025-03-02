#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

int main() {
	struct Node *head,*p,*q,*t;
	int i,n,a;
	scanf("%d",&n);
	head = NULL;
	for (i = 1;i <= n;i++) {
		scanf("%d",&a);
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = a;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}
		else {
			q->next = p;
		}
		q=p;
	}
	
	t = head;
	while (t!=NULL) {
		printf("%d",t->data);
		t=t->next;
	}
	
}
