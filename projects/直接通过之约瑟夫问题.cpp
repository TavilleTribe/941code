#include <stdio.h>

int main() {
    int N,M,flag = 0,c = 1,t = 0;
    scanf("%d %d",&N,&M);
    int arr[N];
    for (int i = 0;i < N;i++) {
    	arr[i] = 0;
	}
    int out[N];
    while (flag != 1) {
        for (int i = 0;i < N;i++) {
        	if (arr[i] == -1) {
        		continue;
			}
            if (c == M) {
                c = 1;
                arr[i] = -1;
                out[t] = i + 1;
                t++;
                if (t == N) {
                    flag = 1;
                    break;
                }
                continue;
            }
            arr[i] = c;
            c++;
        }
    }
    for (int i = 0;i < N;i++) {
        printf("%d ",out[i]);
    }
}
