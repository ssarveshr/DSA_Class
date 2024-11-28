#include<stdio.h>
#include<stdlib.h>

typedef struct BTREE
{
    int data;
    struct BTREE *llink,*rlink;
}bnode;

bnode* insert(int,bnode*);
bnode* getnode();
bnode* delete(bnode*);
bnode* del_spec(int,int,bnode*);
void display(bnode*);
int main()
{
    bnode *root =NULL;
    int ele,pos;
    int ch;
    while(1)
    {
        printf("1.insert \n");
        printf("2.delete \n");
        printf("3.delete specific element\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);   
        switch(ch)
        {
            case 1: printf("Enter the to be inserted into the tree : ");
                    // printf("%d\n",root->data);
                    scanf("%d",&ele);
                    root=insert(ele,root);
                    break;
            // case 2: root=delete(root);
            //         break;
            // case 3: printf("Enter the to be deleted into the tree : ");
            //         scanf("%d %d",&ele,&pos);
            //         root=del_spec(ele,pos,root);
            //         break;
            case 4: display(root);
                    break;
            case 5: exit(0);
                    break;
            
        }
    }
}
bnode *getnode()
{
    bnode *temp=(bnode *)malloc(sizeof(bnode));
    if(temp==NULL)
        printf("Memory not allocated \n");
    return temp;
    
}
bnode* insert(int ele,bnode* r)
{
    bnode *new=getnode();
    new->data=ele;
    new->rlink=new->llink=NULL;
    if(r==NULL)
    {
        // printf("%d\n");
        return new;
    }
    bnode* temp=r;
    while(temp->llink!=NULL||temp->rlink!=NULL)
    {
        if(ele<temp->data)
        {
            temp=temp->llink;
        }
        else
        {
            temp=temp->rlink;
        }
    }
    if(ele<temp->data)
        temp->llink=new;
    else
        temp->rlink=new;
    return r;
}
void display(bnode* r)
{
    if(r==NULL)
    {
        printf("Empty tree\n");
        return;
    }
    printf(" in func body\n");
    bnode *pres,*prev=NULL;
    pres=r;
    printf(" in func body\n"); 
    while(pres->llink!=NULL)
    {
        printf("in while 1 \n");
        prev=pres;
        printf("in while 2 \n");
        printf("%d\n",pres->data);
        prev=prev->llink;
        printf("in while 3 \n");
    }
    printf("%d\n",prev->rlink->data);
    // pres=pres->llink;
    // prev=NULL;
    // while(pres->rlink!=NULL)
    // {
    //     prev=pres;
    //     printf("%d\n",pres->data);
    //     prev=prev->llink;
    // }
}
