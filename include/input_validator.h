#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

// 检查一个字符串是否为单个整数
static int isValidSingleInteger(const char *str)
{
    const unsigned char *s = (const unsigned char *)str;
    int hasDigits = 0;

    // 跳过前导空格
    while (isspace(*s))
        s++;
    if (*s == '\0')
        return 0;

    // 处理可选正负号
    if (*s == '+' || *s == '-')
        s++;

    // 检查并计数数字
    while (isdigit(*s))
    {
        hasDigits = 1;
        s++;
    }
    if (!hasDigits)
        return 0;

    // 跳过尾随空格
    while (isspace(*s))
        s++;
    return (*s == '\0');
}

// 获取指定范围内的有效整数
static int getValidInteger(int min, int max)
{
    char input[100];
    char *endptr;
    long number;

    while (1)
    {
        // EOF 检查
        if (!fgets(input, sizeof(input), stdin))
        {
            printf("\n检测到 EOF，程序退出\n");
            exit(0);
        }

        // 处理输入过长的情况
        if (!strchr(input, '\n') && !feof(stdin))
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("请重新输入: ");
            continue;
        }

        // 去掉换行符
        input[strcspn(input, "\n")] = '\0';

        // 检查输入是否为空或仅包含空格
        if (!isValidSingleInteger(input))
        {
            printf("请输入一个整数: ");
            continue;
        }

        // 转换为数字并进行错误处理
        errno = 0;
        number = strtol(input, &endptr, 10);

        // 检查转换错误和范围
        if (errno == ERANGE || number < min || number > max)
        {
            printf("请输入 %d-%d 之间的整数: ", min, max);
            continue;
        }

        return (int)number;
    }
}

#endif // INPUT_VALIDATOR_H