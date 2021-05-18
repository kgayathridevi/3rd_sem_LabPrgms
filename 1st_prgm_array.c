#include<stdio.h>
#include<stdlib.h>
int a[10],n,elem,pos,i;

void create()
{
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}

void display()
{
    if (n==0)
    {
        printf("Empty Array\n");
    }
    else
    {
        printf("The array elements are\n");
        for(i=0;i<n;i++)
        {
            printf("%d\t",a[i]);
        }
    } 
}

void insertion()
{
    if (n==0)
    printf("Empty array\n");
    else
    {
        printf("Enter the position of elements to be inserted: ");
        scanf("%d",&pos);
        
        if(pos>=0 && pos<=n)
        {
            printf("Enter the element to be inserted: ");
            scanf("%d",&elem);
            for(i=n-1;i>=pos;i--)
            {
                a[i+1]=a[i];
            }
            n=n+1;
            a[pos]=elem; 
            display();
        }
        else
        {
            printf("%d is a invalid position\n",pos);
        }   
    }
}
void deletion()
{
    if(n==0)
    printf("Empty array\n");
    else
    {
        printf("Enter the position of the element to be deleted: ");
        scanf("%d",&pos);
        if(pos>=0 && pos<=n-1)
        {
            for(i=pos;i<n-1;i++)
            {
                a[i]=a[i+1];
            }
            elem = a[pos];
            n=n-1;
            display();
        }
        else
        {
            printf("%d is a invalid position\n",pos);
        }     
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n ____Menu____\n");
        printf("1.create\n2.Display\n3.Insert\n4.Deletion\n5.exit\n");
        printf("Enter your choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:insertion();
            break;
            case 4:deletion();
            break;
            case 5:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}