#include <stdio.h>
#include <stdlib.h>
#define days 7

typedef struct activity
{
    char* nday;
    int dday;
    char* desc;
}plan;


plan* create();
void read(plan*);
void display(plan*);

int main()
{
    plan* cal = NULL;
    cal = create();
    read(cal);
    display(cal);
    return 0;
}

plan* create()
{
    plan* t = NULL;
    t = (plan*) malloc(days * sizeof(plan));
    if (t == NULL)
    {
        printf("Memory not Allocated");
        return 0;
    }
    return t;
}

void read(plan* P)
{
    for (int i = 0; i < days; i++)
    {
        P[i].nday = (char*) malloc (sizeof(char) * 10);
        P[i].desc = (char*) malloc(sizeof(char) * 100);
        printf("Enter day (name) : ");
        scanf("%s", P[i].nday);
        printf("Enter date : ");
        scanf("%d", &P[i].dday);
        printf("Enter desc : ");
        scanf("%s", P[i].desc);
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
