#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    printf("enter no of strings\n");
    scnaf("%d",&n);
    char str[n][20];
    for(int i=0;i<n;i++)
    {
        printf("enter the string %d",i+1);
        scanf("%s",str[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("string %d is %s\n",i+1,str[i]);
    }
    return 0;
}