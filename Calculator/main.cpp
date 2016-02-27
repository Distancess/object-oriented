#include <iostream>
#include <string>
#include "print.h"

using namespace std; 

int main()
{
	cout<<"请输入一个四则运算表达式:"<<endl;     //输出提示信息; 
	Print p;                                     //创建Print的对象p;  
	string input;                                //定义一个字符串 
	cin>>input;                                  //输入四则表达式 ;
	p.PrintStringQueue(input);                   //调用Print类 输出队列 ;
    return 0;
}
