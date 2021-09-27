#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *ptr;
    ptr = "**yyds**!!!!!!!";
    printf("%s\n", ptr);

    char buf[50];
    //一共50个，写入6-1 + \0个字符
    int n = snprintf(buf, 6, "%s\n", ptr);
    //返回值为要写入的
    printf("string:\n%s\nthe size is: %lu.\nthe return count is %d.\n", buf, strlen(buf), n);

    char value[20];
    char tmp;
    while(1)
    {
        printf("pls. enter:\n");
        scanf("%s", value);
        printf("continue to enter ? (y)es / (n)o : ");
        fflush(stdin);  //清空缓冲区 gcc不太好用
        scanf(" %c", &tmp);  //前面加一个空格抵消上一次输入缓冲区残留的字符比如回车，scanf中空格即为读取停止字符并释放掉
        if('Y' != tmp && 'y' != tmp)
            break;
    }
    printf("string : %s\n", value);

    return 1;
}
