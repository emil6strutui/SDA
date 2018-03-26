#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
    char c;
    int freq;
    struct nod *next;
} NodeT;

void insert_first(NodeT**first,char c)
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    p->c=c;
    p->next=NULL;
    if(*first==NULL)
        *first=p;
    else
    {
        p->next=*first;
        *first=p;
    }
}
void insert_last(NodeT**first,char c)
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    NodeT*q=(*first);
    p->c=c;
    p->next=NULL;
    if(*first==NULL)
        *first=p;
    else
    {
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
    }
}

void afisare(NodeT*first)
{
    while(first!=NULL)
    {
        printf("%c ",first->c);
        first=first->next;
    }
    printf("\n");

}
void inversare(NodeT**first)
{
    if(*first!=NULL){
    NodeT*p=(*first)->next;
    NodeT*q=(*first)->next;
    (*first)->next=NULL;
    while(p!=NULL)
    {
      q=q->next;
      p->next=*first;
      *first=p;
      p=q;

    }
    }
}
int main()
{
    NodeT*first=NULL;
    inversare(&first);
    insert_first(&first,'5');
    afisare(first);
    inversare(&first);
    afisare(first);
    insert_first(&first,'7');
    insert_first(&first,'4');
    insert_first(&first,'3');
    afisare(first);
    inversare(&first);
    afisare(first);
    insert_first(&first,'2');
    afisare(first);
    inversare(&first);
    afisare(first);
    insert_first(&first,'1');
    afisare(first);
    inversare(&first);
    afisare(first);
     inversare(&first);
    afisare(first);


    return 0;
}
