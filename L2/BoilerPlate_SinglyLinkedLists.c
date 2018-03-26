#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
} NodeT;

NodeT *search(NodeT *head, int givenKey)
{
    //TODO: search the given key and return the first node containing it or NULL
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT ));
    p=head;
    while(p!=NULL)
    {
        if ( p->key == givenKey ) /* found node having givenKey*/
            return p;
        else
            p = p->next;
    }
    return NULL;
}

void print_list(NodeT *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->key);
        head=head->next;
    }
    //TODO: print list keys
    printf("\n");
}

void insert_first(NodeT **head, NodeT **tail, int givenKey)
{
    //TODO: insert the given key in the first position of the list given by head and tail;
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT )); /* allocate memory */
    p->key = givenKey; /* copy key (assume type integer) in node pointed to by p*/
    p->next=NULL;
    if (*head==NULL)
    {
        *head=p;
        *tail=p;
    }
    else
    {
        p->next=*head;
        *head=p;
    }

}

void insert_last(NodeT **head, NodeT **tail, int givenKey)
{
    //TODO: insert the given key in the last position of the list given by head and tail;
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT )); /* allocate memory */
    p->key = givenKey; /* copy key (assume type integer) in node pointed to by p*/
    p->next=NULL;
    if(*tail==NULL)
    {
        (*head)=p;
        (*tail)=p;
    }
    else
    {
        (*tail)->next=p;
        (*tail)=p;
    }
}

void insert_after_key(NodeT** head, NodeT** tail, int afterKey, int givenKey)
{
    //TODO: insert the given key after afterKey, in list given by head and tail;
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT ));
    p=(*head);
    while(p!=NULL)
    {
        if(p->key==afterKey)
        {
            NodeT *q = ( NodeT * )malloc( sizeof( NodeT ));
            q->key=givenKey;
            q->next=p->next;
            p->next=q;
            if((*tail)==p)
                *tail=q;
            break;
        }
        p=p->next;
    }
}

void delete_first(NodeT** head, NodeT** tail)
{
    //TODO: delete first list element
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT ));
    if((*head)!=NULL)
        p=(*head);
    (*head)=(*head)->next;
    free(p);
    if((*head)==NULL)
        (*tail)=NULL;
}

void delete_last(NodeT** head, NodeT** tail)
{
    //TODO: delete last list element
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT ));
    NodeT *p1 = ( NodeT * )malloc( sizeof( NodeT ));
    p=(*head);
    if(p!=NULL)
    {
        while(p!=(*tail))
        {
            p1=p;
            p=p->next;
        }
        if ( p == (*head) )
        {
            /* only one node */
            (*head) = (*tail) = NULL;
        }
        else
        {
            p1->next=NULL;
            (*tail)=p1;

        }
        free(p);
    }
}

void delete_key(NodeT** first, NodeT** last, int givenKey)
{ //TODO: delete element having given key
    NodeT *p = ( NodeT * )malloc( sizeof( NodeT ));
    NodeT *q = ( NodeT * )malloc( sizeof( NodeT ));
    p=(*first);
    while(p!=NULL){
        if(p->next!=NULL)
        if(p->next->key==givenKey){
            q=p->next;
            p->next=p->next->next;
            free(q);
            break;
        }
        p=p->next;
    }
}

int main()
{
    NodeT *first = NULL;
    NodeT *last  = NULL;

    //perform several insertions
    insert_first(&first, &last, 4);
    insert_first(&first, &last, 1);
    insert_last(&first, &last, 3);

    //search for two distinct keys...
    int toSearch = 2;
    NodeT *foundNode = search(first, toSearch);
    if (foundNode == NULL)
    {
        printf("Node %d not found!\n", toSearch);
    }
    else
    {
        printf("%d found!", foundNode->key);
    }

    toSearch = 3;
    foundNode = search(first, toSearch);
    if (foundNode == NULL)
    {
        printf("Node %d not found!\n", toSearch);
        printf("\n");
    }
    else
    {
        printf("%d found!", foundNode->key);
        printf("\n");
    }

    //perform some insertions
    insert_after_key(&first, &last, 4, 22);
    insert_after_key(&first, &last, 3, 25);

    //print list contents
    print_list(first);

    //perform some deletions
    delete_first(&first,&last);
    delete_last(&first, &last);
    delete_key(&first, &last, 22);
    delete_key(&first, &last, 8);

    //print list contents
    print_list(first);


    //TODO: place here code to delete all list
    while(first!=NULL)
        delete_first(&first,&last);

    //print list contents
    print_list(first);

    return 0;
}
