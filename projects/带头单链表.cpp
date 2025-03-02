#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* initList() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (!head) {
        exit(1);
    }
    head->next = NULL;
    return head;
}

//头插法
void insertNodeHead(Node* head,int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = head->next;
	head->next = newNode;
} 

//尾插法 
void insertNode(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void deleteNode(Node* head, int data) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    if (head->next->data == data) {
        Node* temp = head->next;
        head->next = temp->next;
        free(temp);
        return;
    }
    Node* cur = head;
    while (cur->next != NULL && cur->next->data != data) {
        cur = cur->next;
    }
    if (cur->next == NULL) {
        return;
    }
    Node* temp = cur->next;
    cur->next = temp->next;
    free(temp);
}

//打印链表 
void traverseList(Node* head) {
    Node* cur = head->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    Node* head = initList();
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    traverseList(head); // 输出: 1 2 3 4

    deleteNode(head, 3);
    traverseList(head); // 输出: 1 2 4

    return 0;
}

