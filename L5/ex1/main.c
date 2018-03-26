#include <stdio.h>
#include <stdlib.h>


typedef struct NodeT
{
    int key;
    struct NodeT *left;
    struct NodeT *right;
} NodeT;


void insertNode(NodeT **root, int key)
{
    if(*root==NULL)
    {
        (*root)=(NodeT*)malloc(sizeof(NodeT));
        (*root)->key=key;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else
    {
        if((*root)->key>key)
            insertNode(&(*root)->left,key);
        else
            insertNode(&(*root)->right,key);
    }
}



NodeT* searchKey(NodeT *root, int key)
{
    if(root==NULL) return NULL;
    else
    {
        if (root->key==key)
            return root;
        else if(root->key>key)
            searchKey(root->left,key);
        else
            searchKey(root->right,key);

    }
}

NodeT *findMin(NodeT *root)
{
    if(root->left!=NULL) return findMin(root->left) ;
    else
        return root;


}

NodeT *findMax(NodeT *root)
{
    if(root->right!=NULL)
        return findMin(root->right) ;
    else
        return root;
}

NodeT* succesor(NodeT *root, NodeT *node)
{


}

NodeT* predecesor(NodeT *root, NodeT *node)
{

}

void deleteKey(NodeT **root, int key)
{
    NodeT *p;
    if(*root==NULL) return NULL;

        if (key < (*root)->key)
            deleteKey(&(*root)->left, key);

        else if (key > (*root)->key)
            deleteKey(&(*root)->right, key);

        else
        {
            if ((*root)->left == NULL && (*root)->left) *root=NULL;


            else if ((*root)->left == NULL)
            {
                p = (*root)->right;
                *root=p;
                deleteKey(&(*root)->right, p->key);

            }
            else if ((*root)->right == NULL)
            {
                p = (*root)->left;
                *root=p;
                deleteKey(&(*root)->left, p->key);

            }

            else{
            p = findMin((*root)->right);
           (*root)->key=p->key;
           deleteKey(&(*root)->right, p->key);
        }
        }
}

void inOrder(NodeT *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->key);
        inOrder(root->right);
    }
}

void preOrder(NodeT *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(NodeT *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->key);
    }
}

int main()
{

    NodeT *root = NULL;
    NodeT *p;

    int n = 11;
    int keys[] = {15, 6, 18, 17, 20, 3, 7, 2, 4, 13, 9};

    insertNode(&root, keys[0]);

    for (int i = 1; i < n; i++)
    {
        insertNode(&root, keys[i]);
    }

    printf( "\nPreorder listing\n" );
    preOrder( root);
    printf( "\nInorder listing\n" );
    inOrder( root );
    printf( "\nPostorder listing\n" );
    postOrder( root);

    int key = 17;
    p = searchKey( root, key );
    if ( p != NULL )
    {
        printf( "\nNod cu cheia = %d gasit\n", key);
        NodeT *m = findMin(p);
        printf("Minimul din subarborele care are ca radacina nodul %d este %d \n", p->key, m->key);
    }
    else
        printf( "Nodul NU a fost gasit \n" );

    NodeT *s = succesor(root, p);
    if ( s != NULL )
    {
        printf( "Nod cu cheia = %d are sucesor pe %d\n", p->key, s->key);
    }
    else
        printf( "Nodul NU are succesor !\n" );

    NodeT *q = predecesor(root, p);
    if ( q != NULL )
    {
        printf( "Nod cu cheia = %d are predecesor pe %d\n", p->key, q->key);
    }
    else
        printf( "Nodul NU are predecesor !\n" );


    key = 15;
    printf("Nodul de sters este: %d\n", key);
    deleteKey( &root, 15 );
    inOrder( root);

    return 0;
}
