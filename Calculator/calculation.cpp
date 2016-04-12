/****************************************
ջ��sign������ȡ�������
	opr������ȡ��������
	rpn������ȡ��׺���ʽ�� 
	num������ȡ�������ݣ�
���飺mark����Ƿ������ȼ��� 
������sstream���������ַ��������������ַ��͵�ת����
	  clear  ����������ʹ�õ�sstream����	 
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
	
	//��ʼ��-------------------------------------- 
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
	//1.��׺ת��׺---------------------------------
	if (s1.IsError() == false)
	{
		if (tmp1.front() == "-")
		{
			opr.push("0");
		} 
		while ( tmp1.empty() == false )
		{
			//---1.���������
			if ( tmp1.front()[0] >= '0' && tmp1.front()[0] <= '9')
			{
				opr.push( tmp1.front() );
				tmp1.pop();
			}
			//---2.���������
			else
			{
				if ( sign.empty() == true || sign.top() == "(")  
				{
					sign.push( tmp1.front() );
					tmp1.pop();
					continue;				
				}
				  
				//�����ջ�ǿ�
				//----1.�ж����ŵ�ƥ�� 
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
				//----2.�ж����ȼ�
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
		//----3.����ʣ�������� 
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
	
		//4.��ʼ������
		//��ʼ��--------------------- 
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
