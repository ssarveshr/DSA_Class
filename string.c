#include<stdio.h>
#include<string.h>
int main()
{
    char str[]={'h','e','l','l','o','\0'};
    char str1[]="hello";
    char *s="hello";
    puts(s);
    printf("%c\n",str[4]);
    printf("%c\n",str1[4]);
    printf("%d",strlen(str));
    return 0;
}