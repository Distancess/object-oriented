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

//����Print�൱�еĺ��������� 
void Print::PrintStringQueue(string input) 
{
	/*����Scan����s*/ 
	Scan s;
	
	/*���Scan����ɨ��Ķ���*/                                            
	queue<string> tmp = s.ToStringQueue(input);  
	
	/*�����������Ҫ���Ԫ��*/
	while ( !tmp.empty() )
	{
		cout << tmp.front() << endl;
		tmp.pop();                                  
	}
}
