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
//#include "calculate.h"

using namespace std; 

int main(int argc, char* argv[])
{
	/*创建Print的对象p*/
	Print p;
	string input;
	
	input = argv[1];                                
	if (input == "-a")
	{
		input = argv[2];
		//调用Print类 输出队列和结果 
		p.PrintStringQueue(input);                   
    	
	}
	else
		if(input == "-f")
		{
			input = "";
			string write  = argv[2];
			string result = argv[3];
			p.Usedfile(input,write,result);
		}
	else 
	{
		input = argv[1];
    	p.Printanswer(input);
	}
	return 0;
}
