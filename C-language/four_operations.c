#include <stdio.h>
double Calculator(char OPERATOR, double n1, double n2)
{
    if (OPERATOR == '+')
        return n1 + n2;
    else if (OPERATOR == '-')
        return n1 - n2;
    else if (OPERATOR == '*')
        return n1 * n2;
    else if (OPERATOR == '/')
        return n1 / n2;
}
int main()
{
    char OPERATOR;
    double x1, x2;
    printf("输入符号 \n");
    scanf_s("%c", &OPERATOR);
    printf("输入数x1 \n");
    scanf_s("%lf", &x1);
    printf("输入数x2 \n");
    scanf_s("%lf", &x2);
    printf("结果%lf \n", Calculator(OPERATOR, x1, x2));
    return 0;
}