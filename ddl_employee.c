/*
WAP to implement DDL with following data feilds for the employee record 
    1.SSN()
    2.name
    3.department 
    4.designation
    5.salary
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct EMPLIST 
{
    char SSN[10];
    char name[10];
    char dept[10];
    char desig[10];
    float sal;
    struct EMPLIST *rlink;
    struct EMPLIST *llink;
}enode;
typedef struct EMPHEAD
{
    int data;
    enode *rlink;
    enode *llink;
}ehead;
ehead *insert_front(ehead *);
ehead *insert_rear(ehead *);
ehead *delete_front(ehead *);
ehead *delete_rear(ehead *);
ehead *del_specific(ehead *);
enode *getnode();
void display(ehead *);
int main()
{
    ehead *head=(ehead*)malloc(sizeof(ehead));
    head->data=0;
    head->llink=head->rlink=NULL;
    int ch;
    // enode *first;
    // char n[10],s[10],d[10],dg[10];
    // float sar;
    while(1)
    {
        printf("1.insert front\n");
        printf("2.insert rear\n");
        printf("3.delete front\n");
        printf("4.delete rear\n");
        printf("5.delete specific element\n");
        printf("6.traverse\n");
        printf("7.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch) 
        {
            case 1: head=insert_front(head);
                    break;
            case 2: head=insert_rear(head);
                    break;
            case 3: head=delete_front(head);
                    break;
            case 4: head=delete_rear(head);
                    break;
            case 5: head=del_specific(head);
                    break;
            case 6: display(head);
                    break;
            case 7:exit(0);
        }
    }
}
enode *getnode()
{
    enode *temp=(enode *)malloc(sizeof(enode));
    if(temp==NULL)
        printf("Memory not allocated \n");
    return temp;
    
}

ehead* insert_front(ehead *head)
{
    enode *new=getnode();
    printf("enter the details :");
    printf("enter the SSN,Name,Dept,Designation,Salary");
    scanf("%s %s %s %s %f",new->SSN,new->name,new->dept,new->desig,&new->sal);
    new->llink=new->rlink=NULL;
    if(head->rlink==NULL)
    {
        head->rlink=new;
        new->llink=(enode*)head;
        head->data+=1;
        if(head->data==1)
            new->rlink=NULL;
        return head;
    }
    new->rlink=head->rlink;
    head->rlink=new;
    new->llink=(enode*) head;
    new->rlink->llink=new;
    head->data+=1;
    if(head->data==1)
        new->rlink=NULL;
    return head;
}
ehead *insert_rear(ehead *head)
{
    enode *new=getnode();
    printf("enter details :\n");
    printf("enter the SSN,Name,Dept,Designation,Salary");
    scanf("%s %s %s %s %f",new->SSN,new->name,new->dept,new->desig,&new->sal);
    new->llink=new->rlink=NULL;
    if(head->rlink==NULL)
    {
        head->rlink=new;
        new->llink=(enode*)head;
        head->data+=1;
        return head;
    }
    enode* temp=head->rlink;
    while(temp->rlink!=NULL)
    {
        temp=temp->rlink;
    }
    temp->rlink=new;
    new->llink=temp;
    head->data+=1;
    return head;
}
ehead *delete_front(ehead *head)
{
    if(head->rlink==NULL)
    {
        printf("List empty");
        return head;
    }
    enode* temp=head->rlink;
    head->rlink=temp->rlink;
    temp->rlink->llink=(enode*)head;
    head->data-=1;
    if(head->data==1)
        head->rlink->rlink=NULL;
    printf("\nFront node deleted\n");
    return head;

}
ehead *delete_rear(ehead *head)
{
    enode*prev=NULL;
    enode*present=head->rlink;
    if(present==NULL)
    {
        printf("list empty\n");
        return head;
    }
    while(present->rlink!=NULL)
    {
        prev=present;
        present=present->rlink;
    }
    printf("\nRear node deleted\n");
    prev->rlink=NULL;
    head->data--;
    return head;
}
ehead *del_specific(ehead *head)
{
    if(head->rlink==NULL)
    {
        printf("list empty cannot deleted\n");
        return head;
    }
    char search_ssn[10];
    printf("enter SSN to be deleted : ");
    scanf("%s",search_ssn);
    int flag=0;
    enode*present=head->rlink;
    enode*prev=NULL;

    while(present!=NULL)
    {
        if(strcmp(search_ssn,present->SSN)==0)
        {
            printf("SSN found and deleted\n");
            if(present->rlink==NULL)
            {
                if(prev==NULL)
                    head->rlink=NULL;
                else
                    prev->rlink=NULL;
            }
            else
            {
                prev->rlink=present->rlink;
                present->rlink->llink=prev;
            }
            flag=1;
            break;
        }
        prev=present;
        present=present->rlink;
    }
    if(flag==0)
        printf("SSN not found in list\n");
    return head;
}
void display(ehead *head)
{
    enode *temp=head->rlink;
    int cnt=0;
    if(temp==NULL)
    {
        printf("List empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\n",cnt++);
        printf("Social Security Number : %s\n",temp->SSN);
        printf("Name : %s\n",temp->name);
        printf("Department : %s\n",temp->dept);
        printf("Designation : %s\n",temp->desig);
        printf("Salary : %f\n\n",temp->sal);
        temp=temp->rlink;
    }
}