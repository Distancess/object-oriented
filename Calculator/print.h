#ifndef PRINT_H
#define PRINT_H
#include <iostream>
#include <string>
#include "scan.h"
#include "calculate.h"

using namespace std;

/*����Print������������в������൱�еĺ���*/ 
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
