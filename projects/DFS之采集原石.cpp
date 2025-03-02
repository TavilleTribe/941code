#include <stdio.h>
#include <string.h>

int n,m,spawnx,spawny;
long long sum = 0;

int map[105][105];
int book[105][105] = {0};
int pos[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

int isBorder(int x,int y) {
    if (x < 1 || y < 1 || map[x][y] < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int isVisit(int x,int y) {
    return book[x][y] == 1;
}

void dfs(int x,int y) {
    for (int i = 0;i < 4;i++) {
        int cx = x+pos[i][0],cy = y+pos[i][1];
        if (!isBorder(cx,cy) && !isVisit(cx,cy)) {
            sum += map[cx][cy];
            book[cx][cy] = 1;
            dfs(cx,cy);
        }
    }
    return;
}

int main() {
	memset(map, -1, sizeof(map));
    scanf("%d %d",&n,&m);
    scanf("%d %d",&spawnx,&spawny);
    for (int i = 1;i <= n;i++) {
        for (int g = 1;g <= m;g++) {
            scanf("%d",&map[i][g]);
        }
    }
    if (map[spawnx][spawny] > 0) {
        sum += map[spawnx][spawny];
    }
    book[spawnx][spawny] = 1;
    dfs(spawnx,spawny);
    printf("%lld",sum);
}
