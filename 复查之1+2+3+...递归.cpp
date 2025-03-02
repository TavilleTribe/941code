#include <stdio.h>

int N(int n) {
    if (n == 0) {
        return 0;
    }
    return n + N(n - 1);
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d",N(n));
}
