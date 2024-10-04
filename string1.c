#include<stdio.h>
#include<string.h>
int main()
{
    char str[15];
    printf("enter a string\n");
    gets(str);
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    printf("%d\n",i);
    printf("%d\n",strlen(str));
}