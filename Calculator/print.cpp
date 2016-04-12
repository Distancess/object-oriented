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

/*����Print�൱�еĺ�������*/ 
void Print::PrintStringQueue(string input) 
{
	/*����Scan����s*/ 
	Scan s;
	
	/*���Scan����ɨ��Ķ���*/                                            
	queue<string> tmp = s.ToStringQueue(input);  
	
	if (s.IsError() == true)
	{
		cout << "Error" <<endl;
	}
	else
	{
		/*�����������Ҫ���Ԫ��*/
		while ( !tmp.empty() )
		{
			cout << tmp.front() ;
			tmp.pop();                                  
		}
		
	}
}
