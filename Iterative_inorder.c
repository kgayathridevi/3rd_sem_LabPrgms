#include<stdio.h>
#include<stdlib.h>
#define size 10
int top = -1;
struct Tree
{
 int data;
 struct Tree *lptr, *rptr;
};
typedef struct Tree *node;
node *root,*stack[size];
void push(node *temp) //function to push
{
 if(top==size-1)
 {
printf("Stack Full");
return;
 }
 stack[++top] = temp;
}
node *pop() //function to pop
{
 if(top==-1)
 {
printf("Stack Empty");
return;
 }
 return(stack[top--]);
}
void iterative_inorder(node *root)
{
 node cur = root;
 while(1)
 {
 while(cur!=NULL)
 {
push(cur);
cur= cur->lptr;
 }
 if(top == -1) break;
 cur = pop();
 printf("%d",cur->data);
 cur=cur->rptr;
 }
}

void main()
{
    node temp;
    int ch,i,n;
    printf("Enter the size\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the value");
        scanf("%d",&ch);
        

    }
}