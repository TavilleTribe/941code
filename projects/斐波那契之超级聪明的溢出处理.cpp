#include <stdio.h>

int main() {
    int n,mod = 1000000,s = 0;
    scanf("%d",&n);
    long long int sum = 0,temp = 1;
    for (int i = 1;i <= n;i++) {
    	if (n >= 25) {
    		s = 1;
    		break;
		}
        temp = (temp * i) % mod;
        sum = (sum + temp) % mod;
    }
    if (s == 1) {
    	printf("%d",940313);
	}
	else {
		printf("%lld",sum);
	}
}
