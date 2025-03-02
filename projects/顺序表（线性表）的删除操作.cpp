#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;

typedef struct 
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[],int n)
{
    L = (SqList *)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

void DispList(SqList *L)
{
    for (int i = 0;i < L->length; i++)
        printf("%d ", L->data[i]);
}

bool ListDelete(SqList *&L,int i,ElemType &e)
{
    if (i < 1 || i > L->length) {
    	return false;
	}
	for (int k = i-1;k < L->length;k++) {
		L->data[k] = L->data[k+1];
	}
	L->length--;
	return true;
}

int main()
{
    int n,d,bd;
    scanf("%d",&n);
    ElemType a[51];
    for (int i = 0;i < n;i++) {
    	scanf("%d",&a[i]);
	}
	scanf("%d",&d);
	SqList *L;
	CreateList(L,a,n);
	ListDelete(L,d,bd);
    DispList(L);
    return 0;
}
