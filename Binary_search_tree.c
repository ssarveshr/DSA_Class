#include<stdio.h>
#include<stdlib.h>

typedef struct BTREE
{
    int data;
    struct BTREE *llink,*rlink;
}bnode;

bnode* insert(int,bnode*);
bnode* getnode();
int b_search_tree(int,bnode*);
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
        printf("2.display\n");
        printf("3.search element\n");
        printf("4.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);  
        int key;
        int result; 
        switch(ch)
        {
            case 1: printf("Enter the number to be inserted into the tree : ");
                    scanf("%d",&ele);
                    root=insert(ele,root);
                    break;
            case 2: printf("Enter what order you want? \n");
                    printf("1) inorder\n");
                    printf("2) preorder\n");
                    printf("3) postorder\n");
                    scanf("%d",&c);
                    display(c,root);
                    break;
            case 3: printf("enter the key to be searched :");
                    scanf("%d",&key);
                    result=b_search_tree(key,root);
                    if(result==1)
                        printf("key found\n");
                    else
                        printf("key not found\n");
                    break;
            case 4:printf("Exiting code....");
                   exit(0);
            default:printf("invalid input\n");
        }
    }
    return 0;
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
        return new;
    }
    bnode* temp=r;
    while(temp->llink!=NULL||temp->rlink!=NULL)
    {
        if(ele<temp->data)
        {
            if(temp->llink==NULL)
            {
                temp->llink=new;
                return r;
            }
            temp=temp->llink;
        }
        else if(ele>temp->data)
        {
            if(temp->rlink==NULL)
            {
                temp->rlink=new;
                return r;
            }
            temp=temp->rlink;
        }
        else
            break;
    }
    if(ele<temp->data)
        temp->llink=new;
    else if(ele>temp->data)
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
    printf("\n");
    preorder(r->llink);
    preorder(r->rlink);
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
int b_search_tree(int key,bnode* root)
{
    bnode *temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)
            return 1;
        if(key<temp->data)
            temp=temp->llink;
        else
            temp=temp->rlink;
    }
    return -1;
}