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
	/*创建Scan对象s*/ 
	Scan s;
	
	/*获得Scan里所扫描的队列*/                                            
	queue<string> tmp = s.ToStringQueue(input);  
	
	/*依次输出符合要求的元素*/
	while ( !tmp.empty() )
	{
		cout << tmp.front() << endl;
		tmp.pop();                                  
	}
}
