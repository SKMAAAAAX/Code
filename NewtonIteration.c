#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// 三次方程系数、迭代变量
double coefficientA, coefficientB, coefficientC, coefficientD, currentX;

/**
 * 计算 f(x)/f'(x)
 */
double calculateDelta(double x)
{
    double functionValue = coefficientA * x * x * x + coefficientB * x * x + coefficientC * x + coefficientD;
    double derivativeValue = 3 * coefficientA * x * x + 2 * coefficientB * x + coefficientC;
    return functionValue / derivativeValue;
}

int main()
{
    int iterationCount;
    system("cls");

    // 输入方程系数
    printf("三次方程：f(x) = ax³+bx²+cx+d\n");
    printf("输入 a, b, c, d 的值：");
    if (scanf("%lf %lf %lf %lf", &coefficientA, &coefficientB, &coefficientC, &coefficientD) != 4 || (!coefficientA && !coefficientB && !coefficientC && !coefficientD))
    {
        printf("输入有误\n");
        return 0;
    }

    // 输入起始 x
    printf("起始 x= ");
    if (scanf("%lf", &currentX) != 1)
    {
        printf("输入有误\n");
        return 0;
    }

    // 输入迭代次数
    printf("输入迭代次数：");
    if (scanf("%d", &iterationCount) != 1 || iterationCount < 1)
    {
        printf("输入有误\n");
        return 0;
    }

    system("cls");
    printf("迭代次数   迭代值\n");
    printf("--------------------\n");

    // 迭代过程
    for (int i = 0; i < iterationCount; i++)
    {
        double oldX = currentX;
        currentX -= calculateDelta(currentX);
        if (fabs(currentX - oldX) <= 1e-12 || fabs(currentX) >= 1e15)
        {
            printf("迭代结束！\n");
            break;
        }
        printf("%-10d%-10lf\n", i + 1, currentX);
    }

    printf("--------------------\n");
    printf("f(x) = %gx³ + %gx² + %gx + %g\n",
           coefficientA, coefficientB, coefficientC, coefficientD);

    double finalFxValue = coefficientA * currentX * currentX * currentX + coefficientB * currentX * currentX + coefficientC * currentX + coefficientD;
    if (fabs(finalFxValue) <= 1e-6)
    {
        printf("方程的一个根为：%.6lf\n", currentX);
    }
    else
    {
        printf("迭代失败\n");
    }
    return 0;
}
