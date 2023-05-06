#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *fp;
    int cnt = 0; // 统计数
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // 统计单词
    {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            cnt ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词数=%d\n", cnt);
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt ++;
        printf("字符数=%d", cnt);
    }
    fclose(fp);
    return 0;
}


