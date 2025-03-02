#include <stdio.h>
//正确做法（不超时，无错误） 
int main()
{
    int n;
    scanf("%d",&n);
    int sum = (1 + n) * n / 2;
    int x = 1;
    while (1)
    {
        int i = ((1 + x) * x / 2 - n) / 3;
        if ((1 + x) * x / 2 - 3 * i == n && i >= 1)
        {
            printf("%d %d",i,x);
            break;
        }
        x++;
    }
    return 0;
}


//部分对了但是有些错了 
/*
#include <stdio.h>

void getNum(int n) {
    int t = 1,sum = 0;
    while (sum <= n || (sum - n) % 3 != 0) {
        sum += t;
        t+=1;
    }
    printf("%d %d",(sum - n) / 3,t - 1);
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    getNum(n);
}
*/
