#include<stdio.h>

typedef struct 
{
    float coef;
    int exp;
}POLY;

int avail=0;

void addpoly(int,int,int,int,int *,int *,POLY[]);
void readpoly(int,int,POLY[]);
void printpoly(int,int,POLY[]);
int comp(int a,int b)
{
    if(a==b)
        return 0;
    else if (a>b)
        return  1;
    else
        return -1;
}

void attach(float cf,int ex,POLY T[])
{
    T[avail].coef=cf;
    T[avail].exp=ex;
    avail++;
}

int main()
{
    POLY terms[10];
    int SA=0,FA,SB,na,nb,SD,FD,FB;
    printf("no of terms in 1st polynomial : ");
    scanf("%d",&na);
    readpoly(na,SA,terms);
    FA=na-1;
    SB=na;
    printf("enter no of terms in 2nd polynomial : ");
    scanf("%d",&nb);
    FB=na+nb-1;
    readpoly(FB+1,SB,terms);
    printf("the first polynomial \n");
    printpoly(SA,FA,terms);
    printf("the second polynomial \n");
    printpoly(SB,FB,terms);
    avail=na+nb;
    addpoly(SA,FA,SB,FB,&SD,&FD,terms);
    printf("sum of the two polynomials \n");
    printpoly(SD,FD,terms);
    return 0;
}

void readpoly(int no,int s,POLY t[])
{
    printf("enter the coefficeint exponent: \n");
    for(int i=s;i<no;i++)
    {
        scanf("%f %d",&t[i].coef,&t[i].exp);
    }
}

void addpoly(int sa,int fa,int sb,int fb,int* sd,int* fd,POLY t[])
{
    float cof;
    *sd=avail;
    while((sa<=fa)&&(sb<=fb))
    {
        switch (comp(t[sa].exp,t[sb].exp))
        {
            case -1:attach(t[sb].coef,t[sb].exp,t);
                    sb++;
                    break;
            case 0:cof=t[sa].coef+t[sb].coef;
                   if(cof)
                   {
                    attach(cof,t[sb].exp,t);
                   }
                   sa++;
                   sb++;
                   break;
            case 1:attach(t[sa].coef,t[sb].exp,t);
                   sa++;
                   break;
        }
    }
    if(sa<=fa)
    {
        for(;sa<=fa;sa++)
        {
            attach(t[sa].coef,t[sa].exp,t);
        }
    }
    if(sb<=fb)
    {
        while(sb<=fb)
        {
            attach(t[sb].coef,t[sb].exp,t);
        }
        *fd=avail-1;
    }
}
void printpoly(int s,int f,POLY t[])
{
    printf("polynomial : \n");
    printf("%0.2f X^(%d) + ",t[0].coef,t[0].exp);
    for(int i=s+1;i<=f;i++)
    {
        printf("%0.2f X^(%d) + ",t[i].coef,t[i].exp);
    }
    printf("\n");
}