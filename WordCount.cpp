#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("error: missing parameter\n");
        return 1;
    }

    const char *filename = argc > 2 ? argv[2] : "input.txt";
    const char *param = argv[1];
    int count = 0;

    FILE *fp;
    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("error: unable to open file %s\n", filename);
        return 1;
    }

    char c;
    char last = '\0';
    if (strcmp(param, "-c") == 0) {
        while((c = fgetc(fp)) != EOF) {
            if (c != '\r') { // 不统计回车符
                count++;
            }
        }
        printf("字符数：%d\n", count);
    } else if (strcmp(param, "-w") == 0) {
        while((c = fgetc(fp)) != EOF) {
            if (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == '.') {
                // 遇到空格、制表符、换行符、逗号、句号，认为单词结束
                if (last != ' ' && last != '\t' && last != '\n' && last != ',' && last != '.') {
                    // 如果上一个字符不是空格、制表符、换行符、逗号、句号，则统计一个单词
                    count++;
                }
            }
            last = c;
        }
        printf("单词数：%d\n", count);
    } else {
        printf("error: invalid parameter\n");
        return 1;
    }

    fclose(fp);
    return 0;
}



