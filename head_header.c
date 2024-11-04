#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list* link;
}node;

struct header
{
    int hdata;
    struct list*link;
};