#include<stdio.h>
#include<stdlib.h>
int *ht,c,n,m,flag;
void create()
{
    int i;
    ht=(int*)malloc(m*sizeof(int));
    if(ht==NULL||m==0)
    printf("Hash table is not present\n");
    for (i=0;i<m;i++)
    ht[i]=-1;
}

void display()
{
    int i;
    printf("The hash table is\n");
    for(i=0;i<m;i++)
    printf("[%d]->%d\n",i,ht[i]);
}

void insert(int key)
{
    int j;
    j=key%m;
    while (ht[j]!=-1)
    {
        j=(j+1)%m;
        flag=1;
    }
    if (flag)
    {
        printf("Collision is detected and it is solved by using linear probing\n");
        flag=0;
    }
    ht[j]=key;
    display();
    c++;
}

void main()
{
    int i,key;
    printf("Enter the number of employees\n");
    scanf("%d",&n);
    printf("Enter the memory size\n");
    scanf("%d",&m);
    create();
    for(i=0;i<n;i++)
    {
        if(c!=m)
        {
            printf("Enter the key\n");
            scanf("%d",&key);
            insert(key);
        }
        else
        {
            printf("The hash table is full\n");
            exit(0);
        }
    }
}
