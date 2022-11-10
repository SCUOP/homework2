#include "../head/Calculator.h"

// 传入参数x,y,运算符op, 进行运算并返回运算结果
double Calculator::DoOperator(double x, char op, double y)
{
    if (op == '+')
        return x + y;
    if (op == '-')
        return x - y;
    if (op == '*')
        return x * y;
    if (op == '/')
        return x / y;
    return -1;
}