#include "stdafx.h"
#include "Calculate.h"
#include <iostream>
#define pi 3.14
using namespace std;


Calculate::Calculate()
{
}


Calculate::~Calculate()
{
}

double Calculate::circle(double r)
{
    double area;
    area = pi*r*r;
    return area;
}