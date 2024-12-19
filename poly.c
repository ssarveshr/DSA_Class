#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct p
{
    int coef;
    int x;
    int y;
    int z;
    struct p* link;
}poly;
poly *getnode();
poly *read_poly(int,poly*);
void print_poly(poly*);
poly* add_poly(poly*,poly*);
int main()
{
    int n1,n2;
    poly* poly1=getnode();
    poly* poly2=getnode();
    poly* poly3=getnode();
    poly1->link=poly1;
    poly2->link=poly2;
    poly3->link=poly3;
    printf("enter number of terms in poly1 : ");
    scanf("%d",&n1);

    printf("enter number of terms in poly2 : ");
    scanf("%d",&n2);
    printf("Reading Poly 1\n");
    read_poly(n1,poly1);
    printf("Reading Poly 2\n");
    read_poly(n2,poly2);

    printf("Polynomial 1\n");
    print_poly(poly1);

    printf("\nPolynomial 2\n");
    print_poly(poly2);

    printf("\n");
    printf("THE POLY\n");
    poly3=add_poly(poly1,poly2);
    print_poly(poly3);
}
poly* read_poly(int n,poly*p)
{
    poly* temp=p->link;
    for(int i=0;i<n;i++)
    {
        poly*new=getnode();
        printf("enter coeff x y z values : ");
        scanf("%d %d %d %d",&new->coef,&new->x,&new->y,&new->z);
        temp->link=new;
        temp=temp->link;
    }
    temp->link=p;
    return p;
}

void print_poly(poly*p)
{
    poly*temp=p->link;
    while(temp!=p)
    {
        printf("(%d x^%d y^%d z^%d) + ",temp->coef,temp->x,temp->y,temp->z);
        temp=temp->link;
    }
}
poly* add_poly(poly*p1,poly*p2)
{
    int flag1=0;
    poly*temp1=p1->link;
    poly*prev2=p2;
    poly*temp2=p2->link;
    while(temp1!=p1)
    {
        temp2=p2->link;
        while(temp2!=p2)
        {
            if(temp1->x==temp2->x && temp1->y==temp2->y && temp1->z==temp2->z )
            {
                temp1->coef+=temp2->coef;
                prev2->link=temp2->link;
                poly*te=temp2;
                temp2=temp2->link;
                free(te);
                continue;
            }
            prev2=temp2;
            temp2=temp2->link;
        }
        temp1=temp1->link;
    }
    temp1=p1->link;
    while(temp1->link!=p1)
        temp1=temp1->link;
    temp2=p2->link;

    while(temp2!=p2) 
    {
        poly* new_node = getnode();
        new_node->coef = temp2->coef;
        new_node->x = temp2->x;
        new_node->y = temp2->y;
        new_node->z = temp2->z;
        new_node->link = p1;
        temp1->link = new_node;
        temp1 = new_node;
        temp2 = temp2->link;
    }
    return p1;
}
poly *getnode()
{
    return (poly *)malloc(sizeof(poly));
}