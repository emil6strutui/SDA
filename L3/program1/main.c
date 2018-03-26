#include <stdio.h>
#include <stdlib.h>
#include "listadubla.h"

void afisare(Node*first){
    while(first!=NULL)
    {
        printf("%d ",first->key);
        first=first->next;
    }
    printf("\n");
}
int main()
{
    Node*first=NULL;Node*last=NULL;
    insert_first(&first,&last,7);
    afisare(first);
    insert_first(&first,&last,2);
    afisare(first);
    insert_last(&first,&last,3);
    afisare(first);
    return 0;
}
