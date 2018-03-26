#include <stdlib.h>
#include <stdio.h>
#include "listadubla.h"

void insert_first(Node**first,Node** last,int val){
    Node*p=(Node*)malloc(sizeof(Node*));
    p->key=val;
    p->next=NULL;
    p->prev=NULL;
    if(*first==NULL){
        *first=p;
        *last=p;
    }
    else{
        p->next=*first;
    (*first)->prev=p;
    *first=p;
    }
}
void insert_last(Node**first,Node** last,int val){
    Node*p=(Node*)malloc(sizeof(Node*));
    p->key=val;
    p->next=NULL;
    p->prev=NULL;
    if(*first==NULL){
        *first=p;
        *last=p;
    }
    else {
        p->prev=*last;
        (*last)->next=p;
        *last=p;
    }
}

void insert_afterkey(Node**first,Node** last,int afterkey,int val){
    Node*p=(Node*)malloc(sizeof(Node*));
    Node*q=*first;
    p->key=val;
    p->next=NULL;
    p->prev=NULL;

    while(q->key!=afterkey && q!=NULL)
    q=q->next;
    if(q!=NULL){
    p->prev=q;
    p->next=q->next;
    if(q->next!=NULL)
        q->next->prev=p;
    q->next=p;
    if(*last==q)
        *last=p;
    }


}
void delete_first (Node**first){
     Node *p;
    if(*first!=NULL){
    p=*first;
    *first=(*first)->next;
    free(p);
    }
}
void delete_last(Node**first,Node**last){
    Node *p;
    if(*first!=NULL){
        p=*last;
        *last=(*last)->prev;
       (*last)->next=NULL;
       free(p);
    }
}

void delete_key(Node**first,Node**last,int givenkey){
    Node*p;
    if(*first!=NULL){
    p=*first;
    while(p->key!=givenkey && p!=NULL)
        p=p->next;
    if(p!=NULL){
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    }
    }
}

