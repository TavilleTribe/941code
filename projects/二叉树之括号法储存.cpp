#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
} TreeNode;

typedef struct Stack{
	TreeNode *datas[105];
	int top;
} Stack;

void preOrderPrint(TreeNode *root) {
	if(root != NULL) {
		printf("%c ",root->data);
		preOrderPrint(root->lchild);
		preOrderPrint(root->rchild);
	}
} 

void inOrderPrint(TreeNode *root) {
	if(root != NULL) {
		inOrderPrint(root->lchild);
		printf("%c ",root->data);
		inOrderPrint(root->rchild);
	}
}

void postOrderPrint(TreeNode *root) {
	if(root != NULL) {
		postOrderPrint(root->lchild);
		postOrderPrint(root->rchild);
		printf("%c ",root->data);
	}
}

//void BTreePrint(TreeNode *root) {
//	if(root != NULL) {
//		printf("%c",root->data);
//		if(root->lchild!=NULL || root->rchild!=NULL) {
//			printf("(");
//			BTreePrint(root->lchild);
//			if(root->rchild!=NULL) {
//				printf(",");
//			}
//			BTreePrint(root->rchild);
//			printf(")");
//		}
//	} 
//}

int main() {
	//≥ı ºªØ’ª
	Stack s;
	s.top = 0;
	
	char input[105];
	scanf("%s",input);
	int length = strlen(input);
	
	int flag = 0;
	TreeNode *st = NULL;
	TreeNode *newNode = NULL;
	
	for (int i = 0;i < length;i++) {
		if (input[i] >= 65 && input[i] <= 90) {
			if (flag == 0) {
				st = (TreeNode*)malloc(sizeof(TreeNode));
				st->data = input[i];
				st->lchild = NULL;
				st->rchild = NULL;
			}
			else if (flag == 1) {
				newNode = (TreeNode*)malloc(sizeof(TreeNode));
				newNode->data = input[i];
				newNode->lchild = NULL;
				newNode->rchild = NULL;
				s.datas[s.top]->lchild = newNode;
				st = newNode;
			}
			else if (flag == 2) {
				newNode = (TreeNode*)malloc(sizeof(TreeNode));
				newNode->data = input[i];
				newNode->lchild = NULL;
				newNode->rchild = NULL;
				s.datas[s.top]->rchild = newNode;
				st = newNode;
			}
		}
		else {
			if (input[i] == '(') {
				flag = 1;
				s.datas[++s.top] = st;
			}
			else if (input[i] == ',') {
				flag = 2;
			}
			else if (input[i] == ')') {
				st = s.datas[s.top];
				s.top--;
			}
		}
	}
	//BTreePrint(st);
	preOrderPrint(st);
	printf("\n");
	inOrderPrint(st);
	printf("\n");
	postOrderPrint(st);
	free(newNode);
	free(st);
}

