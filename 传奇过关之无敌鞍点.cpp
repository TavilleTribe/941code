#include <stdio.h>

int main() {
    int arr[5][5];
    int flag = 1;
    for (int i = 0;i < 5;i++) {
        for (int g = 0;g < 5;g++) {
            scanf("%d",&arr[i][g]);
        }
    }
    for (int i = 0;i < 5;i++) {
        int max = arr[i][0],mp = 0;
        for (int g = 1;g < 5;g++) {
            if (arr[i][g] > max) {
                max = arr[i][g];
                mp = g;
            }
        }
        int min = max;
        for (int g2 = 0;g2 < 5;g2++) {
            if (arr[g2][mp] < min)  {
                min = arr[g2][mp];
                break;
            }
        }
        if (min == max) {
            printf("%d %d %d",i+1,mp+1,max);
            flag = 0;
            break;
            
        }
    }
    if (flag) {
        printf("not found");
    }
}
