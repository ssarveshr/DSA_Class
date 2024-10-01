#include<stdio.h>

struct student 
{
    int r_no;
    char name[10];
    float fee;
};


void display(float f);
void display_all(struct student s);

int main()
{
    struct student std={11,"RAM",17.5};
    struct student *sp=&std;
    display(std.fee);
    display_all(std);
    printf("display using pointer\n");
    printf("%d %s %f\n",sp->r_no,sp->name,sp->fee);
}
void display(float f)
{
    printf("%f\n",f);
}
void display_all(struct student s)
{
    printf("details are \n");
    printf("%d %s %f\n",s.r_no,s.name,s.fee);
}