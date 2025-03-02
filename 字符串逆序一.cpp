#include <stdio.h>
#include<string.h>

char str[85];

int len(char str[85]) {
	int l = 0;
	for (int i = 0;str[i] != '\0';i++) {
		l++;
	}
	return l;
}

int main() {
    gets(str);
    int p = len(str);
    //ע�ⳤ��p����Ȼ�����Wrong 
    for (int i = p - 1;i >= 0;i--) {
        printf("%c",str[i]);
    }

}

