#include<stdio.h>

//利用队列先入先出的特性，把内存当成队列来用
int queue[100000];
//队首索引
int begin;
//队尾索引
int end;

//入队
void EnQueue(int elem)
{
	queue[end++] = elem;
}

//出队
int DeQueue()
{
	return queue[begin++];
}

//队列查询
int Query(int elem)
{
	for(int i=begin;i<end;i++)
	{
		if(queue[i]==elem) return 1;
	}
	return 0;
}

int main()
{
	
	begin = end = 0;
	
	// m 内存容量  n 文章长度
	int m,n,num,find_count = 0;
	//scanf("%d%d",&m,&n);
	m = 3,n = 7;
	int arr[n] = {1,2,1,3,1,5,6};
	for(int i=0;i<n;i++)
	{
		num = arr[i];
		//scanf("%d",&num);
		//如果在内存查不到，外存词典查找次数加一，新元素入队
		if(!Query(num))
		{
			find_count++;
			EnQueue(num);
			//超过内存容量，队首出队
			if(end-begin==m)
				DeQueue();
		}
	}
	printf("%d",find_count);
	return 0;
}
