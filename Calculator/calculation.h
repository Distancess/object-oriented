#ifndef CALCULATION_H
#define CALCULATION_H
#include <iostream>
#include <string> 
#include "scan.h"

using namespace std;

class Calculation
{
	public:
		Calculation();
		~Calculation();
		void Getqueue(string input);
	protected:
		bool error;
};

#endif
