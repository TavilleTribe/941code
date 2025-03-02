#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    char array[n*m + n + 1];
    int output[n*m];
    int counter = 0;
    for (int i = 0;i < n*m + n + 1;i++) {
		scanf("%c",&array[i]);
    }

    for (int i = 1;i < n*m + n;i++) {
    	if (array[i] == '\n') {
    		continue;
		}
		if  (array[i] == '*') {
			output[counter] = -1;
			counter ++;
			continue;
		}
		int boom_counter = 0;
    	if (array[i - 1] == '\n') {
    		if (i - m <= 0) {
    			if (array[i + 1] == '*') {
    				boom_counter ++;
				}
				if (array[i + m + 1] == '*') {
					boom_counter ++;
				}
				if (array[i + m + 2] == '*') {
					boom_counter ++;
				} 
			}
			else if (i + m >= n*m + n) {
				if (array[i + 1] == '*') {
					boom_counter ++;
				}
				if (array[i - m] == '*') {
					boom_counter ++;
				}
				if (array[i - m - 1] == '*') {
					boom_counter ++;
				}
			}
			else {
				if (array[i + 1] == '*') {
					boom_counter ++;
				}
				if (array[i - m - 1] == '*') {
					boom_counter ++;
				}
				if (array[i - m] == '*') {
					boom_counter ++;
				}
				if (array[i + m + 1] == '*') {
					boom_counter ++;
				}
				if (array[i + m + 2] == '*') {
					boom_counter ++;
				}
			}
		}
		else if (array[i + 1] == '\n') {
			if (i + m >= n*m + n) {
				if (array[i - 1] == '*') {
					boom_counter ++;
				}
				if (array[i - m - 1] == '*') {
					boom_counter ++;
				}
				if (array[i - m - 2] == '*') {
					boom_counter ++;
				}
			}
			else if (i - m <= 0) {
				if (array[i - 1] == '*') {
					boom_counter ++;
				}
				if (array[i + m + 1] == '*') {
					boom_counter ++;
				}
				if (array[i + m] == '*') {
					boom_counter ++;
				}
			}
			else {
				if (array[i - 1] == '*') {
					boom_counter ++; 
				}
				if (array[i - m - 1] == '*') {
					boom_counter ++;
				}
				if (array[i - m - 2] == '*') {
					boom_counter ++;
				}
				if (array[i + m] == '*') {
					boom_counter ++;
				}
				if (array[i + m + 1] == '*') {
					boom_counter ++;
				}
			}
		}
		else if (i - m <= 0) {
			if (array[i - 1] == '*') {
				boom_counter ++;
			}
			if (array[i + 1] == '*') {
				boom_counter ++;
			}
			if (array[i + m] == '*') {
				boom_counter ++;
			}
			if (array[i + m + 1] == '*') {
				boom_counter ++;
			}
			if (array[i + m + 2] == '*') {
				boom_counter ++;
			}
		}
		else if (i + m >= n*m + n) {
			if (array[i - 1] == '*') {
				boom_counter ++;
			}
			if (array[i + 1] == '*') {
				boom_counter ++;
			}
			if (array[i - m - 2] == '*') {
				boom_counter ++;
			}
			if (array[i - m - 1] == '*') {
				boom_counter ++;
			}
			if (array[i - m] == '*') {
				boom_counter ++;
			}
		}
		else {
			if (array[i - 1] == '*') {
				boom_counter ++;
			}
			if (array[i + 1] == '*') {
				boom_counter ++;
			}
			if (array[i - m - 2] == '*') {
				boom_counter ++;
			}
			if (array[i - m - 1] == '*') {
				boom_counter ++;
			}
			if (array[i - m] == '*') {
				boom_counter ++;
			}
			if (array[i + m] == '*') {
				boom_counter ++;
			}
			if (array[i + m + 1] == '*') {
				boom_counter ++;
			}
			if (array[i + m + 2] == '*') {
				boom_counter ++;
			}
		}
		output[counter] = boom_counter;
		counter ++;
    }
    for (int i = 0;i < counter;i ++) {
    	if ((i + 1) % m == 0) {
    		if (output[i] == -1) {
    			printf("*\n");
			}
			else {
				if (i == counter - 1) {
					printf("%d",output[i]);
				}
				else {
					printf("%d\n",output[i]);
				}
			}
		}
		else {
			if (output[i] == -1) {
    			printf("*");
			}
			else {
				printf("%d",output[i]);
			}
		}
	}
}
