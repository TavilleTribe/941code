#include <stdio.h>

int main() {
    long long int a,b,c;
    while (scanf("%lld %lld %lld",&a,&b,&c) != EOF) {
        if (a > b && a > c) {
            if (b > c) {
                printf("%lld->%lld->%lld",c,b,a);
            }
            else if (b < c) {
                printf("%lld->%lld->%lld",b,c,a);
            }
        }
        else if (b > a && b > c) {
            if (a > c) {
                printf("%lld->%lld->%lld",c,a,b);
            }
            else if (a < c) {
                printf("%lld->%lld->%lld",a,c,b);
            }
        }
        else if (c > a && c > b) {
            if (a > b) {
                printf("%lld->%lld->%lld",b,a,c);
            }
            else if (a < b) {
                printf("%lld->%lld->%lld",a,b,c);
            }
        }
        printf("\n");
    }
}
