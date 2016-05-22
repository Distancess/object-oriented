/*
	Name:反转链表 
	Copyright: 
	Author: Distance 
	Date: 22/05/16 16:47
	Description: 
*/
/*
描述：who数组用来存储每个节点的位置;
tab1 tab2 指针数组用来开辟静态链表; 
*/ 
#include <iostream>
#include <cstdio>

using namespace std;

//------------------
int first, n, k;
int i, j;
int t = 0, T, cnt = 0, who[1000010];
//------------------

struct Node
{
    int adress;
    int date;
    int _next;
    Node *next;
    Node *last;
} tab[100005];
Node *tab1[100005], *tab2[100005];

int main()
{
//	freopen ( "xx.in ","r",stdin );
// 	freopen ( "xx.out","w",stdout);
    //----0 initial
	for (i = 0; i <= 100005; i++)
    {
        tab1[i] = &tab[i];
        tab2[i] = &tab[i];
    }
    //----1 init
    cin >> first >> n >> k;
    for (i = 1; i <= n; i++)
    {
        cin >> tab1[i]->adress >> tab1[i]->date >> tab1[i]->_next;
        who[tab1[i]->adress] = i;
        tab1[i - 1]->next = tab1[i];
    }
    tab1[n]->next = NULL;

    for (i = first; i >= 0; i = tab1[who[i]]->_next)
    {
        tab2[++t] = tab1[who[i]];
        tab2[t - 1]->next = tab2[t];
        tab2[t]->last = tab2[t - 1];
    }
    tab2[t]->next = NULL;//very important!
    
	//-----2 change
    Node *head, *p1, *p2, *tmp;
    p1 = tab2[0]->next;
    head = p2 = tmp = new Node;
    head = NULL;
    for (; p1 != NULL && t >= k; )
    {
        cnt++;
        if (cnt == k)
        {
            t -= k;
            tmp = p1;
            p1 = p1->next;
            while (cnt--&&tmp)
            {
                if (head == NULL)
                    head = tmp;
                else
                    p2->next = tmp;
                p2 = tmp;
                tmp = tmp->last;
            }
            cnt = 0;
        }
        else
        {
        	p1 = p1->next;
		}
    }
   
    for (; p1 != NULL; p1 = p1->next)
    {
        if (head == NULL)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
    }
    p2->next = NULL;//very important
    
	//-----3print
    for (head; head->next != NULL; head = head->next)
    {
        printf("%05d %d %05d\n", head->adress, head->date, head->next->adress);
    }
    printf("%05d %d -1",head->adress,head->date);
    
    return 0;
}

