#include <stdio.h>
#include <string.h>

int value[1005],volume[1005];
//价值和体积

int dp[1005][10005];
//动态规划二维数组 

int max(int a,int b) {
	return a > b?a : b;
}

int solve(int n,int C) {
	for (int i = 1;i <= n;i++) {
		//共n个物品，遍历每个（表格在下面） 
		for (int j = 0;j <= C;j++) {
			//容量最大为C，每一个物品每一个容量都进行遍历
			if (volume[i] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-volume[i]] + value[i]);
			}
		}
	}
	return dp[n][C];
}

int main() {
	int n,C;
	scanf("%d %d",&n,&C);
	for (int i = 1;i <= n;i++) {
		scanf("%d %d",&volume[i],&value[i]);
	}
	memset(dp,0,sizeof(dp));
	printf("%d",solve(n,C));
}

