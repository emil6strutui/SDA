#ifndef LISTD
#define LISTD
typedef struct nod{
int key;
struct nod *next;
struct nod *prev;
}Node;
void insert_first(Node**first,Node** last,int val);
void insert_last(Node**first,Node** last,int val);
void insert_afterkey(Node**first,Node** last,int afterkey,int val);
void delete_first (Node**first);
void delete_last(Node**first,Node**last);
void delete_key(Node**first,Node**last,int givenkey);

#endif
