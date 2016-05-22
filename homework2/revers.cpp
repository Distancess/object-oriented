#include <iostream>
#include <cstdio>
struct p
{
	int adress;
	int date;
	int next;
} tab[100010],tab2[100010];
int T,who[1000010];
using namespace std;
int main()
{
	struct p tmp;
	int n,k;
	int i,j,t=0,first;
	cin >> first >> n >> k;
	
	//----init 
	for ( i = 1; i <= n; i++)
	{
		cin >> tab[i].adress >> tab[i].date >> tab[i].next;
		who[tab[i].adress] = i;
	}
	
	for ( i = first ; i >= 0; i = tab[ who[i] ].next)
		tab2[++t] = tab[ who[i] ];

	//----change
	for ( i = 1; i <= t/k; i++)
	{
		T=i*k;
		for ( j = (i-1)*k+1; j <= k/2+(i-1)*k; j++,T--)
		{
			tmp = tab2[j];
			tab2[j] = tab2[T];
			tab2[T] = tmp;
 		}	
	}
	//----print
	for ( i = 1; i < t; i++)
		printf("%05d %d %05d\n",tab2[i].adress,tab2[i].date,tab2[i+1].adress);
	printf("%05d %d -1",tab2[t].adress,tab2[t].date);
	return 0;
}   
