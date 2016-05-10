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
/*����Scan�൱�еĺ�������*/
queue<string> Scan::ToStringQueue(string input)
{
	while (arithmetic.empty() == false)
		arithmetic.pop();
    //-------------Ԥ����ʹ֮�Ϸ�
	string temp="";	
	int i, l, n = 0, t = 0;
	l = input.size();
	//----2 ȥ���Ⱥ�; 
	for (i=0;i<l;i++)
	{
		if (input[i] != '=')
			temp += input[i];
	}
	input = "";
	input = temp;
	//-----1�ж������Ƿ�ƥ�� 
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
	//------2�ж����������Ƿ���Ϲ淶 
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
   
    /*flg��Ϊ��ǳ���λ������ʮλ�����,���ֱ��Ϊ1,total��ʾ��ǰ����λ��*/
    int flg = 0,total = 0;       
    l = input.size();
	for ( i = 0; i < l;)
    {
        /*���һ�����ַ�����ȡ���ʽ*/
        string tmp = "";
		      
        /*ɨ��ʵ�������жϲ�����ʵ��λ��*/
        while (i < l && input[i] >= '0'
                && input[i] <= '9' || input[i] == '.')
        {
            tmp += input[i];
            i++;
            if(input[i] == '.')
            {
                total -= 1;  /*����λ��ʱȥ��С����*/
            }
            total++;
        }

        /*�ж��Ƿ񳬹�10λ��,�����������Error�����������ʵ��*/
        if(total > 10)         
        { 
            error = true; 
        }

        /*������Ҫ���ʵ����ӵ�������*/
        if (tmp != "")       
        {
            arithmetic.push(tmp);
            total = 0;
        }

        /*ɨ�������ַ����ַ��������ж�����*/
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
