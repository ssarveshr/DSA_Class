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
    char USN[20];
    char name[20];
    char programm[20];
    char sem[20];
    struct student_node *link;
}node;
node* getnode();
node* insert_front(char[],char[],char[],char[],node*);
node* delete_front(node*);
node* insert_rear(char[],char[],char[],char[],node*);
node* delete_rear(node*);
void display(node*);
int main()
{
    node *first=NULL;
    int ch;
    char student_name[20],student_USN[20],student_prog[20],student_sem[20];
    while(1)
    {
        printf("\n");
        printf("\n");
        printf("1) insert data at rear \n");
        printf("2) insert data at front \n");
        printf("3) Remove data at rear )\n");
        printf("4) Remove data at front )\n");
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
                    scanf("%s",student_name);
                    printf("Enter the USN of the : ");
                    scanf("%s",student_USN);
                    printf("Enter the program of the student : ");
                    scanf("%s",student_prog);
                    printf("Enter the semester of the student : ");
                    scanf("%s",student_sem);
                    first=insert_rear(student_name,student_USN,student_prog,student_USN,first);
                    printf("\n");
                    printf("Database updated\n\n");
                    break;
            case 2: printf("\n");
                    printf("Enter the name of the student : ");
                    scanf("%s",student_name);
                    printf("Enter the USN of the : ");
                    scanf("%s",student_USN);
                    printf("Enter the program of the student : ");
                    scanf("%s",student_prog);
                    printf("Enter the semester of the student : ");
                    scanf("%s",student_sem);
                    first=insert_front(student_name,student_USN,student_prog,student_USN,first);
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
    if(new==NULL)
        return NULL;
    return new;
}
node* insert_front(char n[],char u[],char p[],char s[],node* f)
{
    node* node=getnode();
    strcpy(node->name,n);
    strcpy(node->USN,u);
    strcpy(node->programm,p);
    strcpy(node->sem,s);
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
node* insert_rear(char n[],char u[],char p[],char s[],node *f)
{    
    if(f==NULL)
    {
        printf("Database empty\n");
        return f;
    }
    node* temp=f;
    node* node=getnode();
    strcpy(node->name,n);
    strcpy(node->USN,u);
    strcpy(node->programm,p);
    strcpy(node->sem,s);
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
    do
    {
        printf("Name : %s\n",temp->name);
        printf("USN : %s\n",temp->USN);
        printf("PROGRAMME : %s\n",temp->programm);
        printf("SEMESTER : %s\n",temp->sem);
        temp=temp->link;
        i++;
        printf("\n");
    }
    while(temp!=NULL);
}