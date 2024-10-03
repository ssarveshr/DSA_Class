#include<stdio.h>
#include<string.h>
int main()
{
    char s1[10],s2[10];
    printf("enter 1 strings :\n");
    gets(s1);
    int i=0;
    while(s1[i]!='\0')
    {
        s2[i++]=s1[i];
    }
    s2[i]='\0';
    puts(s2);
}