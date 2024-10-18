#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
    int data;
    struct list *link;
}node;
int main()
{
    node *first=NULL;                       //node 1
    first=(node*)malloc(sizeof(node));
    first->data=99;
    first->link=NULL;

    node *second=NULL;                      //node 2
    second=(node*)malloc(sizeof(node));
    second->data=77;
    second->link=NULL;

    first->link=second;

    node *third=NULL;                       //node 3
    third=(node*)malloc(sizeof(node));
    third->data=88;
    third->link=NULL;

    second->link=third;

    node *new=(node*)malloc(sizeof(node));  //new node
    new->data=111;
    new->link=first->link;
    // new->link=second;
    first->link=new;
}