#include<stdio.h>
struct file 
{
    int all[10];
    int max[10];
    int need[10];
    int flag;
};

void main() 
{
    struct file f[10];
    int avail[10], seq[10];
    int n, r, i, j, k, p, b, g, cnt = 0, id, newr;
    int f1 = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < n; i++) 
    {
        printf("Enter details for process P%d:\n", i);
        printf("Enter the allocation: ");
        for (j = 0; j < r; j++) {
            scanf("%d", &f[i].all[j]);
        }
        printf("Enter the maximum requirement: ");
        for (j = 0; j < r; j++) {
            scanf("%d", &f[i].max[j]);
        }
        f[i].flag = 0;
    }

    printf("Enter available resources: ");
    for (i = 0; i < r; i++) 
    {
        scanf("%d", &avail[i]);
    }

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < r; j++) 
        {
            f[i].need[j] = f[i].max[j] - f[i].all[j];
            if (f[i].need[j] < 0) 
            {
                f[i].need[j] = 0;
            }
        }
    }

    while (cnt < n) 
    {
        g = 0;
        for (i = 0; i < n; i++) 
        {
            if (f[i].flag == 0) 
            {
                b = 0;
                for (j = 0; j < r; j++) 
                {
                    if (avail[j] < f[i].need[j]) 
                    {
                        b = 1;
                        break;
                    }
                }
                if (b == 0) 
                {
                    printf("Process P%d is executed.\n", i);
                    seq[cnt++] = i;
                    for (j = 0; j < r; j++) 
                    {
                        avail[j] += f[i].all[j];
                    }
                    f[i].flag = 1;
                    g = 1;
                }
            }
        }
        if (g == 0) 
        {
            printf("The system is in an unsafe state.\n");
            break;
        }
    }

    if (cnt == n) 
    {
        printf("The system is in a safe state.\nSafe Sequence: ");
        for (i = 0; i < n; i++) 
        {
            printf("P%d ", seq[i]);
        }
        printf("\n");
    }
}