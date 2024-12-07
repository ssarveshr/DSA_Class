//Linear Probing with Division Hashing
#include<stdio.h>
typedef struct employee
{
    int eno;
    char ename[18];
    int sal;
}emp;

int main()
{
    emp e;
    FILE *fp;
    int n,i,s=(2*sizeof(int)+20),M_one=-1,choice,flag,index,indexcopy,id;
    printf("enter the no of records : ");
    scanf("%d",&n);
    fp=fopen("abc.txt","w+");
    for(i=0;i<n;i++)
    {
        fwrite(&M_one,sizeof(int),1,fp);
        fseek(fp,s-sizeof(int),SEEK_CUR);
    }
    int ch;
    while(1)
    {
        printf("enter 1 for add record 2 for Display record 3 for exit\n");
        scanf("%d",&ch);
        flag=0;
        switch(ch)
        {
            case 1:

            printf("enter enum ename salary: ");
            scanf("%d %s %d",&e.eno,e.ename,&e.sal);
            index=indexcopy=(e.eno%n);
            fseek(fp,s*index,SEEK_SET);
            fread(&id,sizeof(int),1,fp);
            while(id!=-1)//Linear Probing
            {
                index++;
                flag=1;
                if(index==n)
                {
                    index=0;
                }
                if(index==indexcopy)
                {
                    printf("File Full\n");
                    break;
                }
                fseek(fp,s*index,SEEK_SET);
                fread(&id,sizeof(int),1,fp);
            }
            if(!((index==indexcopy)&&flag))
            {
                fseek(fp,s*index,SEEK_SET);
                fwrite(&e,sizeof(emp),1,fp);
            }
            break;

            case 2:
            i=0;
            for(;i<n;i++)
            {
                fseek(fp,s*i,SEEK_SET);
                fread(&e,sizeof(emp),1,fp);
                if(e.eno!=-1)
                {
                    printf("%d %d %d\n",e.eno,e.ename,e.sal);
                }
            }
            break;

        }
    }
}