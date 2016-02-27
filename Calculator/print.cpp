#include "print.h"
#include <iostream>
#include <queue>

using namespace std;

Print::Print()
{
}

Print::~Print()
{
}

//定义Print类当中的函数方法： 
void Print::PrintStringQueue(string input) 
{
	Scan s;                                            //创建Scan对象s; 
	queue<string> tmp = s.ToStringQueue(input);        //获得Scan里所得的队列; 
	while(!tmp.empty())
	{
		cout<<tmp.front()<<endl;                       //输出队列中的元素; 
		tmp.pop();                                     //删除队首元素; 
	}
}
