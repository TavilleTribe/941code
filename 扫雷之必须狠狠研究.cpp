#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                printf("%c", a[i][j]);
            } else {
                if (i - 1 >= 0 && j + 1 < m) {
                    if (a[i - 1][j + 1] == '*') {
                        sum++;
                    }
                }
                if (j + 1 < m) {
                    if (a[i][j + 1] == '*') {
                        sum++;
                    }
                }
                if (i - 1 >= 0) {
                    if (a[i - 1][j] == '*') {
                        sum++;
                    }
                }
                if (i + 1 < n && j - 1 >= 0) {
                    if (a[i + 1][j - 1] == '*') {
                        sum++;
                    }
                }
                if (i + 1 < n) {
                    if (a[i + 1][j] == '*') {
                        sum++;
                    }
                }
                if (j - 1 >= 0) {
                    if (a[i][j - 1] == '*') {
                        sum++;
                    }
                }
                if (i - 1 >= 0 && j - 1 >= 0) {
                    if (a[i - 1][j - 1] == '*') {
                        sum++;
                    }
                }
                if (i + 1 < n && j + 1 < m) {
                    if (a[i + 1][j + 1] == '*') {
                        sum++;
                    }
                }
                printf("%d", sum);
            }
            sum = 0;
        }
        printf("\n");
    }
    return 0;
}
