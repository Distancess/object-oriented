#include "scan.h"
#include <iostream>
#include <queue>

using namespace std;

Scan::Scan()
{
	error = false; 
}

Scan::~Scan()
{
}

bool Scan::IsError()
{
	return error;
}
/*����Scan�൱�еĺ�������*/
queue<string> Scan::ToStringQueue(string input)
/*void Scan::ToStringQueue(string input ,queue<string> *Que)�ڷ���2*/
{
    /*�����ַ�������*/
    int l = input.size();     
    
    /*flg��Ϊ��ǳ���λ������ʮλ�����,���ֱ��Ϊ1,total��ʾ��ǰ����λ��*/
    int flg = 0,total = 0;       
    
	for (int i = 0; i < l;)
    {
        /*���һ�����ַ�����ȡ���ʽ*/
        string tmp = "";
		      
        /*ɨ��ʵ�������жϲ�����ʵ��λ��*/
        while (i < l && input[i] >= '0'
                && input[i] <= '9' || input[i] == '.')
        {
            tmp += input[i];
            i++;
            if(input[i] == '.')
            {
                total -= 1;  /*����λ��ʱȥ��С����*/
            }
            total++;
        }

        /*�ж��Ƿ񳬹�10λ��,�����������Error�����������ʵ��*/
        if(total > 10)         
        { 
            error = true; 
        }

        /*������Ҫ���ʵ����ӵ�������*/
        if (tmp != "")       
        {
            arithmetic.push(tmp);
            total = 0;
        }

        /*ɨ�������ַ����ַ��������ж�����*/
        while ( i < l && (input[i] < '0' || input[i] > '9'))
        {
            tmp = "";
            tmp += input[i];
            arithmetic.push(tmp);
            tmp = "";
            i++;
        }
    }

    return arithmetic;          
}    
