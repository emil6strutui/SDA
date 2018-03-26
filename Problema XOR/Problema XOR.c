#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int key;
    struct nod *pn;
} NodeT;

void insert_first(NodeT**first,int givenKey)
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    p->key=givenKey;
    p->pn=(NodeT*)(((int)(*first))^0);
    if(*first!=NULL)
    {
        NodeT*next=(NodeT*)(((int)((*first)->pn))^0);
        (*first)->pn=(NodeT*)(((int)p)^((int)next));
    }
    *first=p;
}
void afisare(NodeT*first)
{
    NodeT*c=first;
    NodeT*p=NULL;
    NodeT*n;
    while(c!=NULL)
    {
        printf("%d ",c->key);
        n=(NodeT*)(((int)c->pn)^((int)p));
        p=c;
        c=n;
    }
    printf("\n");
}
void insert_last(NodeT**first,int givenKey)
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    p->key=givenKey;
    if(*first==NULL)
    {
        p->pn=(NodeT*)(((int)(*first))^0);
        *first=p;
    }
    else
    {
        NodeT*current=(*first);
        NodeT*prev=NULL;
        NodeT*next;
        while(current!=NULL)
        {
            next=(NodeT*)(((int)current->pn)^((int)prev));
            if (next==NULL) break;
            prev=current;
            current=next;
        }
        current->pn=(NodeT*)(((int)p)^((int)prev));
        p->pn=(NodeT*)(((int)current)^0);
        current=p;
    }

}
void delete_first(NodeT**first)
{
    if(*first!=NULL)
    {
        NodeT*current=*first;
        NodeT*next=(NodeT*)(((int)current->pn)^0);
        if(current->pn==0)
        {
            free(first);
            *first=NULL;
        }
        else
        {
            next=(NodeT*)(((int)(next)->pn)^((int)current));
            (*first)=(NodeT*)(((int)current->pn)^0);
            (*first)->pn=(NodeT*)((int)(next)^0);
            free(current);
        }
    }
}

void delete_last(NodeT**first)
{
    if(*first!=NULL)
    {
        NodeT*current=*first;
        if(current->pn==0)
        {
            free(*first);
            *first=NULL;
        }
        else
        {
            NodeT*current=(*first);
            NodeT*prev=NULL;
            NodeT*next;
            while(current!=NULL)
            {
                next=(NodeT*)(((int)current->pn)^((int)prev));
                if (next==NULL) break;
                prev=current;
                current=next;
            }
            prev=(NodeT*)(((int)prev->pn)^((int)current));
            current=(NodeT*)(((int)current->pn)^((int)next));
            next=(NodeT*)(((int)current->pn)^((int)prev));
            current->pn=(NodeT*)(((int)prev)^0);
            free(next);
        }
    }
}

void insert_after_key(NodeT**first,int search_key,int givenKey)
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    p->key=givenKey;
    if(*first!=NULL)
    {
        NodeT*current=*first;
        if(current->pn==0){
         if(search_key==current->key){
            p->pn=(NodeT*)(((int)current)^0);
            current->pn=(NodeT*)(((int)p)^0);
         }
        }
         else
         {
            NodeT*current=(*first);
            NodeT*prev=NULL;
            NodeT*next;
            while(current!=NULL)
            {
                next=(NodeT*)(((int)current->pn)^((int)prev));

                if(search_key==current->key){
                  if (next!=NULL)
                   next->pn=(NodeT*)(((int)((NodeT*)(((int)next->pn)^((int)current))))^((int)p));
                   p->pn=(NodeT*)(((int)current)^((int)next));
                   current->pn=(NodeT*)(((int)prev)^((int)p));
                   break;
               }
                if (next==NULL) break;
                prev=current;
                current=next;
            }
         }
    }

}
void delete_after_key(NodeT**first,int search_key)
{
    if(*first!=NULL)
    {
        NodeT*current=*first;
        if(current->pn==0){
         if(search_key==current->key){

            free(*first);
            *first=NULL;
         }
        }
         else
         {
            NodeT*current=(*first);
            NodeT*prev=NULL;
            NodeT*next=(NodeT*)(((int)current->pn)^((int)prev));

            while(next!=NULL){
                if(search_key==current->key){
                  if (next!=NULL)
                   next->pn=(NodeT*)(((int)((NodeT*)(((int)next->pn)^((int)current))))^((int)prev));
                   if(prev!=NULL)
                   prev->pn=(NodeT*)(((int)((NodeT*)(((int)prev->pn)^((int)current))))^((int)next));
                   free(current);
                   if (prev==NULL)
                    *first=next;
                   break;
               }
                prev=current;
                current=next;
                next=(NodeT*)(((int)current->pn)^((int)prev));


        }
    }
    }

}
int main()
{
    NodeT*first=NULL;
    insert_first(&first,89);
    insert_first(&first,11);
    insert_first(&first,73);
    afisare(first);
    insert_last(&first,4);
    afisare(first);
    insert_after_key(&first,89,2);
    afisare(first);
    delete_after_key(&first,89);
    afisare(first);
    delete_last(&first);
    afisare(first);
    delete_last(&first);
    afisare(first);
    return 0;
}
