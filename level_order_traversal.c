#include<stdio.h>
#define MAX 10
typedef struct BTREE
{
    int data;
    struct BTREE *llink,*rlink;
}tnode;
void leverorder(tnode *root)
{
    int f=0,r=-1;
    tnode *queue[MAX];
    tnode *temp=root;
    if(!temp)
    {
        printf("\nTree is empty");
        return;
    }
    addq(temp);

}