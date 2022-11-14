#include "../head/Calculator.h"
#include "assert.h"
//遇到运算符进行操作
//操作成功返回true
//不成功返回false
//输入op为' '空格时，弹出符号栈内所有元素并运算
//并将运算后数字栈内剩余元素赋值给answer
//若计算失败返回false
bool Calculator::OperateOp(char op)
{
    if (op == ' ') //读取完
    {
        while (!OPTR.empty())
        {
            if (OPND.empty())
            {
                return false;
            }
            try
            {
                char tempOp = OPTR.top();
                OPTR.pop(); //弹出栈顶操作符存入temOp
                double tempNum1 = OPND.top();
                OPND.pop();
                if (OPND.empty())
                {
                    return false;
                }
                double tempNum2 = OPND.top();
                OPND.pop();
                double tempAns = DoOperator(tempNum2, tempOp, tempNum1);
                OPND.push(tempAns);
            }
            catch (...)
            {
                return false;
            }
        }
        if (OPND.empty())
        {
            return false;
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
                if (OPND.empty())
                {
                    return false;
                }
                try
                {
                    double tempNum1 = OPND.top();
                    OPND.pop();
                    double tempNum2 = OPND.top();
                    OPND.pop();
                    double tempAns = DoOperator(tempNum2, topOp, tempNum1);
                    OPND.push(tempAns);
                    OPTR.pop();
                    if (OPTR.empty())
                    {
                        return false;
                    }
                    topOp = OPTR.top();
                }
                catch (...)
                {
                    return false;
                }
            }
            OPTR.pop();
        }
        else if (op == '(')
        {
            OPTR.push(op);
        }
        else if (flag == 1)
        {
            OPTR.push(op);
        }
        else if (flag == -1 || flag == 0)
        {
            while (!OPTR.empty() && CompareOp(op, OPTR.top()) < 1)
            {
                if (OPND.empty())
                {
                    return false;
                }
                try
                {
                    topOp = OPTR.top();
                    OPTR.pop();
                    if (OPND.empty())
                    {
                        return false;
                    }
                    double tempNum1 = OPND.top();
                    OPND.pop();
                    if (OPND.empty())
                    {
                        return false;
                    }
                    double tempNum2 = OPND.top();
                    OPND.pop();
                    if (OPND.empty())
                    {
                        return false;
                    }
                    double tempAns = DoOperator(tempNum2, topOp, tempNum1);
                    OPND.push(tempAns);
                }
                catch (...)
                {
                    return false;
                }
            }
            OPTR.push(op);
        }
    }
    return true;
}