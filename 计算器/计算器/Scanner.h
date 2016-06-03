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
    /*处理超出十位数的情况*/
    bool IsError();
private:
    /*创建一个arithmetic队列*/
    queue<string>arithmetic;
    bool error;
};

