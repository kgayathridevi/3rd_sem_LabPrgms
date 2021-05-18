#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coef,expox,expoy,expoz;
    struct node *link;
};
typedef struct node *NODE;
NODE insert_rear(int coef,int x,int y,int z,NODE head);
NODE polyadd(NODE a,NODE b);

NODE createheadnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coef=0;
    temp->expox=-1;
    temp->expoy=-1;
    temp->expoz=-1;
    temp->link=temp;
    return temp;
}

NODE create(int coef,int expox,int expoy,int expoz)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coef=coef;
    temp->expox=expox;
    temp->expoy=expoy;
    temp->expoz=expoz;
    temp->link=NULL;
    return temp;
}

NODE createpoly(NODE head)
{
    int i,n;
    int coef,expox,expoy,expoz;
    printf("Enter the number of terms in polynomial:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the coefficient:\n");
        scanf("%d",&coef);
        printf("Enter the exponents of x,y and z\n");
        scanf("%d%d%d",&expox,&expoy,&expoz);
        head=insert_rear(coef,expox,expoy,expoz,head);
    }
    return head;
}

NODE insert_rear(int coef,int x,int y,int z,NODE head)
{
    NODE temp,cur;
    temp=create(coef,x,y,z);
    if(head->link==head)
    head->link=temp;
    else
    {
        cur=head;
        while(cur->link!=head)
        cur=cur->link;
        cur->link=temp;
    }
    temp->link=head;
    head->coef=head->coef+1;
    return head;
}

void display(NODE head)
{
    NODE cur;
    if (head->link==head)
    printf("List is Empty\n");
    else
    {
        cur=head->link;
        while(cur!=head)
        {
            if(cur->coef<0)
            printf("%dx^%dy^%dz^%d",cur->coef,cur->expox,cur->expoy,cur->expoz);
            else
            printf("+%dx^%dy^%dz^%d",cur->coef,cur->expox,cur->expoy,cur->expoz);
            cur=cur->link;
        }
        printf("\nNumber of terms=%d\n",head->coef);
    }
}

double evaluate(int x,int y,int z,NODE head)
{
    double result =0.00;
    NODE cur;
    if (head->link==head)
    printf("List is Empty\n");
    else
    {
        cur=head->link;
        while (cur!=head)
        {
            result+= cur->coef*pow(x,cur->expox)*pow(y,cur->expoy)*pow(z,cur->expoz);
            cur=cur->link;
        }
    }
    return result;
}

NODE polyadd(NODE a,NODE b)
{
    NODE starta,startb,c;
    int sum=0;
    starta =a;
    startb=b;
    a=a->link;
    b=b->link;
    c=createheadnode();
    while((a!=starta)&&(b!=startb))
    {
        if ((a->expox==b->expox)&&(a->expoy==b->expoy)&&(a->expoz==b->expoz))
        {
            sum=a->coef+b->coef;
            c=insert_rear(sum,a->expox,a->expoy,a->expoz,c);
            a=a->link;
            b=b->link;
        }
        else if(a->expox>b->expox)
        {
            c=insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else if((a->expox==b->expox)&&(a->expoy>b->expoy))
        {
            c=insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else if((a->expox==b->expox)&&(a->expoy==b->expoy)&&(a->expoz>b->expoz))
        {
            c=insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else
        {
            c=insert_rear(b->coef,b->expox,b->expoy,b->expoz,c);
            b=b->link;
        }
    }
    while(a!=starta)
    {
        c=insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
        a=a->link;
    }
    while(b!=startb)
    {
        c=insert_rear(b->coef,b->expox,b->expoy,b->expoz,c);
        b=b->link;
    }
    return c;
}

void main()
{
    int x,y,z;
    double result=0.00;
    NODE poly1=NULL,poly2=NULL,polysum=NULL;
    printf("Polynomial Evaluation\n");
    poly1=createheadnode();
    poly1=createpoly(poly1);
    display(poly1);
    printf("Enter the values for x,y,z\n");
    scanf("%d%d%d",&x,&y,&z);
    result=evaluate(x,y,z,poly1);
    printf("%f",result);
    poly1=NULL;
    poly1=createheadnode();
    poly1=createpoly(poly1);
    poly2=createheadnode();
    poly2=createpoly(poly2);
    display(poly1);
    display(poly2);
    polysum=polyadd(poly1,poly2);
    display(polysum);
}
