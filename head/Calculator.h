#include <stack>
#include <iostream>

class Calculator
{
public:
    void Run();

private:
    // int isp(char op);                               //栈内优先级
    // int icp(char op);                               //栈外优先级
    double answer;                                  //最终结果,初始值为0
    std::stack<double> OPND;                        //操作数栈
    std::stack<char> OPTR;                          //操作符栈
    int CompareOp(char op1, char op2);              //比较两个运算符的优先级
    double DoOperator(double x, char op, double y); //形成运算指令进行运算
    bool OperateNum(double num);                    //遇到运算数进行操作
    bool OperateOp(char op);                        //遇到某运算符进行的操作
};