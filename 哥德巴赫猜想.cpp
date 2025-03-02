//不够快 

/*
#include <stdio.h>
#include <math.h>

int main() {
	for (int i = 6;i <= 100;i+=2) {
		int done = 0,a1,a2,a3;
	    for (int g = 2; g <= i / 2; g++) {
	        int flag = 0;
	        for (int k1 = 2; k1 <= sqrt(g); k1++) {
	            if (g % k1 == 0) {
	                flag = 1;
	                break;
	            }
	        }
	        if (flag == 0) {
	            for (int g2 = i; g2 >= i / 2; g2--) {
	                flag = 0;
	                for (int k2 = 2; k2 <= sqrt(g2); k2++) {
	                    if (g2 % k2 == 0) {
	                        flag = 1;
	                        break;
	                    }
	                }
	                if (flag == 0 && g + g2 == i) {
	                    done = 1; a1 = i; a2 = g; a3 = g2;
	                    break;
	                }
	            }
	            if (done) {
	                printf("%d=%d+%d\n", a1, a2, a3);
	                break;
	            }
	        }
	    }
	}
}

*/
//比较快 

#include <stdio.h>
#include <math.h>

int prime(int n);    //函数声明，判断素数 

int main()
{
	int even;
	
	scanf("%d", &even);
	for (int i = 3; i <= even/2; i += 2)
		if (prime(i) && prime(even-i))
			printf("%d %d\n", i, even-i);
			
	return 0;
} 

// 判断素数，若是返回1，否则返回0 
int prime(int n)
{
	if (n == 1)
		return 0;
	
	int temp = (int)sqrt(n);
	for (int i = 2; i <= temp; i ++)
		if (n % i == 0)
			return 0;
	
	return 1;
}

