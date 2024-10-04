#include<stdio.h>
#include<string.h>
int main()
{
    char s1[20],s2[10];
    printf("enter 2 strings :\n");
    gets(s1);
    gets(s2);
    int i=0;
    while(s1[i]!='\0')
    {
        i++;
    }
    s1[i]=' ';
    i++;
    int j=0;
    while(s2[j]!='\0')
    {
        s1[i++]=s2[j++];
    }
    s1[i]='\0';
    puts(s1);
}