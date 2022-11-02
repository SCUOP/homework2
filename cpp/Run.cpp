#include "../head/Calculator.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

//运行函数
void Calculator::Run()
{
    std::cout << "Eg:\n((2+3)*4-(8+2))/5\n(-3)/(+2)\nPls notice the '()' to express the negative expression exactly \nsuch as (-(a+b)) to express the negative of the expression 'a+b'" << std::endl;
    while (true)
    {
        std::stack<double>().swap(OPND);
        std::stack<char>().swap(OPTR);
        answer = 0;
        std::string expression; //输入
        std::getline(std::cin, expression);
        expression.erase(std::remove(expression.begin(), expression.end(), ' '), expression.end()); //处理为无空格表达式
        int i = -1;
        int begin = 0;
        int end = 0;
        bool flag = true; //判断是否正确正常输入运行
        while (++i <= expression.length())
        {
            if (i != expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                ++end;
            }
            else
            {
                if ((expression[i] == '-' || expression[i] == '+') && (i == 0 || std::string("+-/*(").find(expression[i - 1]) != std::string::npos))
                {
                    flag = OperateNum(0);
                }
                if (i > 0 && isdigit(expression[i - 1]))
                    ++end;
                std::string numString = expression.substr(begin, end - begin); //提取数字字符串
                begin = i + 1;
                end = begin;
                if (!numString.empty())
                {
                    double num = std::stod(numString); //提取数字
                    flag = OperateNum(num);
                }
                if (i != expression.length())
                    flag = OperateOp(expression[i]);
            }
            if (!flag)
            {
                std::cout << "Input error, pls check your express and reload the express" << std::endl;
                break;
            }
        }
        if (flag)
        {
            if (OperateOp(' '))
                std::cout << "The answer: " << answer << std::endl;
            else
                std::cout << "Input error, pls check your express and reload the express" << std::endl;
        }
    }
}