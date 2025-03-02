#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,i,j,max;
    scanf("%d",&a);
    for(i=2;i<sqrt(a);i++){
        if(a%i==0){
            j=a/i;
            break;
        }
    }
    if(i>j){
        max=i;
    }
    else{
        max=j;
    }
    printf("%d",max);
    return 0;
}

