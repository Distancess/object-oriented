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
	Scan s;                                            //����Scan����s; 
	queue<string> tmp = s.ToStringQueue(input);        //���Scan�����õĶ���; 
	while(!tmp.empty())
	{
		cout<<tmp.front()<<endl;                       //��������е�Ԫ��; 
		tmp.pop();                                     //ɾ������Ԫ��; 
	}
}
