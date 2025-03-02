#include <stdio.h>

int main()
{
    int a,b,n,c;
    scanf("%d %d %d", &a, &b, &n);
    if (a > b)
        a = a % b;
    for (int i = 1; i <= n; i++)
    {
        c = 10 * a / b;
        a = 10 * a - b * c;
    }
    printf("%d\n", c);
    return 0;
}
