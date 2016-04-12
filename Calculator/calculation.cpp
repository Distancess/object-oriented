/****************************************
栈：sign用来存取运算符；
	opr用来存取操作数；
	rpn用来存取后缀表达式； 
	num用来存取整型数据；
数组：mark：标记符号优先级； 
函数：sstream用来操作字符串类型与整型字符型的转化；
	  clear  用来清除多次使用的sstream对象；	 
****************************************/
#include "calculation.h"
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

Calculation::Calculation()
{
	error = false;
}

Calculation::~Calculation()
{
}

bool Calculation::Iserror()
{
	return error;
}
//------------------------------------------------------
	stack<string>sign; 
	stack<string>opr;
	stack<string>rpn;
//------------------------------------------------------
void Calculation::Getqueue(string input)
{
	
	//初始化-------------------------------------- 
	int mark[50];
	mark['+'] = 1;
	mark['-'] = 1;
	mark['*'] = 2;
	mark['/'] = 2;
	mark[')'] = 3;
	mark['('] = 4;	
	Scan s1;
	queue<string> tmp1 = s1.ToStringQueue(input);
	//-------------------------------------------- 
	//1.中缀转后缀---------------------------------
	if (s1.IsError() == false)
	{
		if (tmp1.front() == "-")
		{
			opr.push("0");
		} 
		while ( tmp1.empty() == false )
		{
			//---1.处理操作数
			if ( tmp1.front()[0] >= '0' && tmp1.front()[0] <= '9')
			{
				opr.push( tmp1.front() );
				tmp1.pop();
			}
			//---2.处理运算符
			else
			{
				if ( sign.empty() == true || sign.top() == "(")  
				{
					sign.push( tmp1.front() );
					tmp1.pop();
					continue;				
				}
				  
				//运算符栈非空
				//----1.判断括号的匹配 
				if ( tmp1.front() == ")" )
				{
					while ( sign.top() != "(")
					{
						opr.push( sign.top() );
						sign.pop();
					}
					tmp1.pop();
					sign.pop(); 
				}
				//----2.判断优先级
				else 
				{
					
					for ( ; sign.empty() == false && sign.top()!= "("  
									&& (mark[tmp1.front()[0]] <= mark[sign.top()[0]]); )
					{
						opr.push( sign.top() );
						sign.pop();
					}
					sign.push( tmp1.front() );
					tmp1.pop();
				}
			}
		}
		//----3.处理剩余的运算符 
		while ( sign.empty() == false ) 
		{
			if (sign.top() == "(" || sign.top() == ")")
			{ 
				sign.pop();
			}
			else
			{	
				opr.push( sign.top() );
				sign.pop();
			}
		}
		
		while (opr.empty() == false)
		{
			rpn.push( opr.top() );
			opr.pop();
		}
	
		//4.开始计算啦
		//初始化--------------------- 
		stringstream stream;
		double n,a,b;
		stack<double>num;
		//---------------------------
		while ( rpn.empty() == false)
		{
			if ( rpn.top()[0] >= '0' && rpn.top()[0] <='9')
			{
				stream << rpn.top();
				stream >> n;
				num.push(n);
				stream.clear();
				rpn.pop(); 
			}
			else
			{
				a = num.top();
				num.pop();
				b = num.top();
				num.pop();
				if (rpn.top() == "+")
				{
					num.push(b+a);
					rpn.pop();
				}
				else if (rpn.top() == "-")
				{
					num.push(b-a);
					rpn.pop();
				}
				else if (rpn.top() == "*")
				{
					num.push(a*b);
					rpn.pop();  
				}
				else
				{
					if ( a==0 )
						error = true;
					else
						num.push((double)b/a);
					rpn.pop();
				} 
			}
		}
		
		if ( error == true)
		{ 
			cout << "Error" << endl;
		} 
		else
		{ 
			cout << num.top() << endl; 
		}
	} 
} 
