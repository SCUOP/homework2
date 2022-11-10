#include "../head/Calculator.h"

//遇到运算符进行操作
//操作成功返回true
//不成功返回false
//输入op为' '空格时，弹出符号栈内所有元素并运算
//并将运算后数字栈内剩余元素赋值给answer
//若计算失败返回false
bool Calculator::OperateOp(char op)
{
    std::cout << op << std::endl;
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != ' ' && op != '(' && op != ')')
    {
        return false;
    }
    else if (op == ' ') //读取完
    {
        while (!OPTR.empty())
        {
            char tempOp = OPTR.top();
            OPTR.pop(); //弹出栈顶操作符存入temOp
            double tempNum1 = OPND.top();
            OPND.pop();
            double tempNum2 = OPND.top();
            OPND.pop();
            double tempAns = DoOperator(tempNum1, tempOp, tempNum2);
            OPND.push(tempAns);
        }
        answer = OPND.top();
        OPND.pop();
        return true;
    }
    else if (OPTR.empty()) //符号栈空
    {
        OPTR.push(op);
    }
    else
    {
        char topOp = OPTR.top();
        int flag = CompareOp(op, topOp);
        if (op == ')')
        {
            while (topOp != '(')
            {
                double tempNum1 = OPND.top();
                OPND.pop();
                double tempNum2 = OPND.top();
                OPND.pop();
                double tempAns = DoOperator(tempNum1, topOp, tempNum2);
                OPND.push(tempAns);
                OPTR.pop();
                topOp = OPTR.top();
            }
            OPTR.pop();
        }
        else if (flag == 0 || flag == 1)
        {
            OPTR.push(op);
        }
        else if (flag == -1)
        {
            char tempOp = OPTR.top();
            OPTR.pop();
            double tempNum1 = OPND.top();
            OPND.pop();
            double tempNum2 = OPND.top();
            OPND.pop();
            double tempAns = DoOperator(tempNum1, tempOp, tempNum2);
            OPND.push(tempAns);
        }
    }
    return true;
}