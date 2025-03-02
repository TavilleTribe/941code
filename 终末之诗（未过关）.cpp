#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char words[n][101];
	int wordsAlpha[n][26];
	int alphabet[26];
	int length[n];
	memset(wordsAlpha,0,sizeof(wordsAlpha));
	memset(alphabet,0,sizeof(alphabet));
	for (int i = 0;i < n;i++) {
		gets(words[i]);
		int l = strlen(words[i]);
		length[i] = l;
		for (int g = 0;g < l;g++) {
			int ascii = words[i][g];
			ascii -= 97;
			wordsAlpha[i][ascii]++;
			alphabet[ascii]++;
		}
	}
	int flag = 1;
	for (int i = 0;i < n;i++) {
		for (int g = 0;g < 26;g++) {
			if (length[i] == alphabet[g] && wordsAlpha[i][g] == 0) {
				flag = 0;
				printf("%s\n",words[i]);
				break;
			}
		}
	}
	if (flag) {
		printf("-1");
	}
}

