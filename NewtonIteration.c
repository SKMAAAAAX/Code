/**
 * 牛顿迭代法求解三次方程根
 *
 * 本程序使用牛顿-拉夫森迭代法（Newton-Raphson method）求解三次方程 f(x) = ax³ + bx² + cx + d = 0 的一个实根。
 * 迭代公式：x_{n+1} = x_n - f(x_n)/f'(x_n)
 *
 * 程序流程：
 * 1. 输入方程系数 a, b, c, d
 * 2. 输入迭代初值 x₀
 * 3. 输入最大迭代次数
 * 4. 进行迭代计算并输出结果
 *
 * @author: SKMAAAAAX
 * @date: 2025-02-25
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 定义三次方程系数和迭代变量
double coefficientA, coefficientB, coefficientC, coefficientD, currentX;

/**
 * 清空输入缓冲区
 */
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * 计算牛顿迭代法中的 f(x)/f'(x) 值
 *
 * @param x 当前迭代点的x值
 * @return 函数值与导数值的比值
 */
double calculateDelta(double x)
{
    // 计算函数值 f(x) = ax³ + bx² + cx + d
    double functionValue = coefficientA * x * x * x + coefficientB * x * x + coefficientC * x + coefficientD;

    // 计算导数值 f'(x) = 3ax² + 2bx + c
    double derivativeValue = 3 * coefficientA * x * x + 2 * coefficientB * x + coefficientC;

    // 返回 f(x)/f'(x)，即迭代公式中需要减去的值
    return functionValue / derivativeValue;
}

int main()
{
    int iterationCount;
    int inputStatus;

    system("cls"); // 清屏，提供更好的用户体验

    // 输入方程系数
    printf("三次方程：f(x) = ax³+bx²+cx+d\n");

    while (1)
    {
        printf("输入 a, b, c, d 的值：");
        inputStatus = scanf("%lf %lf %lf %lf", &coefficientA, &coefficientB, &coefficientC, &coefficientD);
        clearInputBuffer(); // 清空输入缓冲区

        if (inputStatus == 4 && !(coefficientA == 0 && coefficientB == 0 &&
                                  coefficientC == 0 && coefficientD == 0))
        {
            break; // 输入有效
        }
        else
        {
            printf("输入有误，请重新输入！\n");
        }
    }

    // 输入初始迭代值
    while (1)
    {
        printf("起始 x= ");
        inputStatus = scanf("%lf", &currentX);
        clearInputBuffer(); // 清空输入缓冲区

        if (inputStatus == 1)
        {
            break; // 输入有效
        }
        else
        {
            printf("输入有误，请重新输入一个有效的实数！\n");
        }
    }

    // 输入最大迭代次数
    while (1)
    {
        printf("输入迭代次数：");
        inputStatus = scanf("%d", &iterationCount);
        clearInputBuffer(); // 清空输入缓冲区

        if (inputStatus == 1 && iterationCount >= 1)
        {
            break; // 输入有效
        }
        else
        {
            printf("输入有误，请重新输入一个正整数！\n");
        }
    }

    // 显示迭代结果表头
    system("cls");
    printf("迭代次数   迭代值\n");
    printf("--------------------\n");

    // 迭代计算过程
    for (int i = 0; i < iterationCount; i++)
    {
        double oldX = currentX; // 保存上一次迭代值，用于收敛判断

        // 核心迭代公式：x_{n+1} = x_n - f(x_n)/f'(x_n)
        currentX -= calculateDelta(currentX);

        // 收敛判断：当两次迭代结果非常接近或发散时停止
        if (fabs(currentX - oldX) <= 1e-12 || fabs(currentX) >= 1e15)
        {
            printf("迭代结束！\n");
            break;
        }
        printf("%-10d%-10lf\n", i + 1, currentX);
    }

    // 显示方程和计算结果
    printf("--------------------\n");
    printf("f(x) = %gx³ + %gx² + %gx + %g\n",
           coefficientA, coefficientB, coefficientC, coefficientD);

    // 验证解的精确度：将解代入原方程计算函数值，应接近0
    double finalFxValue = coefficientA * currentX * currentX * currentX +
                          coefficientB * currentX * currentX +
                          coefficientC * currentX +
                          coefficientD;

    // 如果函数值足够接近0，则认为找到了一个有效解
    if (fabs(finalFxValue) <= 1e-6)
    {
        printf("方程的一个根为：%.6lf\n", currentX);
    }
    else
    {
        printf("求解失败\n"); // 未能在指定迭代次数内找到足够精确的解
    }
    return 0;
}
