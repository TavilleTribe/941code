#include <stdio.h>

int ain() {

    int n;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++) {

        scanf("%d", &a[i]);

    }

    int count = 1;

    int last = 1;

    for(int i = 0; i < n; i++) {

        if(a[i] == a[i+1]) {

            count++;

        }else {

            if(count > last) {

                last = count;

            }

            count = 1;

        }

    }

    printf("%d", last);



}
