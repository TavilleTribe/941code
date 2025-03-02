//
// Created by 19074 on 2025/3/2.
//
#include <stdio.h>

int time = 0;

void dfs(int current,int sum,int plate,int total,int totalPlate) {
    if(plate == totalPlate+1) {
        if (sum == total) {
            time++;
        }
        return;
    }
    for (int i = 0;i <= total;i++) {
        if (i >= current) {
            dfs(i,sum+i,plate+1,total,totalPlate);
        }
    }
    return;
}

int main() {
    int t;
    int M,N;
    int result[t];
    scanf("%d",&t);
    for (int i = 0;i < t;i++) {
        scanf("%d %d",&M,&N);
        dfs(0,0,1,M,N);
        result[i] = time;
        time = 0;
    }
    for (int i = 0;i < t;i++) {
        printf("%d",result[i]);
    }
}

