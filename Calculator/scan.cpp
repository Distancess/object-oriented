#include "scan.h"
#include <iostream>
#include <queue>

using namespace std;

Scan::Scan()
{
	error = false;
}

Scan::~Scan()
{
}

bool Scan::IsError()
{
	return error;
}
/*描述Scan类当中的函数方法*/
queue<string> Scan::ToStringQueue(string input)
{
	while (arithmetic.empty() == false)
		arithmetic.pop();
    //-------------预处理使之合法
	string temp="";	
	int i, l, n = 0, t = 0;
	l = input.size();
	//----2 去除等号; 
	for (i=0;i<l;i++)
	{
		if (input[i] != '=')
			temp += input[i];
	}
	input = "";
	input = temp;
	//-----1判断括号是否匹配 
	for (i = 0; i < l; i++)
	{
		if (input[i] == '(')
		{
			n++;
		}
		if (input[i] == ')')
		{
			t++;
		}
	}
	if (n > t)
	{
		for (i = 0; i < n-t; i++)
		{
			input += ")";
		}
	}
	if (n < t)
	{
		for (i = 0; i < t-n; i++)
		{
			temp += "(";
		}
		input = temp + input;	
	}
	//------2判断四则运算是否符合规范 
	temp = "";
	l = input.size();
	for (i = 0; i < l; i++)
	{
		if ((i+1) < l && input[i] == '(' && input[i+1] == '(')
			temp += input[i];
		else if((i+1) < l && input[i] == '(' && input[i+1] < '0')
		{
			temp += input[i];
			temp += "0";
		}
		else
			temp += input[i];
	}
	l = temp.size();
	input = "";
	for (i = 0; i < l; i++)
	{
		if( (i+1) < l && (temp[i] >= '0' && temp[i+1] == '(') || (temp[i] == ')' && temp[i+1] >= '0'))
		{
			if (temp[i] == '=')
				continue;
			input += temp[i];
			input += "*";
		}
		else
			if((i+1) < l && temp[i] < '0' && temp[i+1] < '0' && 
					temp[i] != temp[i+1] && temp[i] >= 42 && temp[i+1] >= 42)
		{
			input += temp[i];
			input += "(0";
			input += temp[++i];
			if(temp[++i] == '(')
			{
				n = 0;
				for ( i = i; i < l ; i++)
				{
					input += temp[i];
					if(temp[i] == '(')
					{
						n++;		
					}
					if(temp[i] == ')')
					{
						n--;
						if(n == 0)
							break;
					}
				}
				if (i < l)
					input += ")";
			}
			else
			{
				input += temp[++i];
				input += temp[++i];
				input += ")";
			}
		}
		else 
			input += temp[i];
	} 
	//-------------------------------------
   
    /*flg作为标记出现位数超过十位的情况,出现标记为1,total表示当前数字位数*/
    int flg = 0,total = 0;       
    l = input.size();
	for ( i = 0; i < l;)
    {
        /*添加一个空字符串存取表达式*/
        string tmp = "";
		      
        /*扫描实数部分判断并计算实数位数*/
        while (i < l && input[i] >= '0'
                && input[i] <= '9' || input[i] == '.')
        {
            tmp += input[i];
            i++;
            if(input[i] == '.')
            {
                total -= 1;  /*处理位数时去除小数点*/
            }
            total++;
        }

        /*判断是否超过10位数,若超过则输出Error并输出超出的实数*/
        if(total > 10)         
        { 
            error = true; 
        }

        /*将符合要求的实数添加到队列中*/
        if (tmp != "")       
        {
            arithmetic.push(tmp);
            total = 0;
        }

        /*扫描运算字符将字符存入已有队列中*/
        while ( i < l && (input[i] < '0' || input[i] > '9'))
        {
            tmp = "";
            tmp += input[i];
            arithmetic.push(tmp);
            tmp = "";
            i++;
        }
    }
    arithmetic.push("=");
    
    return arithmetic;          
}    
