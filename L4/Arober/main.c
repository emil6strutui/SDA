#include <stdio.h>
#include <stdlib.h>
typedef struct node_type
{
    int id; /* numele nodului */
    /* alte informatii  utile */
    struct node_type *left, *right;
} NodeT;

void fatalError( const char *msg )
{
    printf( msg );
    printf( "\n" );
    exit ( 1 );
}

void postorder( NodeT *p )
{
    if ( p != NULL )

    {
        postorder( p->left);
        postorder( p->right);
        printf( "%d ", p->id );
    }

}

void inorder( NodeT *p )
{

    if ( p != NULL )

    {
        inorder( p->left);
        printf( "%d ", p->id );
        inorder( p->right);
    }
}

int leaf_node(NodeT *p)
{
    if(p!=NULL)
    {
        if (p->left==NULL && p->right==NULL)
            return 1;
        else if(p->left!=NULL && p->right!=NULL)
            return leaf_node(p->left)+leaf_node(p->right);
        else if(p->left!=NULL)
            return(leaf_node(p->left));
        else
            return(leaf_node(p->right));
    }
    return 0;
}

int noduri_interne(NodeT *p)
{
    if (p!=NULL)
    {
        if (p->left==NULL && p->right==NULL)
            return 0;
        else
        {
            if(p->left!=NULL && p->right!=NULL)
                return 1+leaf_node(p->left)+leaf_node(p->right);
            else if(p->left!=NULL)
                return 1+(leaf_node(p->left));
            else
                return 1+(leaf_node(p->right));
        }
    }
    return 0;
}
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int inaltime(NodeT *node)
{
    if(node==NULL)
        return -1;
    else return 1+max(inaltime(node->left),inaltime(node->right));
    return 0;
}
NodeT *search(NodeT *node, int key)
{
    if(node!=NULL)
    {
        if(node->id==key)
        {
            return node;
        }
        return search(node->left,key);
        return search(node->right,key);
    }
    else
        return NULL;
}


void preorder( NodeT *p )
/*
 * p = nodul curent;
*/
{
    if ( p != NULL )
    {
        printf( "%d ", p->id );
        preorder( p->left);
        preorder( p->right);
    }
}
//creaza un arbore binar prin citirea de la tastatura
NodeT *createBinTree( int branch, NodeT *parent )
{
    NodeT *p;
    int id;

    /* read node id */
    if ( branch == 0 )
        printf( "Valoarea pentru radacina [0 pt null] =" );
    else if ( branch == 1 )
        printf( "Fiul stang al nodului cu valoarea %d [0 pt null] =",
                parent->id );
    else
        printf( "Fiul drept al nodului cu valoarea %d [0 pt null] =",
                parent->id );
    scanf("%d", &id);
    if ( id == 0 )
        return NULL;
    else
    {
        /* construim nodul la care pointeaza p */
        p = ( NodeT *)malloc(sizeof( NodeT ));
        if ( p == NULL )
        {
            printf( "Nu mai avem memorie in createBinTree" );
            exit(1);
        }
        /* fill in node */
        p->id = id;
        p->left = createBinTree( 1, p );
        p->right = createBinTree( 2, p );
    }
    return p;
}
NodeT *createBinTreeFromFile(FILE* f)
{
    NodeT *p;
    int c;

    /* se citeste id-ul nodului */
    fscanf(f, "%d", &c);
    if ( c == 0 )
        return NULL; /* arbore vid, nu facem nimic */
    else /* else inclus pentru claritate */
    {
        /* construim nodul la care pointeaza p */
        p = ( NodeT *) malloc( sizeof( NodeT ));
        if ( p == NULL )
            fatalError( "Nu mai avem memorie in createBinTree" );
        /* se populeaza nodul */
        p->id = c;
        p->left = createBinTreeFromFile(f);
        p->right = createBinTreeFromFile(f);
    }
    return p;
}


int main()
{
    NodeT *root;
    FILE *f = fopen("ArboreBinar.txt", "r");
    if (!f)
    {
        printf("Nu se poate deschide fisierul ArboreBinar.txt\n");
        return -1;
    }
    root = createBinTreeFromFile(f);
    fclose(f);


    printf( "\nParcurgere in preordine\n" );
    preorder( root );

    //TODO
    printf("\n");
    printf( "\nParcurgere in postordine\n" );
    postorder(root);
    printf("\n");
    printf( "\nParcurgere in inordine\n" );
    inorder(root);
    printf("\n");

    int nr_frunze = leaf_node(root);
    printf("Numarul de frunze este = %d\n", nr_frunze);//3

    printf("Noduri interne = %d \n", noduri_interne(root));//5

    printf("Inaltimea arborelui = %d \n", inaltime(root)); //3
    return 0;
}
