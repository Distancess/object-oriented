#include "scan.h"
#include <iostream>
#include <queue>

using namespace std;

Scan::Scan()
{	
}

Scan::~Scan()
{	
}

//描述Scan类当中的函数方法： 

queue<string> Scan::ToStringQueue(string input)
//void Scan::ToStringQueue(string input ,queue<string> *Que)② 
{
	int l = input.size();     //计算字符串长度; 
	int flag=0,total=0;       //flag作为标记出现位数超过十位的情况,出现标记为1,total表示当前数字位数;
	for (int i=0; i<l;)
	{
		string temp="";      //添加一个空字符串存取表达式;
        //扫描实数部分判断并计算实数位数;  
		while (i<l && input[i]>='0' && input[i]<='9' || input[i]=='.')    
		{    
			temp+=input[i];
			i++;
			if(input[i]=='.')   total-=1;  //去除小数点; 
			total++;
	    }
		if(total>10)         //判断是否超过10位数,若超过则输出Error并输出超出的实数;
		{
			cout<<"Error，"<<"超过十位数的实数为："<<temp<<endl;
			temp="";
			total=0;
			flag=1;
		}
		if (temp!="")       //将符合要求的实数添加到队列中;
		{
			arithmetic.push(temp);
			total=0;
		}
        //扫描运算字符将字符存入已有队列中 
		while (i<l && (input[i]<'0' || input[i]>'9'))
		{
			temp="";
			temp+=input[i];
			arithmetic.push(temp);
			temp="";
			i++;
		}
	}
	if(flag==1) cout<<"剩余四则运算表达式为："<<endl;     //若超过十位数,输出提示信息; 
	return arithmetic;           //将所获得的队列返回; 
}
