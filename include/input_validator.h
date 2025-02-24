#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 检查一个字符串是否为单个整数
static int isValidSingleInteger(const char *str)
{
    const unsigned char *s = (const unsigned char *)str;

    // 跳过前导空格
    while (isspace(*s))
        s++;
    if (*s == '\0')
        return 0; // 空字符串

    // 处理可选正负号
    if (*s == '+' || *s == '-')
        s++;

    // 必须至少有一个数字
    if (!isdigit(*s))
        return 0;

    // 跳过所有数字
    while (isdigit(*s))
        s++;

    // 跳过尾随空格
    while (isspace(*s))
        s++;

    // 必须恰好到字符串末尾才算合法
    return (*s == '\0');
}

// 获取指定范围内的有效整数
static int getValidInteger(int min, int max)
{
    char input[100];

    while (1)
    {
        // 如果遇到 EOF（例如按 Ctrl+D 或 Ctrl+Z），则退出程序
        if (!fgets(input, sizeof(input), stdin))
        {
            printf("\n退出程序...\n");
            exit(0);
        }

        // 去掉行尾换行符
        char *pos = strchr(input, '\n');
        if (pos)
            *pos = '\0';

        // 检查是否为单个整数
        if (!isValidSingleInteger(input))
        {
            printf("请输入单个整数（%d-%d）：", min, max);
            continue;
        }

        // 转换为 long，再检查范围
        long number = strtol(input, NULL, 10);
        if (number >= min && number <= max)
            return (int)number;

        printf("请输入在%d到%d之间的整数：", min, max);
    }
}

#endif // INPUT_VALIDATOR_H