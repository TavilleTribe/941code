#include <stdio.h>

void move(char x,char y) {
    printf("Move %c to %c\n",x,y);
}
//重点，递归 
int hanoit(unsigned int x) {
 
	if (x > 1) {	
		return 2 * hanoit(x - 1) + 1;
	}
	else if(1 == x) {//递归的最后一层，也就是1 == x
	
		return 1;
	}
	else {//输入0层，代码要健壮
		return 0;
	}
 
}

void hanoi(int n,char one,char two,char three) {
    if (n==1) {
        move(one,three);
    }
    else {
        hanoi(n-1,one,three,two);
        move(one,three);
        hanoi(n-1,two,one,three);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",hanoit(n));
    hanoi(n,'A','B','C');
}
