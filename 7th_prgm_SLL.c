#include<stdio.h>
#include<stdlib.h>
struct node
{
    int sem;
    char name[20],branch[20],usn[20],phone_no[20];
    struct node *link;
};
typedef struct node *NODE;
NODE first=NULL;
int count=0;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE create()
{
    NODE temp;
    temp=getnode();
    
}