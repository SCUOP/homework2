#include "../head/Calculator.h"

//比较两个运算符的优先级
// op1>op2返回1,等于返回0,小于返回-1
int Calculator::CompareOp(char op1, char op2)
{
    if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
        return -1;
    if ((op2 == '+' || op2 == '-') && (op1 == '*' || op1 == '/'))
        return 1;
    if (op1 == '(' && op2 != '(')
        return -1;
    if (op1 != '(' && op2 == '(')
        return 1;

    return 0;
}