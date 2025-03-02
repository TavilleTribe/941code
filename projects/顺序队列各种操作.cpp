// 顺序队列（非环形队列）基本运算算法

#include <stdio.h>
#include <malloc.h>

#define MaxSize 100
typedef int ElemType;

typedef struct 
{	
    ElemType data[MaxSize];
    // 队头和队尾的标记位
    int front, rear;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue *&q)
{
    // 请补充下面的代码
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

// 销毁队列
void DestroyQueue(SqQueue *&q)			
{
    // 请补充下面的代码
    free(q);
}

// 判断队列是否为空
bool QueueEmpty(SqQueue *q)				
{
    // 请补充下面的代码
	return q->front == q->rear;
}

// 入队
bool enQueue(SqQueue *&q, ElemType e)		
{
    // 请补充下面的代码，请注意返回值
    // 需要判断队列是否已满
    if (q->rear == MaxSize-1) {
    	return false;
	}
	q->rear = q->rear + 1;
	q->data[q->rear] = e;
	return true;
}

// 出队
bool deQueue(SqQueue *&q, ElemType &e)	
{
    // 请补充下面的代码，请注意返回值
    // 需要判断队列是否为空
    if (QueueEmpty(q)) {
    	return false;
	}
	q->front = q->front + 1;
	e = q->data[q->front];
	return true;
}

int main()
{
    int n, num, e;
    char op;
	
    SqQueue * q;
	
    // 初始化队列
    InitQueue(q);
	
    scanf("%d", &n);
    getchar();
	
    // 从键盘输入 n 个操作，请注意判断操作类型
    // 同时请注意用 getchar() 吸引回车符
    // 请被下面 for 循环中的代码
    // 即输入数据，并根据操作的类型不同，进行入队与出队
    // 如果是入队，请将 num 入队
    // 如果是出队， 出队需要有个次数，该次数为 num
    
    for(int i = 0; i < n; i++)
    {
        // 请补充下面的代码
        scanf("%c %d",&op,&num);
        if (op == 'i') {
        	enQueue(q,num);
		}
		else if (op == 'o') {
			int time = num;
			for (int i = 0;i < time;i++) {
				deQueue(q,num);
			}
		}
        getchar();
    }
	
    // 出队列，并输出
    while(!QueueEmpty(q))
    {
        deQueue(q, e);
        // 这里的 e 为输出型参数
        printf("%d ", e);
    }
    return 0;
}
