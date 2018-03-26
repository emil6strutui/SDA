#include <stdlib.h>
#include <stdio.h>
#include "cqueue.h"

void enq(Node**first,int val){
    Node*p=(Node*)malloc(sizeof(Node*));
    Node*q=*first;
    p->key=val;
    p->next=NULL;
    if(q==NULL)
    *first=p;
    else
        while(q!=NULL)
        q=q->next;
    q=p;

}

int deq(Node**first){
    Node *p;int x;
    if(*first!=NULL){
    p=*first;
    *first=(*first)->next;
    x=p->key;
    free(p);
    return x;
    }
    else return -1;
}
