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
void display(int,bnode*);
void postorder(bnode*);
void preorder(bnode*);
void inorder(bnode*);
int main()
{
    bnode *root =NULL;
    int ele,pos,c;
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
            //         scanf("%d %d",&ele,&pos)postorder;
            //         root=del_spec(ele,pos,root);
            //         break;
            case 4: printf("Enter what order you want? \n");
                    printf("1) inorder\n");
                    printf("2) preorder\n");
                    printf("3) postorder\n");
                    scanf("%d",&c);
                    display(c,root);
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
void postorder(bnode* r)
{
    if(r==NULL)
        return;
    postorder(r->llink);
    postorder(r->rlink);
    printf("%d",r->data);
    printf("\n");
}
void preorder(bnode* r)
{
    if(r==NULL)
        return;
    printf("%d",r->data);
    preorder(r->llink);
    preorder(r->rlink);
    printf("\n");
}
void inorder(bnode* r)
{
    if(r==NULL)
        return;
    inorder(r->llink);
    printf("%d",r->data);
    printf("\n");
    inorder(r->rlink);
}
void display(int ch,bnode* r)
{
    switch(ch)
    {
        case 1: inorder(r);
                break;
        case 2: preorder(r);
                break;
        case 3: postorder(r);
                break;
    }
}