//
// Created by 19074 on 2025/3/2.
//
#include <stdio.h>

int time = 0;

void dfs(int current,int sum,int step,int total,int totalStep) {
    if(step == totalStep) {
        if (total - sum >= current) {
            time++;
        }
        return;
    }
    for (int i = current;i <= total-(step-1);i++) {
        if (i >= current) {
            dfs(i,sum+i,step+1,total,totalStep);
            if (total - (sum+i) < current) {
            	break;
			}
        }
    }
    return;
}

int main() {
    int M,N;
    scanf("%d %d",&M,&N);
    dfs(1,0,1,M,N);
	printf("%d",time);
}

