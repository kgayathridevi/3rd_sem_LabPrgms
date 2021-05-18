#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max],top=-1,item;

void push()
{
    if(top==(max-1))
    printf("The stack is overflow\n");
    else
    {
        printf("Enter the element to be pushed\n");
        scanf("%d",&item);
        stack[++top] = item;
    }
}

void pop()
{
    if (top==-1)
    printf("The stack is underflow\n");
    else
    {
        item=stack[top--];
        printf("The popped element is %d\n",item);
    }
}

void display()
{
    int i=0;
    if(top==-1)
    printf("The stack is empty\n");
    else
    {
        printf("the stack elements are: \n");
        for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    }
}

void palindrome()
{
    int j=top,k=0,flag=0;
    if(top==-1)
    {
        printf("The stack is empty\n");
        return;
    }
    while(k<=top/2)
    {
        if(stack[k++]!=stack[j--])
        {
            flag=1;
            break;
        }
    }
    if (flag)
    {
        printf("Stack contents are not a palindrome\n");
    }
    else
    {
        printf("Stack contents are palindrome\n");
    }
}
    
void main()
{
  while (1)
  {
    int ch=0;
    printf("\n___Menu___\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:palindrome();
        break;
        case 5:exit(0);
        break;
        default :printf("Invalid choice");
        return;
    }
  }
    
    
}