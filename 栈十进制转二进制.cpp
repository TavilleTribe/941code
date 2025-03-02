#include <stdio.h>

int isUnique(int num) {
    int arr[18],t = 0;
    while (num > 0) {
        arr[t++] = num % 2;
        num /= 2;
    }
    for (int i = t - 1;i >= t / 2;i--) {
        if (arr[i] != arr[t - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n,t;
    scanf("%d",n);
    for (int i = 1;i <= n;i++) {
        if (isUnique(i)) {
            t++;
        }
    }
    printf("%d",t);
}
