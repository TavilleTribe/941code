#include <stdio.h>
int main()
{
    int a,b;
    char c;
    scanf("%d %d %c",&a,&b,&c);
    if(b==90&&c=='m'){
        printf("%.2lf",a*6.95*0.95);
    }else if(b==90&&c=='e'){
        printf("%.2lf",a*6.95*0.97);
    }else if(b==93&&c=='m'){
        printf("%.2lf",a*7.44*0.95);
    }else if(b==93&&c=='e'){
        printf("%.2lf",a*7.44*0.97);
    }else if(b==97&&c=='m'){
        printf("%.2lf",a*7.93*0.95);
    }else if(b==97&&c=='e'){
        printf("%.2lf",a*7.93*0.97);
    }
}

#include <stdio.h>

int main() {
	double a,b;
	char m;
	double result,cost,discount;
	scanf("%lf %lf %c",&a,&b,&m);
	if (b == 90) {
		cost = 6.95;
	}
	else if (b == 93) {
		cost = 7.44;
	}
	else if (b == 97) {
		cost = 7.93;
	}
	if (m == 'm') {
		discount = 0.05;
	}
	else if (m == 'e') {
		discount = 0.03;
	}
	result = (a * cost) - (a * cost * discount);
	printf("%.2lf",result);
}
