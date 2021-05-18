#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 20
char stack[max];
int top=-1;
void push(char elem)
{
    stack[++top]=elem;
}
char pop()
{
    return (stack[top--]);
}
int precedence(char elem)
{
    switch (elem)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':return 2;
        case '-':return 2;
        case '/':return 3;
        case '*':return 3;
        case '%':return 3;
        case '^':return 4;
        default :printf("Not a valid expression\n");
        exit(0);

    }
}
void main()
{
    char ch,elem,infix[20],postfix[20];
    int i=0,k=0,pr;
    printf("Enter the infix expression:\n");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        push (ch);
        else if (isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();
                if(stack[top]=='#')
                {
                    printf("Not a valid expression\n");
                    exit(0);
                }
            }
            elem=pop();
        }
        else
        {
            pr=precedence(ch);
            if(ch=='^')
            pr++;
            while(precedence(stack[top])>=pr)
            postfix[k++]=pop();
            push(ch);
        }

    }
    while(stack[top]!='#')
    postfix[k++]=pop();
    postfix[k++]='\0';
    printf("Given infix expression:%s\nPostfix expression:%s\n",infix,postfix);
}
