// main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Calculate.h"
using namespace std;


int main()
{
    cout << "请输入圆的半径：";
    double r;
    Calculate c;
    cin >> r;
    cout << "圆的面积S=";
    cout << c.circle(r) << endl;
    return 0;
}

