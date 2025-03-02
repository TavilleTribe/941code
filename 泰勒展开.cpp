#include <stdio.h>
#include <math.h> 

int main() {
	double x = 1.0 / sqrt(3.0);
	double zi = x,sum = 0,deno = 1,sign = 1,c = x;
	while(fabs(c) >= 1e-6) {
		sum += c;
		zi *= x*x;
		deno += 2;
		sign = -sign;
		c = (sign) * (zi / deno);
	}
	printf("%.10lf",6*sum);
}
