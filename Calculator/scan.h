#ifndef SCAN_H
#define SCAN_H
#include <iostream>
#include <string>
#include <queue>

using namespace std;
//创建一个Scan类并定义 
class Scan
{
	public:
		Scan();
		~Scan();
		queue<string> ToStringQueue(string input);   //定义为queue<string>类型的Scan类的函数 
	private:
		queue<string>arithmetic;//创建一个arithmetic队列; 
};

#endif
