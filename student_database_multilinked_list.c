/*
*write a program to do following operations using link list 
    1) insert at front and rear
    2) delete at fromt amd rear
    3) display 
*create student marks of two subjects(two data set in each node)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student_node
{
    char name[20];
    int m1;
    int m2;
    struct student_node *link;
}node;
node* getnode();
node* insert_front(char[],int[],node*);
node* delete_front(node*);
node* insert_rear(char[],int[],node*);
node* delete_rear(node*);
void display(node*);
int main()
{
    node *first=NULL;
    int ele[2],ch;
    char sample_name[20];
    while(1)
    {
        printf("\n");
        printf("\n");
        printf("1) Enter new student data ( insert at rear )\n");
        printf("2) Enter new student data at first ( insert at front )\n");
        printf("3) Remove student data ( delete at rear )\n");
        printf("4) Remove student data at the start ( delete at front )\n");
        printf("5) Review the database of the student data ( display )\n");
        printf("6) Quit the program\n");
        printf("\n");
        printf("\n");
        printf("Enter you choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n");
                    printf("Enter the name of the student : ");
                    scanf("%s",sample_name);
                    printf("Enter the marks of the student obtained in two subjects : ");
                    scanf("%d",&ele[0]);
                    scanf("%d",&ele[1]);
                    first=insert_rear(sample_name, ele, first);
                    printf("\n");
                    printf("Database updated\n\n");
                    break;
            case 2: printf("\n");
                    printf("Enter the name of the student : ");
                    scanf("%s",sample_name);
                    printf("Enter the marks of the student obtained in two subjects : ");
                    scanf("%d",&ele[0]);
                    scanf("%d",&ele[1]);
                    first=insert_front(sample_name, ele, first);
                    printf("\n");
                    printf("Database updated\n\n");
                    break;
            case 3: printf("\n");
                    first=delete_rear(first);
                    printf("\n");
                    printf("Database updated\n\n");
                    break;
            case 4: printf("\n");
                    first=delete_front(first);
                    printf("\n");
                    printf("Database updated\n\n");
                    break;
            case 5: printf("\n");
                    display(first);
                    break;
            case 6: exit(0);
                    break;
            default:printf("\n");
                    printf("INVALID CHOICE!!!!\n\nPLEASE TRY AGAIN\n");
                    break;        
        }
    }
    return 0;
}
node* getnode()
{
    node *new=(node*)malloc(sizeof(node));
    new->m1=0;
    new->m2=0;
    new->link=NULL;
    if(new==NULL)
        return NULL;
    return new;
}
node* insert_front(char name[],int e[],node* f)
{
    node* node=getnode();
    node->m1=e[0];
    node->m2=e[1];
    strcpy(node->name,name);
    if(f==NULL)
    {
        node->link=NULL;
        return node;
    }
    node->link=f;
    return node;
}
node* delete_front(node* f)
{
    if(f==NULL)
    {
        printf("Database empty\n");
        return f;
    }
    node* temp=f;
    f=f->link;
    printf("%s data has been deleted\n",temp->name);
    return f;
}
node* insert_rear(char name[],int e[],node *f)
{    
    if(f==NULL)
    {
        printf("Database empty\n");
        return f;
    }
    node* temp=f;
    node* node=getnode();
    node->m1=e[0];
    node->m2=e[1];
    strcpy(node->name,name);
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=node;
    return f;
}
node* delete_rear(node* f)
{
    if(f==NULL)
    {
        printf("Database empty\n");
        return f;
    }
    node* temp=f;
    node* previous=NULL;
    while(temp->link!=NULL)
    {
        previous=temp;
        temp=temp->link;
    }
    previous->link=NULL;
    printf("%s data has been deleted\n",temp->name);
    return f;
}
void display(node* f)
{
    if(f==NULL)
    {
        printf("Database empty\n");
    }
    node* temp=f;
    int i=0;
    printf("SLNO\tNAME\t\tMARKS 1\tMARKS 2\n");
    do
    {
        printf("%d\t%s\t\t%d\t%d\n",i,temp->name,temp->m1,temp->m2);
        temp=temp->link;
        i++;
    }
    while(temp!=NULL);
}