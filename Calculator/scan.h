#ifndef SCAN_H
#define SCAN_H
#include <iostream>
#include <string>
#include <queue>

using namespace std;
//����һ��Scan�ಢ���� 
class Scan
{
	public:
		Scan();
		~Scan();
		queue<string> ToStringQueue(string input);   //����Ϊqueue<string>���͵�Scan��ĺ��� 
	private:
		queue<string>arithmetic;//����һ��arithmetic����; 
};

#endif
