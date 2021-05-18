#include<stdio.h>
#include<stdlib.h>
#define max 4
int rear=-1,front=-1;
char queue[max],item;
void insert()
{
    if(front==(rear+1)%max)
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        rear=(rear+1)%max;
        printf("Enter the item to be inserted:");
        scanf("%*c%c",&item);
        queue[rear]=item;
        printf("Item inserted:%c",item);
        if (front==-1)
        front++;
    }
}

void delete()
{
    if (front==-1)
    printf("Queue underflow\n");
    else
    {
        item=queue[front];
        printf("Item deleted:%c",item);
        if (front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%max;
        }
    }
}
void display()
{
    int i;
    if (front==-1)
    {
        printf("queue is empty!\n");
    }
    else
    {
        printf("Elements of queue are:\n");
        i=front;
        while(i!=rear)
        {
            printf("%c\n",queue[i]);
            i=(i+1)%max;
        }
        printf("%c",queue[i]);
        printf("\n");
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("Circular queue operations:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("Invalid operation\n");
        }
    }
}
