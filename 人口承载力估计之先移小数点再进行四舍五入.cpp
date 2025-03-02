#include <stdio.h>

int main() {
	double x,a,y,b,ans;
	double u;
	scanf("%lf %lf %lf %lf",&x,&a,&y,&b);
	ans = (b*y-a*x)/(b-a);
	u = (long int)(ans*100 + 0.5)/100;
	printf("%.2lf",u);
}
