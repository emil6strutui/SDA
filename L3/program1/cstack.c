#include <stdlib.h>
#include <stdio.h>
#include "cstack.h"

void push(Node**first,int v){
Node *p=(Node*)malloc(sizeof(Node*));
p->key=v;
p->next=*first;
*first=p;
}

int pop(Node** first){
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

