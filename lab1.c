#include <stdio.h>
#include <stdlib.h>
#define days 7
typedef struct day
{
    char *dname;
    int date;
    char *desc;
}plan;

int main()
{
    int size;
    printf("Enter the number of days :");
    scanf("%d",size);
    plan *cal=(plan *)malloc(sizeof(plan)*size);
    if(cal==NULL)
    {
        printf("No memory allocated \n");
        exit(0);
    }
    read(cal,size);
    display(cal,size);
    return 0;
}
void read(plan *c,int s)
{
    for (int i = 0; i < days; i++)
    {
        c[i].dname = (char*) malloc (sizeof(char) * 10);
        c[i].desc = (char*) malloc(sizeof(char) * 100);
        printf("Enter day (name) : ");
        scanf("%s", c[i].dname);
        printf("Enter date : ");
        scanf("%d", &c[i].date);
        printf("Enter desc : ");
        scanf("%s", c[i].desc);
        printf("\n");
    }
}
void display(plan* P)
{
    printf("\n\n Activity plan for %d days is : \n\n", days);
    for (int i = 0; i < days; i++)
    {
        printf("Name of Day : %s\n", P[i].nday);
        printf("Date of Day : %d\n", P[i].dday);
        printf("DESC : %s\n", P[i].desc);
        printf("\n");
    }
}