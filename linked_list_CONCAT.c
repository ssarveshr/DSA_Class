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
int main()
{
    node* first_1=(node*)malloc(sizeof(node));
    node* first_2=(node*)malloc(sizeof(node));

    first_1->data=99;
    first_1->link=NULL;
    first_2->data=100;
    first_2->link=NULL;

    node *second_1=NULL;                      //node 2
    second_1=(node*)malloc(sizeof(node));
    second_1->data=77;
    second_1->link=NULL;
    node *second_2=NULL;                      //node 2
    second_2=(node*)malloc(sizeof(node));
    second_2->data=77;
    second_2->link=NULL;

    first_1->link=second_1;
    first_2->link=second_2;

    node *third_1=NULL;                       //node 3
    third_1=(node*)malloc(sizeof(node));
    third_1->data=88;
    third_1->link=NULL;
    node *third_2=NULL;                       //node 3
    third_2=(node*)malloc(sizeof(node));
    third_2->data=88;
    third_2->link=NULL;

    second_1->link=third_1;
    second_2->link=third_2;
    node* temp=first_1;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
    free(temp);
    temp=first_2;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
    free(temp);
    
    first_1=concat(first_1, first_2);
    temp=first_1;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}