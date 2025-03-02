#include <stdio.h>
#include <string.h>

int main()
{
	
	int find(char * str, char * strFind);
	void replace(char * str, char * strFind, char * strReplace);
	
	char str[101], strFind[101], strReplace[101];
	
	int findPos;
	
	// 输入原始字符串
	gets(str);
	
	// 输入要查找的字符串
	gets(strFind);
	
	// 输入要替换的字符串
	gets(strReplace);
	
	findPos = find(str, strFind);
	
	if(findPos != -1)
	{
	    // 输出查找到的位置
	    printf("%d\n", findPos);
	    // 进行替换操作，直接影响 str
		replace(str, strFind, strReplace);
		printf("%s", str);
	}
	else {
		printf("-1");
	}
	
	return 0;
}

// str 为原始字符串，strFind为要查找的字符串
// 返回值为strFind在str中的起始位置，如果不存在，请返回-1
// 注意：只查找第一次出现的位置
int find(char * str, char * strFind)
{
	// 请补充下面的代码
	int cmp,temp,strl = strlen(str),strf = strlen(strFind);
	for (int i = 0;i < strl;i++) {
		temp = i,cmp = 1;
		for (int k = 0;k < strf;k++) {
			if (i+strf >= strl) {
				return -1;
			}
			if (str[i+k] != strFind[k]) {
				cmp = 0;
				break;
			}
		}
		if (cmp == 1) {
			return temp;
		}
	}
	return -1;
}

// 替换操作，直接影响原始字符串 str
void replace(char * str, char * strFind, char * strReplace)
{
	// 请补充下面的代码
	int move = strlen(strReplace) - strlen(strFind),
	strl = strlen(str),
	strf = strlen(strFind),f = find(str,strFind),
	strr = strlen(strReplace);
	for (int i = strl;i >= strf+f;i--) {
		str[i+move] = str[i];
	}
	for (int i = 0;i < strr;i++) {
		str[f+i] = strReplace[i];
	}
}
