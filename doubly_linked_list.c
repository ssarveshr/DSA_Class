#include<stdio.h>
#include<stdlib.h>

typedef struct double_list
{
    int data;
    struct double_list* llink;
    struct double_list* rlink;
}dnode;
