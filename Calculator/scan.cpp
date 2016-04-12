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
/*void Scan::ToStringQueue(string input ,queue<string> *Que)②方法2*/
{
    /*计算字符串长度*/
    int l = input.size();     
    
    /*flg作为标记出现位数超过十位的情况,出现标记为1,total表示当前数字位数*/
    int flg = 0,total = 0;       
    
	for (int i = 0; i < l;)
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

    return arithmetic;          
}    
