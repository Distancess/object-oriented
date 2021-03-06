#include "stdafx.h"
#include "Calculation.h"
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

Calculation::Calculation()
{
}


Calculation::~Calculation()
{
}

//------------------------------------------------------
stack<string> Calculation::Getqueue(string input)
{
    while (rpn.empty() == false)
        rpn.pop();
    while (opr.empty() == false)
        opr.pop();
    while (sign.empty() == false)
        sign.pop();
    //初始化-------------------------------------- 
    int mark[50];
    mark['+'] = 1;
    mark['-'] = 1;
    mark['*'] = 2;
    mark['/'] = 2;
    mark[')'] = 3;
    mark['('] = 4;
    Scanner s1;
    queue<string> tmp1 = s1.ToStringQueue(input);
    //-------------------------------------------- 
    //1.中缀转后缀---------------------------------
    if (s1.IsError() == false)
    {
        if (tmp1.front() == "-" || tmp1.front() == "+")
        {
            opr.push("0");
        }
        if (tmp1.front() == "*" || tmp1.front() == "/")
        {
            opr.push("1");
        }
        while (tmp1.empty() == false)
        {
            //---1.处理操作数
            if (tmp1.front()[0] >= '0' && tmp1.front()[0] <= '9')
            {
                opr.push(tmp1.front());
                tmp1.pop();
            }
            //---2.处理运算符
            else
            {
                if (sign.empty() == true || (sign.top() == "(" && tmp1.front() != ")"))
                {
                    sign.push(tmp1.front());
                    tmp1.pop();
                    continue;
                }

                //运算符栈非空
                //----1.判断括号的匹配 
                if (tmp1.front() == ")")
                {
                    while (sign.top() != "(")
                    {
                        opr.push(sign.top());
                        sign.pop();
                    }
                    tmp1.pop();
                    sign.pop();
                }
                //----2.判断优先级
                else
                {

                    for (; sign.empty() == false && sign.top() != "("
                        && (mark[tmp1.front()[0]] <= mark[sign.top()[0]]); )
                    {
                        opr.push(sign.top());
                        sign.pop();
                    }
                    sign.push(tmp1.front());
                    tmp1.pop();
                }
            }
        }
        //----3.处理剩余的运算符 
        while (sign.empty() == false)
        {
            if (sign.top() == "(" || sign.top() == ")")
            {
                sign.pop();
            }
            else
            {
                opr.push(sign.top());
                sign.pop();
            }
        }

        while (opr.empty() == false)
        {
            rpn.push(opr.top());
            opr.pop();
        }
    }

    return rpn;
}


