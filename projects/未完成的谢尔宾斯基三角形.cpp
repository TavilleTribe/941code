#include <stdio.h>

int n;

void Sierpinski(int level,int blank,int s) {
    for (int i = 0;i < blank;i++) {
        printf(" ");
    }
    for (int l = 0;l < level;l++) {
    	for (int i = 0;i < s;i++) {
        	printf("* ");
    	}
    	if (l+1==level) {
    		continue;
		}
    	for (int b = 0;b < 8 - (s*2);b++) {
    		printf(" ");
		}
	}
    
    printf("\n");
    
    if (s == 4) {
    	if (level == n) {
        	return;
    	}
    	Sierpinski(level+1,blank-1,1);
	}
    else {
    	Sierpinski(level,blank-1,s+1);
	}
}

int main() {
    scanf("%d",&n);
    Sierpinski(1,3+(n-1)*4,1);
}
