#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <string>
#include "scan.h"
#include "calculate.h"

using namespace std;

/*创建Print类用来输出队列并定义类当中的函数*/ 
class Print
{
    public:
        Print();
        ~Print();
    void PrintStringQueue(string input);
	void Printanswer(string input);
	void Usedfile(string input, string read, string ans);  
    private:
};

#endif
