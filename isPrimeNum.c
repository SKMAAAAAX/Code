#include <stdio.h>
#include <stdlib.h>

// 定义数字类型枚举
enum TypeOfNum
{
    prime,      // 质数
    Composite   // 合数
};

// 判断一个数是否为质数
enum TypeOfNum isPrimeNum(long long int num)
{
    if (num % 2 == 0 || num % 3 == 0)
        return Composite;
    for (long long int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return Composite;
    }
    return prime;
}

int main()
{   system("cls");
    printf("1.判断单一数字是否为质数\n");
    printf("2.判断范围内的数字是否为质数\n");
    printf("输入选项(1或2)：");
    int option;
    while (scanf("%d", &option) != 1 || (option != 1 && option != 2))
    {
        system("cls");
        printf("输入有误!");
        printf("1.判断单一数字是否为质数\n");
        printf("2.判断范围内的数字是否为质数\n");
        printf("输入选项(1或2)：");
        while (getchar() != '\n')  // 清空输入缓冲区
            ;
    }
    if (option == 1)
    {
        system("cls");
        printf("输入一个自然数：");
        long long int num;

        // 输入验证：确保输入为有效的大于1的整数
        while (scanf("%lld", &num) != 1 || num <= 1)
        {
            system("cls");
            printf("输入有误，请重新输入一个有效的自然数：");
            while (getchar() != '\n') // 清空输入缓冲区
                ;
        }

        // 显示结果
        system("cls");
        printf("数字\"%lld\"是一个", num);

        // 根据判断结果输出不同信息
        switch (isPrimeNum(num))
        {
        case prime:
            printf("质数\n");
            break;
        case Composite:
            printf("合数\n");
            break;
        default:
            printf("错误\n");
            break;
        }
        return 0;
    }
    else{
        system("cls");
        printf("输入起始数字：");
        long long int start, end;

        // 输入验证：确保输入为有效的大于1的整数
        while (scanf("%lld", &start) != 1 || start <= 1)
        {
            system("cls");
            printf("输入有误，请重新输入一个有效的自然数：");
            while (getchar() != '\n') // 清空输入缓冲区
                ;
        }

        // 输入验证：确保输入为有效的大于起始数字的整数
        printf("输入结束数字：");
        while (scanf("%lld", &end) != 1 || end <= start)
        {
            system("cls");
            printf("输入有误，请重新输入一个有效的自然数：");
            while (getchar() != '\n') // 清空输入缓冲区
                ;
        }

        // 显示结果
        system("cls");
        printf("范围内的质数有：\n");

        for (long long int i = start; i <= end; i++)
        {
            if (isPrimeNum(i) == prime)
                printf("%lld\n", i);
        }
    }
    
}