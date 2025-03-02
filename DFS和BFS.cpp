////DFS(深度优先搜索) 之全排序 
//#include <stdio.h>
//
//int a[10],book[10],n;
//
//void dfs(int step) {
//	int i;
//	if (step == n + 1) {
//		for (i = 1;i <= n;i++) {
//			printf("%d",a[i]);
//		}
//		printf("\n");
//		
//		return;
//	}
//	for (i = 1;i <= n;i++) {
//		if(book[i] == 0) {
//			printf("被填入时的i:%d\t",i); 
//			a[step] = i;
//			book[i] = 1;
//			printf("被调用的DFS的step:%d\n",step);
//			dfs(step+1);
//			printf("被回收的i:%d\n",i);
//			book[i] = 0;
//		}
//	}
//	return;
//}
//
//int main() {
//	scanf("%d",&n);
//	dfs(1);
//}

//BFS(广度优先搜索) 之走迷宫
#include <stdio.h>

struct note {
	int x;
	int y;
	int f;
	int s;
};

int main() {
	struct note que[2501];
	
	int a[51][51]= {0},book[51][51] = {0};
	
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	
	scanf("%d %d",&n,&m);
	for (i = 1;i<=n;i++) {
		for (j = 1;j<=m;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//队列初始化
	head = 1;
	tail = 1;
	que[tail].x=startx;
	que[tail].y=starty;
	que[tail].f=0;
	que[tail].s=0;
	tail++;
	book[startx][starty]=1;
	
	flag = 0;
	
	while (head < tail) {
		for (k = 0;k < 4;k++) {
			tx=que[head].x+next[k][0];
			ty=que[head].y+next[k][1];
			
			if (tx < 1||tx > n||ty < 1||ty > m) {
				continue;
			}
			if (a[tx][ty] == 0 && book[tx][ty] == 0) {
				book[tx][ty] = 1;
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				
				que[tail].s = que[head].s+1;
				tail++;
			}
			if (tx==p && ty==q) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
		head++;
	}
	printf("%d",que[tail-1].s);
	
}
