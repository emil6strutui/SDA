#ifndef QUEUE
#define QUEUE
typedef struct nod{
int key;
struct nod *next;
}Node;
int deq(Node**first);
void enq(Node**first,int val);
#endif

