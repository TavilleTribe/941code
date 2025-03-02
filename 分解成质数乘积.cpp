#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int switcher = 0;
    for (int i = 2;i <= n / 2;i++) {
        if (n % i == 0) {
            switcher = 1;
            break;
        }
    }
    if (switcher == 0) {
        printf("%d=%d",n,n);
    }
    else {
        int counter = 0;
        int record = -1;
        int current = n;
        for (int i = 2;i <= current + 1;i++) {
            if (record != -1) {
                i = record;
            }
            if (current % i == 0) {
                current = current / i;
                counter ++;
                record = i;
            }
            else {
                record = -1;
            }
        }
        record = -1;
        current = n;
        int array[counter + 1];
        int c = 0;
        for (int i = 2;i <= current + 1;i++) {
            if (record != -1) {
                i = record;
            }
            if (current % i == 0) {
                current = current / i;
                array[c] = i;
                c ++;
                record = i;
            }
            else {
                record = -1;
            }
        }
        array[counter] = -1;
        printf("%d=",n);
        int mult = 1;
        if (array[0] == array[1]) {
        	mult ++;
		}
		else {
			printf("%d*",array[0]);
		}
        for (int i = 1;i < counter;i++) {
			if (array[i] != array[i - 1] && array[i] != array[i + 1]) {
				if (mult == 1) {
					if (array[i + 1] == -1) {
						printf("%d",array[i]);
					}
					else {
						printf("%d*",array[i]);
					}
				}
				else {
					if (array[i + 1] == -1) {
						printf("%d^%d",array[i],mult);
					}
					else {
						printf("%d^%d*",array[i],mult);
					}
					mult = 1;
				}
			}
			else if (array[i] == array[i - 1] && array[i] != array[i + 1]) {
				if (mult == 1) {
					if (array[i + 1] == -1) {
						printf("%d",array[i]);
					}
					else {
						printf("%d*",array[i]);
					}
				}
				else {
					if (array[i + 1] == -1) {
						printf("%d^%d",array[i],mult);
					}
					else {
						printf("%d^%d*",array[i],mult);
					}
					mult = 1;
				}
			}
			else {
				mult ++;
			}
		}
    }
    return 0;
}
