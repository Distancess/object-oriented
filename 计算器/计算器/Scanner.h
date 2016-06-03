#pragma once
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Scanner
{
public:
    Scanner();
    ~Scanner();
    queue<string> ToStringQueue(string input);
    /*������ʮλ�������*/
    bool IsError();
private:
    /*����һ��arithmetic����*/
    queue<string>arithmetic;
    bool error;
};

