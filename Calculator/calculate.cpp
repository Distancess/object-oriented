#include "Calculate.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

Calculate::Calculate()
{
	Error = false;
}

Calculate::~Calculate()
{
}

bool Calculate::iserror()
{
	return Error;
}
double Calculate::Calculater(string input)
{
	while (num.empty() == false)
		num.pop();
	Calculation c;
    stack<string> tmp2 = c.Getqueue(input);
    //初始化--------------------- 
    stringstream stream;
    double n, a, b;
    //---------------------------
    if (tmp2.empty() == false)
    {
        while (tmp2.empty() == false)
        {
        	if (tmp2.top() == "=")
        	{
				break;
        	}
            if (tmp2.top()[0] >= '0' && tmp2.top()[0] <= '9')
            {
                stream << tmp2.top();
                stream >> n;
                num.push(n);
                stream.clear();
                tmp2.pop();
            }
            else
            {
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                if (tmp2.top() == "+")
                {
                    num.push(b + a);
                    tmp2.pop();
                }
                else if (tmp2.top() == "-")
                {
                    num.push(b - a);
                    tmp2.pop();
                }
                else if (tmp2.top() == "*")
                {
                    num.push(a*b);
                    tmp2.pop();
                }
                else
                {
                 //除数为0时的处理 
                     if (a == 0)
                     {
                        Error = true;
                        num.push(0);
                        tmp2.pop();
                     }
                     else
                     {
                         num.push((double)b / a);
                         tmp2.pop();
                     }
                }
            }
        }
        
		return num.top();
    }
    else
    {
		return 0;
    }
}
