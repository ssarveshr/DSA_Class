#include<stdio.h>
#include<string.h>

int main()
{
    char str[10]="hello";
    const char *cstr="hello";
    puts(cstr);
    printf("%s",str);
}