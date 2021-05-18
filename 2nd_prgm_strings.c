#include<stdio.h>
void readstr();
void matchpattern();
int flag=0,i,j,k,l,p;
char str[100],pat[100],rep[100],ans[100];

void main()
{
    readstr();
    matchpattern();
    if(flag==0)
    {
        printf("Pattern not found\n");
    }
    else
    {
        printf("The resultant string is:\n%s\n",ans);
    }
}

void readstr()
{
    printf("Enter the string: \n");
    scanf("%[^\n]",str);
    printf("Enter the pattern string: \n");
    scanf("%*c%[^\n]",pat);
    printf("Enter the replace string: ");
    scanf("%*c%[^\n]",rep);
}

void matchpattern()
{
    while(str[i]!='\0')
    {
        if(str[j]==pat[p])
        {
            j++;
            p++;
            if(pat[p]=='\0')
            {
                flag=1;
                for(k=0;rep[k]!='\0';k++)
                {
                    ans[l]=rep[k];
                    l++;
                }
                i=j;
                p=0;
            }
        }
        else
        {
            ans[l]=str[i];
            l++;
            i++;
            j=i;
            p=0;
        }
    }
    ans[l]='\0';
}
