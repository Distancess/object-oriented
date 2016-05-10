#ifndef CALCULATION_H
#define CALCULATION_H
#include <iostream>
#include <string>
#include <stack> 
#include "scan.h"

using namespace std;

class Calculation
{
	public:
		Calculation();
		~Calculation();
		stack<string> Getqueue(string input);
	protected:
		stack<string>sign; 
		stack<string>opr;
		stack<string>rpn;
};

#endif
