#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int size);
void insert(int arr[],int p,int k,int size);
void del(int arr[],int p,int size);
int search(int arr[],int k,int size);
int max_ele(int arr[],int size);
int sum_arr(int arr[],int size);
void sort(int arr[],int n);
int size_arr(int arr[]);
/************************************************************************************************/
int main()
{
    int choice;
    int a[50]={1,9,2,8,7,-1};
    int s=size_arr(a);
    while(1)
    {
        printf("\nenter your choice\n0) Exit\n1) insert\n2) delete\n3) sum\n4) search\n5) max elements\n6) display\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int pos,key;
                printf("enter the position for insertion : ");
                scanf("%d",&pos);
                printf("enter the key for insertions : ");
                scanf("%d",&key);
                insert(a,pos,key,s);
                break;
            }
            case 2:
            {
                int pos;
                printf("enter the position for deletion : ");
                scanf("%d",&pos);
                del(a,pos,s);
                break;
            }
            case 3:
            {
                int val=sum_arr(a,s);
                printf("sum of all the elements in the array is %d",val);
                break;
            }
            case 4:
            {
                int key;
                printf("enter the key for search : ");
                scanf("%d",&key);
                sort(a,s);
                int res=search(a,key,s);
                if(res==0)
                {
                    printf("element not found in the array");
                }
                break;
            }
            case 5:
            {
                int val=max_ele(a,s);
                printf("The max element in the array is %d",val);
                break;
            }
            case 6:
            {
                display(a,s);
                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("Invalid input!Try again");
            }
        }
    }
}
void display(int arr[],int size)
{
    size=size_arr(arr);
    size=size_arr(arr);
    printf("\n%d\n",size);
    for(int i=0;i<size;i++)
    {   
        if(arr[i]!=-1)
            printf("%d\t",arr[i]);
    }
}
int search(int arr[],int k,int size)
{
    int l=0,u=size-1;
    int mid=0,me=0;
    while(l<=u)
    {
        mid=(u+l)/2;
        if(arr[mid]==k)
        {
            printf("\n %d is found at %d \n",arr[mid],mid+1);
            me=1;
            break;
        }
        else if(arr[mid]!=k)
        {
            if(k>arr[mid])
                l=mid+1;
            else if (k<arr[mid])
                u=mid-1;
        }
    }
    return me;
}
void insert(int arr[],int p,int k,int size)
{
    //int size=sizeof(arr)/sizeof(int);
    for(int i=size+1;i>-1;i--)
    {
        if(i==(p-1))
        {
            arr[i+1]=arr[i];
            arr[i]=k;
            break;
        }
        else
        {
            arr[i+1]=0;
            arr[i+1]=arr[i];
        }
    }
    size=size_arr(arr);
    printf("\n%d\n",size);
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void del(int arr[],int p,int size)
{
    //int size=sizeof(arr)/sizeof(int);
    arr[p-1]=0;
    for(int i=0;i<size+1;i++)
    {
        if(arr[i]==0)
        {
            arr[i]=arr[i+1];
            arr[i+1]=0;
        }
    }
    size=size_arr(arr);
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int sum_arr(int arr[],int size)
{
    int sum=0;
    //int size=sizeof(arr)/sizeof(int);
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int max_ele(int arr[],int size)
{
    int lar=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>lar)
        {
            lar=arr[i];
        }
    }
    return lar;
}
void sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int size_arr(int arr[])
{
    int i=0,len=0;
    while (1)
    {
        if(arr[i]==-1)
        {
            break;
        }
        else
        {
            len+=1;
            i++;
        }
    }
    return len;
}
