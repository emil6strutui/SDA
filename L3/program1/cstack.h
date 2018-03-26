#ifndef STACK
#define STACK
typedef struct nod{
int key;
struct nod *next;
}Node;

int pop(Node **s);
void push(Node**s,int v);
#endif // STACK
