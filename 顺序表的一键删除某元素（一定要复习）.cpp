#include <stdio.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;

typedef struct 
{
    ElemType data[MaxSize];
    int length;
} SqList;

void CreateList(SqList *&L, ElemType a[], int n)
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

//相当于直接把那些重复的给顶掉了，把k作为索引，类似于重新安排了个数组 
void delnode1(SqList *&L, ElemType x)
{
    int k=0,i;
	for(i=0;i<L->length;i++) {
  		if(L->data[i]!=x)
  		{
   			L->data[k]=L->data[i];
   			k++;
  		}
	}
 	L->length=k;
}

int main()
{
    int n,e;
    scanf("%d",&n);
    ElemType a[51];
    for (int i = 0;i < n;i++) {
    	scanf("%d",&a[i]);
	}
	
	scanf("%d",&e);
	SqList *L;
	CreateList(L,a,n);
	delnode1(L,e);
    DispList(L);
    
    return 0;
}
