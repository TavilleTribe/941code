#include <stdio.h>
#include <string.h>

void buildNext(const char *pattern,int *next) {
	int j = 0,len = strlen(pattern);
	next[0] = 0;
	for (int i = 1;i < len;i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = next[j-1];
		}
		if (pattern[i] == pattern[j]) {
			j++;
		}
		next[i] = j;
	}
}

int kmpSearch(const char * text,const char * pattern) {
	int textLen = strlen(text),patternLen = strlen(pattern);
	int next[patternLen];
	buildNext(pattern,next);
	
	int j = 0;
	for (int i = 0;i < textLen;i++) {
		while (j > 0 && text[i] != pattern[j]) {
			j = next[j-1];
		}
		if (text[i] == pattern[j]) {
			j++;
		}
		if (j == patternLen) {
			return i - patternLen + 1;
		}
	}
	return -1;
}

int main() {
	const char *text = "ABABDABACDABABCABAB";
	const char *pattern = "ABABCABAB";
	int pos = kmpSearch(text,pattern);
	if (pos != -1) {
		printf("模式串在主串中的起始位置: %d\n",pos);
	}
	else {
		printf("未找到匹配\n");
	}
	return 0;
}

