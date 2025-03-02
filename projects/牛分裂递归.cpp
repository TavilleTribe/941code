#include <stdio.h>

int split(int n,int k) {
    if ((n - k) % 2 != 0 || (n-k) <= 0) {
        return 1;
    }
    else {
        return split((n-k)/2,k)+split((n-k)/2+k,k);
    }
}

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",split(n,k));
}
