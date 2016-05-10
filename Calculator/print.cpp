#include "print.h"
#include <iostream>
#include <queue>
#include <fstream>
#include <stack>

using namespace std;

Print::Print()
{
}

Print::~Print()
{
}

//--------1 输出表达式; 
void Print::PrintStringQueue(string input) 
{
	/*创建Scan对象s*/ 
	Scan s;
	Calculate c;
	/*获得Scan里所扫描的队列*/                                            
	queue<string> tmp = s.ToStringQueue(input);  
	
	//---- 除数为0或超出十位数输ERROR 
	if (s.IsError() == true )
	{
		cout << "ERROR" <<endl;
	}
	else 
	{
		if (c.iserror() == false) 
		{
			/*依次输出符合要求的元素*/
			while ( !tmp.empty() )
			{
				cout << tmp.front() ;
				tmp.pop();                                  
			}
			cout << " " << c.Calculater(input);
		}
		else
		{
			cout << "ERROR" << endl;
		}	
	}
}
//-----2 输出结果; 
void Print::Printanswer(string input)
{
	Calculate c;
	Scan s;
	double answer = 0;
	answer = c.Calculater(input);
	if (s.IsError() == true)
	{
		cout << "ERROR" << endl;
	}
	else
	{
		if (c.iserror() == false)
		{
			cout << answer << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	} 
	
}

//-----3 采用文件读取的方法
void Print::Usedfile(string input, string read, string ans)
{
	Calculate c;
	Scan ss;
	
	//---- 3-1 文件声明及打开; 
	ifstream in;
	ofstream out;
	
	//调用.c_str()接受字符串作为文件名;
	in.open (read.c_str(),ios::in );
	out.open(ans.c_str() ,ios::out); 
	//----3-2 文件的读写;
	while ( !in.eof() )
	{
		int flag1 = 0;
		input.clear();
		getline(in, input, '\n');	
		double answer = 0;
		//---- 3-2-1 判断是否超出十位; 
		if (ss.IsError() == true)
		{
			flag1 = 1;
//			out << "ERROR" << endl;
		}
		 
		if (ss.IsError() == false)
		{
			answer = c.Calculater(input);
			
			//---- 3-2-2 判断除数是否为0; 
			if (c.iserror() == true )
			{
				out << "ERROR" << endl;
			}
			else
			{
				//---- 3-2-3 输出答案; 
				if (flag1 == 1)
				{
					out << "ERROR" << endl;
					flag1 = 0;
				}
				else
				{
					out << answer << endl;	
				}
				
			}
		}
	}
	//-----3-3 关闭文件; 
	in.close() ;
	out.close();
}

 
