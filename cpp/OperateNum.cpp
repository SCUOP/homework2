#include "../head/Calculator.h"

//遇到运算数进行操作
//操作成功返回true
//不成功返回false
bool Calculator::OperateNum(double num)
{
    std::cout << num << std::endl;
    try
    {
        OPND.push(num);
        return true;
    }
    catch (...)
    {
        return false;
    }
}