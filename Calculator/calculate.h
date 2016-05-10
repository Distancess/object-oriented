#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>
#include <string>
#include <stack>
#include "calculation.h"

class Calculate
{
	public:
		Calculate();
		~Calculate();
		double Calculater(string input);
		bool iserror();
	private:
		stack<double>num;
		bool Error;
};

#endif
