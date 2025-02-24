#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include "input_validator.h" // 使用双引号包含自定义头文件

// 生成指定范围内的随机整数
int Randomint(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int main(void)
{
    // 定义猜测结果的枚举类型
    enum GuessResult
    {
        TOO_BIG,
        TOO_SMALL
    } lastGuess;

    system("cls");
    srand(time(0)); // 初始化随机数种子

    // 选择游戏难度
    printf("\n1.简单(1-100)\n2.中等(1-500)\n3.困难(1-1000)\n选择难度：");
    int level, maxNum;
    // 从输入中获取有效的难度等级
    level = getValidInteger(1, 3);

    // 设置最大值范围
    switch (level)
    {
    case 1:
        maxNum = 100;
        break;
    case 2:
        maxNum = 500;
        break;
    case 3:
        maxNum = 1000;
        break;
    default:
        printf("输入错误！");
        return 1;
    }

    int realNum = Randomint(1, maxNum); // 生成目标数字
    int guessNum, times = 1;

    system("cls");
    printf("难度：1-%d\n", maxNum);
    printf("输入你猜的数字：");

    // 使用验证函数获取用户猜测
    guessNum = getValidInteger(1, maxNum);

    // 主游戏循环
    while (guessNum != realNum)
    {
        // 判断猜测结果并记录
        if (guessNum > realNum)
        {
            printf("猜大了\n");
            lastGuess = TOO_BIG;
        }
        else
        {
            printf("猜小了\n");
            lastGuess = TOO_SMALL;
        }

        Sleep(400); // 延时显示结果
        system("cls");
        times++;

        // 显示上次猜测结果
        printf("%d%s\n", guessNum, lastGuess == TOO_BIG ? "太大了" : "太小了");
        printf("输入你猜的数字：");

        guessNum = getValidInteger(1, maxNum);
    }

    // 游戏结束
    system("cls");
    printf("恭喜你猜对了！共猜了%d次\n", times);
    return 0;
}