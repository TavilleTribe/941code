#include<stdio.h>
int main()
{
	int money[13] = { 0 };
	for (int i = 1; i <= 12; i++)
		scanf("%d", &money[i]);
	int sum = 0;
	int n = 0;
	for (int i = 1; i <= 12; i++)
	{
		n += 300;
		n -= money[i];
		if (n < 0)
		{
			printf("-%d\n", i);
			return 0;
		}
		sum += n / 100 * 100;
		n %= 100;
	}
	sum = sum * 1.2 + n;
	printf("%d\n", sum);
	return 0;
}

#include <stdio.h>

int main() {
    int array[12];
    int x = -1,s = 0,c = 300;
    double final;
    for (int i = 0;i < 12;i++) {
        scanf("%d",&array[i]);
        if (x != -1) {
            continue;
        }
        if (c - array[i] < 0) {
            x = i + 1;
            continue;
        }
        if ((c - array[i]) % 100 == 0) {
            s += (c - array[i]);
            c -= (c - array[i]);
        }
        else if ((c - array[i]) / 100 != 0) {
            s += ((c - array[i]) / 100) * 100;
            c -= ((c - array[i]) / 100) * 100;
        }
        else {
            c = c - array[i] + 300;
        }
    }
    if (x == -1) {
        final = s * 1.2 + c;
        printf("%.0lf",final);
    }
    else {
        printf("-%d",x);
    }
}
