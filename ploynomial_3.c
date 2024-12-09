typedef struct polynomial
{
    float coef;
    int exp_x,exp_y,exp_z;
    struct polynomail *link;
}poly;

poly *getnode();
void read_poly(poly *,int);
void print_poly(poly *);
void evaluate(poly *);

int main()
{
    int n1,n2;
    poly *head1=getnode();
    poly *head2=getnode();
    poly *head3=getnode();
    head1->link=head1;
    head2->link=head2;
    head3->link=head3;
    printf("Enter the number of terms in first polynomial: ");
    scanf("%d",&n1);
    printf("Enter the number of terms in second polynomial: ");
    scanf("%d",&n2);
    printf("Reading 1st polynomial \n");
    read_poly(head1,n1);    
    printf("Reading 2nd polynomial \n");
    read_poly(head2,n2);
    printf("The first polynomial is : ");
    print_poly(head1);
    printf("The second polynomial is : ");
    print_poly(head2);
    head3=add_poly(head1,head2);
    printf("The sum of the two polynomials is : ");
    print_poly(head3);

    //Evaluation of polynomial(Substituting x y z values in any polynomial)

    evaluate(head1);    
    // evaluate(head2);
    // evaluate(head3);
    
}
poly *getnode()
{
    poly* temp=(poly *)malloc(sizeof(poly));
    return temp;
}
void read_poly(poly *head,int n)
{
    poly *new,*temp;
    temp=head;
    for(int i=0;i<n;i++)
    {
        new=getnode();
        printf("Enter the coef x y z values : ");
        scanf("%f %d %d %d",&new->coef,&new->exp_x,&new->exp_y,&new->exp_z);
        temp->link=new;
        temp=temp->link;
    }
    temp->link=head;
}
void print_poly(poly *head)
{
    poly *temp;
    temp=head->link;
    while(temp!=head)
    {
        printf("%f x^%d y^%d z^%d  + ",temp->coef,temp->exp_x,temp->exp_y,temp->exp_z);
        temp=temp->link;
    }
}

void evaluate(poly *head)
{
    poly *temp=head->link;
    double x,y,z,sum=0.0,tx,ty,tz;
    printf("enter the values for x y z");
    scanf("%f %f %f",&x,&y,&z);
    while(temp!=head)
    {
        tx=(double)temp->exp_x;
        ty=(double)temp->exp_y;
        tz=(double)temp->exp_z;
        //incomplete
    }
}