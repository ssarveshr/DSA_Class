//cicular singly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct clist
{
    int data;
    struct clist* link;
}cnode;
cnode *ins_front(int ele,cnode* last);
cnode *del_front(cnode* last);
cnode *getnode();
int main()
{
    cnode *last=NULL;
    int ch;
    while(1)
    {
        printf("1.insert front\n");
        printf("1.delete front\n");
        printf("your choose : ");
        scanf("%d",&ch);
        int ele;
        switch(ch)
        {
            case 1: printf("enter the element : ");
                    scanf("%d",ele);
                    last=ins_front(ele,last);
                    printf("element inserted\n");
            case 2: last=del_front(last);
                    break;
            case 3: //code
                    break;
        }
    }
    return 0;
}
cnode *getnode()
{
    cnode *temp=(cnode*)malloc(sizeof(cnode));
    if(temp==NULL)
    {
        printf("no memmory allocated \n");
        return NULL;
    }
    return temp;
}
cnode *ins_front(int ele,cnode* last)
{
    cnode* new=getnode();
    new->data=ele;
    new->link=NULL;
    if(last==NULL)
    {
        new->link=new;
        return new;
    }
    new->link=last->link;
    last->link=new;
    return last;
}
cnode *del_front(cnode* last)
{
    if(last=NULL)
    {
        printf("list is empty\n");
        return last;
    }
    if(last->link==last)
    {
        printf("deleted element is %d\n",last->data);
        return NULL;
    }
    cnode* temp=last->link;
    printf("deleted element is %d",temp->data);
    last->link=temp->link;
    free(temp);
    return last;
}