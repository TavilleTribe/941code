#include <stdio.h>
#include <string.h>

char str[205];
char a[105];
char b[105];

void sendMatched(char s[205],char w[105],char r[105]) {
	int cl = 0;
	int wl = strlen(w);
	int rl = strlen(r);
	for (int i = 0;i < strlen(s);i++) {
		if (s[i] == w[cl]) {
			cl++;
			if (cl == wl && ((i - wl == -1 && s[i + 1] == ' ') || (s[i - wl] == ' ' && s[i + 1] == ' ') || (s[i - wl] == ' ' && i+1 == strlen(s)))) {
				cl = 0;
				for (int g = 0;g < wl;g++) {
					s[i - g] = '*';
				}
			}
		}
		else {
			cl = 0;
		}
	}
	cl = 0;
	for (int i = 0;i < strlen(s);i++) {
		if (s[i] == '*') {
			cl++;
			if (cl==wl) {
				cl = 0;
				for (int g = 0;g < rl;g++) {
					printf("%c",r[g]);
				}
			}
			continue;
		}
		printf("%c",s[i]);
	}
}

int main() {
    gets(str);
    gets(a);
    gets(b);
    sendMatched(str,a,b);
}
