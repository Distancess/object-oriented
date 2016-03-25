#ifndef SCAN_H
#define SCAN_H
#include <iostream>
#include <string>
#include <queue>

using namespace std;
/*创建一个Scan类并定义类当中函数的方法*/ 
class Scan
{
	public:
		Scan();
		~Scan();
		queue<string> ToStringQueue(string input); 
	private:
		/*创建一个arithmetic队列*/
		queue<string>arithmetic; 
};

#endif
