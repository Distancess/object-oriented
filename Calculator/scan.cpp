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

//����Scan�൱�еĺ��������� 

queue<string> Scan::ToStringQueue(string input)
//void Scan::ToStringQueue(string input ,queue<string> *Que)�� 
{
	int l = input.size();     //�����ַ�������; 
	int flag=0,total=0;       //flag��Ϊ��ǳ���λ������ʮλ�����,���ֱ��Ϊ1,total��ʾ��ǰ����λ��;
	for (int i=0; i<l;)
	{
		string temp="";      //���һ�����ַ�����ȡ���ʽ;
        //ɨ��ʵ�������жϲ�����ʵ��λ��;  
		while (i<l && input[i]>='0' && input[i]<='9' || input[i]=='.')    
		{    
			temp+=input[i];
			i++;
			total++;
	    }
		if(total>10)         //�ж��Ƿ񳬹�10λ��,�����������Error�����������ʵ��;
		{
			cout<<"Error��"<<"����ʮλ����ʵ��Ϊ��"<<temp<<endl;
			temp="";
			total=0;
			flag=1;
		}
		if (temp!="")       //������Ҫ���ʵ����ӵ�������;
		{
			arithmetic.push(temp);
			total=0;
		}
        //ɨ�������ַ����ַ��������ж����� 
		while (i<l && (input[i]<'0' || input[i]>'9'))
		{
			temp="";
			temp+=input[i];
			arithmetic.push(temp);
			temp="";
			i++;
		}
	}
	if(flag==1) cout<<"ʣ������������ʽΪ��"<<endl;     //������ʮλ��,�����ʾ��Ϣ; 
	return arithmetic;           //������õĶ��з���; 
}
