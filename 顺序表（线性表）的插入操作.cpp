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

bool ListInsert(SqList *&L,int i,ElemType e)
{
	if (i < 1||i > L->length+1) {
		return false;
	}
    for (int k = L->length-1;k >= i-1;k--) {
    	L->data[k+1] = L->data[k];
	}
	L->data[i-1] = e;
	L->length++;
	return true;
}



int main()
{
    int i, n, p, d;
    scanf("%d", &n);
    ElemType a[51];
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // 输入 p 与 d 的数据
	scanf("%d %d",&p,&d); 
    SqList *L;
    CreateList(L, a, n);
    // 插入数据
    ListInsert(L,p,d);
    DispList(L);
    return 0;
}
