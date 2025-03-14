#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 跨平台清屏函数
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void extractDigits(long long num, int digits[], int *count, int maxDigits)
{
    // 处理负数情况
    if (num < 0)
        num = -num;

    // 判断数字为0时的特殊情况
    if (num == 0)
    {
        digits[0] = 0;
        *count = 1;
        return;
    }

    // 计算数字长度并检查溢出
    long long temp = num;
    *count = 0;
    while (temp > 0)
    {
        (*count)++;
        temp /= 10;
    }
    // 填入每位数字
    for (int i = *count - 1; i >= 0 && num > 0; i--)
    {
        digits[i] = (int)(num % 10);
        num /= 10;
    }
}

int main(void)
{
    clearScreen();

#define MAX_DIGITS 20
    long long num;
    int count;
    char ch;
    int digits[MAX_DIGITS];

    printf("整数位数拆分程序\n");
    printf("==================\n");
    printf("输入一个整数 (支持范围：%lld 到 %lld)：", LLONG_MIN, LLONG_MAX);

    while (!(scanf("%lld%c", &num, &ch) == 2 && ch == '\n'))
    {
        printf("输入有误，请重新输入：");
        while (getchar() != '\n')
            ; 
    }
    clearScreen();
    // 提取并显示结果
    extractDigits(num, digits, &count, MAX_DIGITS);

    printf("\n数字 %lld 的拆分结果：\n", (num < 0) ? -num : num);

    if (num < 0)
        printf("负号 - \n");

    printf("位数：%d\n", count);
    printf("各位数字：");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", digits[i]);
    }
        return 0;
}
