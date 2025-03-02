#include<stdio.h>
#include<math.h>
int main() {
    double a,
    b,
    c,
    t,
    x,
    y;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        t = b*b-4*a*c;
        if(a != 0 && t > 0) {
            x = 1.0*(-b+sqrt(t))/(2*a);
            y = 1.0*(-b-sqrt(t))/(2*a);
            printf("%.2f\n", x);
            printf("%.2f\n", y);
        }else if(a != 0 && t == 0) {
            x = (-b)/(2*a);
            printf("%.2f\n", x);
        }else if(a != 0 && t < 0) {
            x = 1.0*(-b)/(2*a);
            y = 1.0*sqrt(-t)/(2*a);
            if(x != 0) {
                printf("%.2f+%.2fi\n", x, y);
                printf("%.2f-%.2fi\n", x, y);
            }else {
                printf("0.00+%.2fi\n", y);
                printf("0.00-%.2fi\n", y);
            }
        }else if(a == 0 && b == 0 && c == 0) {
            printf("Zero Equation\n");
        }else if(a == 0 && b == 0 && c != 0) {
            printf("Not An Equation\n");
        }else {
            x = -1.0*(c/b);
            printf("%.2f\n", x);
        }
    }
    return 0;
}
