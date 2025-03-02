#include <stdio.h>
#include <string.h>

int main() {
	char words[105];
	int index=0;
	while((scanf("%c",&words[index]))==1 && words[index]!='.')
	{
		index++;
	}
	int length = strlen(words) - 1,lp,rp;
	if (length % 2 == 0) {
		lp = length / 2 - 1;rp = length / 2;
		while (lp >= 0 && rp < length) {
			if (words[lp] != words[rp]) {
				printf("No");
				return 0;
			}
			lp --;rp ++;
		}
		printf("Yes");
	}
	else {
		lp = length / 2 - 1;rp = length / 2 + 1;
		while (lp >= 0 && rp < length) {
			if (words[lp] != words[rp]) {
				printf("No");
				return 0;
			}
			lp --;rp ++;
		}
		printf("Yes");
	}
}

//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//int main()
//{
//	char str[103];
//	int index=0;
//	while((scanf("%c",&str[index]))==1 && str[index]!='.')
//	{
//		index++;
//	}
//	//str[index]='\0';
//	int length=strlen(str);
//	
//	
//	int flag=1;
//	
//	for(int i=0;i<length/2;i++)
//	{
//		if(str[i]!=str[length-i-1])
//		{
//			flag=0;
//		}
//	}
//	if(flag)
//	{
//		printf("Yes");
//	}
//	else
//	{
//		printf("No");
//	}
//	return 0;
//}
