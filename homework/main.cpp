// main.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Calculate.h"
using namespace std;


int main()
{
    cout << "������Բ�İ뾶��";
    double r;
    Calculate c;
    cin >> r;
    cout << "Բ�����S=";
    cout << c.circle(r) << endl;
    return 0;
}

