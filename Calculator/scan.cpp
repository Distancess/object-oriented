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

<<<<<<< 17077e6a7266e7cebfdb72eb4c9409fe0bdc5bac
//æè¿°Scanç±»å½“ä¸­çš„å‡½æ•°æ–¹æ³•ï¼š 

queue<string> Scan::ToStringQueue(string input)
//void Scan::ToStringQueue(string input ,queue<string> *Que)â‘¡ 
{
	int l = input.size();     //è®¡ç®—å­—ç¬¦ä¸²é•¿åº¦; 
	int flag=0,total=0;       //flagä½œä¸ºæ ‡è®°å‡ºç°ä½æ•°è¶…è¿‡åä½çš„æƒ…å†µ,å‡ºç°æ ‡è®°ä¸º1,totalè¡¨ç¤ºå½“å‰æ•°å­—ä½æ•°;
	for (int i=0; i<l;)
	{
		string temp="";      //æ·»åŠ ä¸€ä¸ªç©ºå­—ç¬¦ä¸²å­˜å–è¡¨è¾¾å¼;
        //æ‰«æå®æ•°éƒ¨åˆ†åˆ¤æ–­å¹¶è®¡ç®—å®æ•°ä½æ•°;  
		while (i<l && input[i]>='0' && input[i]<='9' || input[i]=='.')    
		{    
			temp+=input[i];
			i++;
			if(input[i]=='.')   total-=1;  //å»é™¤å°æ•°ç‚¹; 
			total++;
	    }
		if(total>10)         //åˆ¤æ–­æ˜¯å¦è¶…è¿‡10ä½æ•°,è‹¥è¶…è¿‡åˆ™è¾“å‡ºErrorå¹¶è¾“å‡ºè¶…å‡ºçš„å®æ•°;
		{
			cout<<"Errorï¼Œ"<<"è¶…è¿‡åä½æ•°çš„å®æ•°ä¸ºï¼š"<<temp<<endl;
			temp="";
=======
/*ÃèÊöScanÀàµ±ÖĞµÄº¯Êı·½·¨*/
queue<string> Scan::ToStringQueue(string input)
/*void Scan::ToStringQueue(string input ,queue<string> *Que)¢Ú·½·¨2*/
{
	/*¼ÆËã×Ö·û´®³¤¶È*/
	int l = input.size();     
	
	/*flg×÷Îª±ê¼Ç³öÏÖÎ»Êı³¬¹ıÊ®Î»µÄÇé¿ö,³öÏÖ±ê¼ÇÎª1,total±íÊ¾µ±Ç°Êı×ÖÎ»Êı*/
	int flg=0,total=0;       
	for (int i=0; i < l;)
	{
		/*Ìí¼ÓÒ»¸ö¿Õ×Ö·û´®´æÈ¡±í´ïÊ½*/
		string tmp="";      
		
		/*É¨ÃèÊµÊı²¿·ÖÅĞ¶Ï²¢¼ÆËãÊµÊıÎ»Êı*/
		while (i < l && input[i] >= '0'
		        && input[i] <= '9' || input[i] == '.')
		{
			tmp+=input[i];
			i++;
			if(input[i] == '.')
			{
				total-=1;  /*´¦ÀíÎ»ÊıÊ±È¥³ıĞ¡Êıµã*/
			}
			total++;
		}

		/*ÅĞ¶ÏÊÇ·ñ³¬¹ı10Î»Êı,Èô³¬¹ıÔòÊä³öError²¢Êä³ö³¬³öµÄÊµÊı*/
		if(total > 10)         
		{
			cout<<"Error£¬"<<"³¬¹ıÊ®Î»ÊıµÄÊµÊıÎª£º"<<tmp<<endl;
			tmp="";
>>>>>>> code finish
			total=0;
			flg=1;
		}
<<<<<<< 17077e6a7266e7cebfdb72eb4c9409fe0bdc5bac
		if (temp!="")       //å°†ç¬¦åˆè¦æ±‚çš„å®æ•°æ·»åŠ åˆ°é˜Ÿåˆ—ä¸­;
=======

		/*½«·ûºÏÒªÇóµÄÊµÊıÌí¼Óµ½¶ÓÁĞÖĞ*/
		if (tmp != "")       
>>>>>>> code finish
		{
			arithmetic.push(tmp);
			total=0;
		}
<<<<<<< 17077e6a7266e7cebfdb72eb4c9409fe0bdc5bac
        //æ‰«æè¿ç®—å­—ç¬¦å°†å­—ç¬¦å­˜å…¥å·²æœ‰é˜Ÿåˆ—ä¸­ 
=======

		/*É¨ÃèÔËËã×Ö·û½«×Ö·û´æÈëÒÑÓĞ¶ÓÁĞÖĞ*/
>>>>>>> code finish
		while (i<l && (input[i]<'0' || input[i]>'9'))
		{
			tmp="";
			tmp+=input[i];
			arithmetic.push(tmp);
			tmp="";
			i++;
		}
	}
<<<<<<< 17077e6a7266e7cebfdb72eb4c9409fe0bdc5bac
	if(flag==1) cout<<"å‰©ä½™å››åˆ™è¿ç®—è¡¨è¾¾å¼ä¸ºï¼š"<<endl;     //è‹¥è¶…è¿‡åä½æ•°,è¾“å‡ºæç¤ºä¿¡æ¯; 
	return arithmetic;           //å°†æ‰€è·å¾—çš„é˜Ÿåˆ—è¿”å›; 
=======

	/*Èô³¬¹ıÊ®Î»Êı,Êä³öÌáÊ¾ĞÅÏ¢*/
	if(flg == 1)
	{
		cout<<"Ê£ÓàËÄÔòÔËËã±í´ïÊ½Îª£º"<<endl;
	}
	
	 /*½«Ëù»ñµÃµÄ¶ÓÁĞ·µ»Ø*/
	return arithmetic;          
>>>>>>> code finish
}

