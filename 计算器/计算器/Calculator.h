#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "calculation.h"

using namespace std;

class Calculator
{
public:
    Calculator();
    ~Calculator();
    double Calculater(string input);
    bool IsError();
private:
    stack<double>num;
    bool Error;
};

