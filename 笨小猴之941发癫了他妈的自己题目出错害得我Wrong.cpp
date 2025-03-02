#include <stdio.h>
#include <math.h>

int alphabet[26];

int isPrime(int num) {
    if (num == 0 || num == 1) {
        return 0;
    }
    for (int i = 2;i <= sqrt(num);i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int len(char str[105]) {
    int l = 0;
    for (int i = 0;str[i] != '\0';i++) {
        l++;
    }
    return l;
}

int getPlace(char c) {
	return c - 97;
}

int getDiff(char str[105]) {
    int length = len(str),max,min;
    for (int i = 0;i < len(str);i++) {
        alphabet[getPlace(str[i])]++;
    }
    max = 0;
    min = 105;
    for (int i = 0;i < 26;i++) {
    	if (alphabet[i] != 0) {
	    	if (alphabet[i] > max) {
	    		max = alphabet[i];
			}
			if (alphabet[i] < min) {
				min = alphabet[i];
			}
		}
	}
	return max-min;
}

int main() {
    char str[105];
    scanf("%s",str);
    int diff = getDiff(str);
    if (isPrime(diff)) {
    	printf("Lucky Word\n%d",diff);
	}
	else {
		printf("No Answer\n0");
	}
}
