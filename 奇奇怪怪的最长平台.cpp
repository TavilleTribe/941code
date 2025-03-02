#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int array[n+1];
    array[n] = -1;
    for (int i = 0;i < n;i++) {
        scanf("%d",&array[i]);
    }
    int bplat = array[0];
    int bcounter = 1;
    int cplat = array[0];
    int counter = 1;
    for (int i = 0;i < n;i++) {
        if (array[i] == array[i+1] && cplat == array[i]) {
            counter += 1;
            if (counter > bcounter) {
                bcounter = counter;
                bplat = cplat;
            }
        }
        else {
            counter = 1;
            cplat = array[i + 1];
        }
    }
    printf("%d",bplat);
}
