/************************************************************
FileName: main.cpp
Author:Distance   Version :1.0       Date:16/02/25 
Description:ʵ�ֶ������������ʽ����      
Version:Dev-C++ 5.11 
Function List:
    1. ����������ַ���;
    2. ����������ַ���; 
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
	/*�����ʾ��Ϣ*/
	cout << "������һ������������ʽ:" << endl;      
	
	/*����Print�Ķ���p*/
	Print p; 
	/*����Calculation�Ķ���c*/
	Calculation c;                                      
	/*����һ���ַ��� */
	string input;                                
	cin >> input;
	if (input == "-a")
	{
		cin >> input;
		/*����Print�� �������*/
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
