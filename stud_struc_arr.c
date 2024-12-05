//wap that accepts student details including r_no name and 
//fee for n students.write a c functions wheather a key name 
//which is accepted by user is found in the record or not. 
#include<stdio.h>
#include<string.h>
struct student 
{
    int r_no;
    char name[10];
    float fee;

};

int search(char [],struct student[] ,int);

int main()
{
    struct student std[10];
    char key[10];
    int n,res;
    printf("enter number of students\n");
    scanf("%d",&n);
    printf("enter the details for N students\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%s%f",&std[i].r_no,std[i].name,&std[i].fee);
    }
    printf("the details are\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %s %f\n",std[i].r_no,std[i].name,std[i].fee);
    }
    printf("enter the key name to be searched");

    // gets(key) not working ;
    scanf("%s",key);
    res=search(key,std,n);
    if(res)
    {
        printf("key found\n");
    }
    else
    {
        printf("key not found\n");
    }
}

int search(char kname[],struct student st[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(!(strcmp(kname,st[i].name)))
        {
            flag=1;
            return flag;
        }
    }
    return flag;
}