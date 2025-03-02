#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    for (int i = 2;i <= sqrt(num);i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int getDigit(int num) {
    int t = 0;
    while (num != 0) {
        num /= 10;
        t++;
    }
    return t;
}

int getRev(int num) {
    int digit = getDigit(num),mult,sum = 0;
    int rnum[digit];
    mult = pow(10,digit);
    for (int i = 0;i < digit;i++) {
        rnum[i] = num % 10;
        num /= 10;
    }
    for (int i = 0;i < digit;i++) {
        mult /= 10;
        sum += (rnum[i] * mult);
    }
    return sum;
}

int main() {
	int M,N,flag = 1;
	scanf("%d %d",&M,&N);
	for (int i = M;i<=N;i++) {
		if (isPrime(i) && isPrime(getRev(i))) {
			//注意这个位置，flag的用处不止用于最后的判断，也可以作为判断第一个真素数出现的时机。这时只输出%d而不输出逗号。 
			if (flag == 1) {
				flag = 0;
				printf("%d",i)
			}
			//后面flag不是1，那就要输出逗号了，聪明 
			else {
				printf(",%d",i);
			}
		}
	}
	if (flag) {
		printf("No\n");
	}
}


