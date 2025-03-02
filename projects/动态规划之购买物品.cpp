#include <stdio.h>

int value[25],cost[25];

int dp[25][30000];

int max(int x,int y) {
    return x > y ? x : y;
}

int solve(int n,int money) {
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= money;j++) {
            if (cost[i] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - cost[i]] + value[i]);
            }
        }
    }
    return dp[n][money];
}

int main() {
	int money,amount;
	scanf("%d %d",&money,&amount);
	
	int tempValue,tempCost;
	for (int i = 1;i <= amount;i++) {
		scanf("%d %d",&tempCost,&tempValue);
		value[i] = tempValue * tempCost,cost[i] = tempCost;
	}
	printf("%d",solve(amount,money));
}
