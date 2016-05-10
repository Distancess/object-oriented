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

//--------1 ������ʽ; 
void Print::PrintStringQueue(string input) 
{
	/*����Scan����s*/ 
	Scan s;
	Calculate c;
	/*���Scan����ɨ��Ķ���*/                                            
	queue<string> tmp = s.ToStringQueue(input);  
	
	//---- ����Ϊ0�򳬳�ʮλ����ERROR 
	if (s.IsError() == true )
	{
		cout << "ERROR" <<endl;
	}
	else 
	{
		if (c.iserror() == false) 
		{
			/*�����������Ҫ���Ԫ��*/
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
//-----2 ������; 
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

//-----3 �����ļ���ȡ�ķ���
void Print::Usedfile(string input, string read, string ans)
{
	Calculate c;
	Scan ss;
	
	//---- 3-1 �ļ���������; 
	ifstream in;
	ofstream out;
	
	//����.c_str()�����ַ�����Ϊ�ļ���;
	in.open (read.c_str(),ios::in );
	out.open(ans.c_str() ,ios::out); 
	//----3-2 �ļ��Ķ�д;
	while ( !in.eof() )
	{
		int flag1 = 0;
		input.clear();
		getline(in, input, '\n');	
		double answer = 0;
		//---- 3-2-1 �ж��Ƿ񳬳�ʮλ; 
		if (ss.IsError() == true)
		{
			flag1 = 1;
//			out << "ERROR" << endl;
		}
		 
		if (ss.IsError() == false)
		{
			answer = c.Calculater(input);
			
			//---- 3-2-2 �жϳ����Ƿ�Ϊ0; 
			if (c.iserror() == true )
			{
				out << "ERROR" << endl;
			}
			else
			{
				//---- 3-2-3 �����; 
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
	//-----3-3 �ر��ļ�; 
	in.close() ;
	out.close();
}

 
