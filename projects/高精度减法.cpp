//小程序版
#include <stdio.h>
#include <string.h>

char s[10100],ss[10100];
int a[10100],b[10100];
int len; 

/*-------------高精度减法--------------*/    
void jian()
{
    int l1 = strlen(s);    //字符串长度 
    int l2 = strlen(ss);
    int flag = 0;         //一个记录正负的变量（后面就知道啦） 

    memset(a,0,sizeof(a));       
    memset(b,0,sizeof(b));  

    if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )    //这个比较重要是来判断前后两数的大小的  
    {                                           //不然一个小的数减一个大的数是大于零的就尴尬了
        flag = 1; //这里是把正负记录下来  
        for (int i = l2 - 1 ; i >= 0 ; i--)    //倒过来输入 
            a[l2 - i - 1] = ss[i] - '0';      //将字符串里的字符转换为数字 
        for (int i = l1 - 1 ; i >= 0 ; i--)
            b[l1 - i - 1] = s[i] - '0';
    }
    else
    {
        for (int i = l1 - 1 ; i >= 0 ; i--)   //同理，倒过来输入 
            a[l1 - i - 1] = s[i] - '0';
        for (int i = l2 - 1 ; i >= 0 ; i--)
            b[l2 - i - 1] = ss[i] - '0';
    }
    if (l1 > l2) 
        len = l1;             //len赋值为其中大的数 
    else 
        len = l2; 
    for (int i = 0 ; i < len ; i++)
    {
        a[i] = a[i] - b[i];     //运算 
        if (a[i] < 0)          //如果减得多了 
        {
            a[i+1]-=1;         //向前要一位 
            a[i]+=10;          
        }
    }

    while (a[len - 1] == 0 && len>1) len--;   //while去零法，了解一下（名字现编的，别搜百度了） 
    if (flag == 1) printf("-");     //如果结果是负的，先输出一个负号 
    for (int i = len - 1 ;i >= 0 ;i--)   //再输出结果 
        printf("%d",a[i]);
    printf("\n");   //换行 
}                           //高精度减法你懂了吗？ 

void print()
{
	printf("高精度减法(By STY)\n\n");
    printf("退出请按“Ctrl+Z”(在键盘上)，并按回车，谢谢使用！\n"); 
    printf("请输入两个数字：\n");
    printf("数字：(用空格隔开)\n");
}

int main()
{
    print();
    while (scanf("%s%s",s,ss)!=EOF)
    {
        printf("\n结果：\n"); 
        jian();    //引用高精度减法函数
        printf("\n\n");
        print();
    }
    return 0;
}


