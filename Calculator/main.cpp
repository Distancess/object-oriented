#include <iostream>
#include <string>
#include "print.h"

using namespace std; 

int main()
{
	cout<<"������һ������������ʽ:"<<endl;     //�����ʾ��Ϣ; 
	Print p;                                     //����Print�Ķ���p;  
	string input;                                //����һ���ַ��� 
	cin>>input;                                  //����������ʽ ;
	p.PrintStringQueue(input);                   //����Print�� ������� ;
    return 0;
}
