
#include<stdio.h>
#include<math.h>
#include<ctype.h>
int stack[50],top=-1;
void push(int elem)
{
    stack[++top]=elem;
}

void main()
{
    char postfix[20],ch;
    int i=0,op1,op2;
    printf("Enter the postfix expression: ");
    gets(postfix);
    while((ch=postfix[i++])!='\0')
    {
        if(isalpha(ch))
        {
            printf("Invalid expression\n");
            return;
        }
        else if(isdigit(ch))
        {
            push(ch-48);
        }
        else
        {
            op2=stack[top--];
            if(top<=-1)
            {
                printf("Invalid expression\n");
                return;
            }
            op1=stack[top--];
            switch(ch)
            {
                case '+':push(op1+op2);
                break;
                case '-':push(op1-op2);
                break;
                case '*':push(op1*op2);
                break;
                case '/':push(op1/op2);
                break;
                case '%':push(op1%op2);
                break;
                case '^':push(op1^op2);
                break;
                default :printf("Invalid operator\n");
                return;
            }
        }
    }
    if(top!=0)
    printf("Invalid Expression\n");
    else
    {
        printf("Result = %d\n",stack[top]);
    }
}







#include<stdio.h>
void tower(int n,char beg,char aux,char end)
{
    if(n==1)
    {
        printf("Move disk 1 from pole %c to %c \n",beg,end);
        return;
    }
    tower(n-1,beg,end,aux);
    printf("Move disk %d from pole %c to %c\n",n,beg,end);
    tower(n-1,aux,beg,end);
}
void main()
{
    int num;
    char beg,end,aux;
    printf("Enter the number of disks: ");
    scanf("%d",&num);
    printf("The sequence of moves involved in the tower of Hanoi are:\n");
    tower(num,'A','B','C');
}

