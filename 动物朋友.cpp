#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int left = 0, right = 0;
    long long currentSum = 0;
    int count = 0;

    while (right < n) {
        currentSum += a[right]; // 扩大窗口
        while (currentSum > m && left <= right) {
            currentSum -= a[left]; // 缩小窗口
            left++;
        }
        if (currentSum == m) {
            count++; // 找到满足条件的窗口
        }
        right++;
    }

    printf("%d\n", count);

    free(a);
    return 0;
}
