#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 检查一个字符串是否为单个整数
static int isValidSingleInteger(const char *str)
{
    // 跳过前导空格
    while (isspace((unsigned char)*str))
        str++;
    if (*str == '\0')
        return 0; // 空字符串

    // 处理正负号
    if (*str == '+' || *str == '-')
        str++;

    if (!isdigit((unsigned char)*str))
        return 0;

    // 跳过所有数字
    while (isdigit((unsigned char)*str))
        str++;
    // 跳过尾随空格
    while (isspace((unsigned char)*str))
        str++;

    // 必须恰好到字符串末尾才算合法
    return (*str == '\0');
}

// 获取指定范围内的有效整数
static int getValidInteger(int min, int max)
{
    char input[100];
    long number;
    char *endptr;

    while (1)
    {
        // 如果遇到 EOF（例如按 Ctrl+D），则退出程序
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n退出程序...\n");
            exit(0);
        }

        // 去掉行尾换行符
        input[strcspn(input, "\n")] = '\0';

        if (!isValidSingleInteger(input))
        {
            printf("请输入单个整数（%d-%d）：", min, max);
            continue;
        }

        number = strtol(input, &endptr, 10);
        if (number >= min && number <= max)
            return (int)number;

        printf("请输入在%d到%d之间的整数：", min, max);
    }
}

#endif // INPUT_VALIDATOR_H