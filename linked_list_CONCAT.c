#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list* link;
}node;

node* concat(node* list1,node* list2)
{
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;

    node* temp=list1;
    while(temp->link!=NULL)
        temp=temp->link;
    
    temp->link=list2;
    return list1;
}