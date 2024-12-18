#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly_node 
{
    float coeff;
    int expx, expy, expz;
    struct poly_node *link;
} POLY;

POLY *getnode();
void read_poly(int n, POLY *head);
void print_poly(POLY *head);
POLY *add_poly(POLY *h1, POLY *h2);
int COMP(POLY *t1, POLY *t2);
void attach(float cf, POLY *temp, POLY **tres);
POLY *delete_node(POLY *head, POLY *temp);
void evaluate(POLY *head);

int main() 
{
    int n1, n2;
    POLY *head1 = getnode();
    POLY *head2 = getnode();
    POLY *head3 = getnode();

    head1->link = head1;
    head2->link = head2;
    head3->link = head3;

    printf("Enter number of terms in the first and second polynomial:\n");
    scanf("%d%d", &n1, &n2);

    printf("Enter first polynomial:\n");
    read_poly(n1, head1);

    printf("Enter second polynomial:\n");
    read_poly(n2, head2);

    printf("The first polynomial:\n");
    print_poly(head1);

    printf("The second polynomial:\n");
    print_poly(head2);

    // Adding two polynomials
    head3 = add_poly(head1, head2);
    printf("Resultant polynomial:\n");
    print_poly(head3);

    // Evaluation
    printf("Evaluation of the first polynomial:\n");
    evaluate(head1);
    printf("\n");
}

POLY *getnode() 
{
    POLY *temp = (POLY *)malloc(sizeof(POLY));
    return temp;
}

void read_poly(int n, POLY *head) 
{
    POLY *newN, *temp;
    int i;

    temp = head;
    for (i = 0; i < n; i++) 
    {
        newN = getnode();
        printf("Enter coefficient and exponents (x, y, z):\n");
        scanf("%f%d%d%d", &(newN->coeff), &(newN->expx), &(newN->expy), &(newN->expz));
        temp->link = newN;
        temp = temp->link;
    }
    temp->link = head;
}

void print_poly(POLY *head) 
{
    POLY *temp = head->link;
    while (temp != head) 
    {
        printf("(%2.2fx^%dy^%dz^%d) + ", temp->coeff, temp->expx, temp->expy, temp->expz);
        temp = temp->link;
    }
    printf("\n");
}

POLY *add_poly(POLY *h1, POLY *h2) 
{
    POLY *temp1, *temp2;
    POLY *result = getnode();
    POLY *tempres = result;
    double sum;

    temp1 = h1->link;
    while (temp1 != h1) 
    {
        temp2 = h2->link;
        while (temp2 != h2) 
        {
            switch (COMP(temp1, temp2)) 
            {
                case 1: // Exponents are equal
                    sum = temp1->coeff + temp2->coeff;
                    if (sum)
                        attach(sum, temp1, &tempres);
                    h2 = delete_node(h2, temp2);
                    temp2 = h2->link;
                    temp1 = temp1->link;
                    break;
                case -1: // Exponents are unequal
                    temp2 = temp2->link;
                    break;
            }
        }
        if (temp1 != h1) 
        {
            attach(temp1->coeff, temp1, &tempres);
            temp1 = temp1->link;
        }
    }

    temp2 = h2->link;
    while (temp2 != h2) 
    {
        attach(temp2->coeff, temp2, &tempres);
        temp2 = temp2->link;
    }

    tempres->link = result;
    return result;
}

int COMP(POLY *t1, POLY *t2) 
{
    if ((t1->expx == t2->expx) && (t1->expy == t2->expy) && (t1->expz == t2->expz))
        return 1;
    else
        return -1;
}

void attach(float cf, POLY *temp, POLY **tres) 
{
    POLY *newN = getnode();
    newN->coeff = cf;
    newN->expx = temp->expx;
    newN->expy = temp->expy;
    newN->expz = temp->expz;
    (*tres)->link = newN;
    *tres = newN;
}

POLY *delete_node(POLY *head, POLY *temp) 
{
    POLY *prev, *pres;
    prev = head;
    pres = head->link;

    while (pres != temp) 
    {
        prev = pres;
        pres = pres->link;
    }
    prev->link = pres->link;
    free(temp);
    return head;
}

void evaluate(POLY *head) 
{
    POLY *temp = head->link;
    double x, y, z, sum = 0;
    double tx, ty, tz;

    printf("Enter values of x, y, and z:\n");
    scanf("%lf%lf%lf", &x, &y, &z);

    while (temp != head) 
    {
        tx = (double)temp->expx;
        ty = (double)temp->expy;
        tz = (double)temp->expz;
        sum += ((temp->coeff) * pow(x, tx) * pow(y, ty) * pow(z, tz));
        temp = temp->link;
    }
    printf("Result:\n%lf\n", sum);
} 