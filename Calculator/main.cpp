/************************************************************
FileName: main.cpp
Author:Distance   Version :1.0       Date:16/02/25 
Description:实现对输入的四则表达式进行      
Version:Dev-C++ 5.11 
Function List:
    1. 处理输入的字符串;
    2. 输出处理后的字符串; 
History:
      <author>    <time>     <version >   <desc>
      Distance    16/02/27                 
***********************************************************/
#include <iostream>
#include <string>
#include "print.h"
#include "calculation.h"

using namespace std; 

int main(int argc, char* argv[])
{
	/*输出提示信息*/
	cout << "请输入一个四则运算表达式:" << endl;      
	
	/*创建Print的对象p*/
	Print p; 
	/*创建Calculation的对象c*/
	Calculation c;                                      
	/*定义一个字符串 */
	string input;                                
	cin >> input;
	if (input == "-a")
	{
		cin >> input;
		/*调用Print类 输出队列*/
		p.PrintStringQueue( input );                   
		
		cout << "= ";
		
    	c.Getqueue( input );
	}
	else
	{
    	c.Getqueue( input );
	}
	return 0;
}
