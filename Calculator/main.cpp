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

using namespace std; 

int main()
{
	/*�����ʾ��Ϣ*/
	cout << "������һ������������ʽ:" << endl;      
	
	/*����Print�Ķ���p*/
	Print p;                                       
	/*����һ���ַ��� */
	string input;                                
	cin >> input;
	
	/*����Print�� �������*/
	p.PrintStringQueue( input );                   
    return 0;
}
