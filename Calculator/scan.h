#ifndef SCAN_H
#define SCAN_H
#include <iostream>
#include <string>
#include <queue>

using namespace std;
/*����һ��Scan�ಢ�����൱�к����ķ���*/ 
class Scan
{
	public:
		Scan();
		~Scan();
		queue<string> ToStringQueue(string input); 
		/*������ʮλ�������*/
		bool IsError();
	private:
		/*����һ��arithmetic����*/
		queue<string>arithmetic; 
		bool error;
};

#endif
