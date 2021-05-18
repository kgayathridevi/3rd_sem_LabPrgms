#include<stdio.h>
void BFS(int v);
void DFS(int v);
int visited[10], reach[10],q[10], a[10][10],f=0,i,j,r=-1,n;
void main()
{
    int v;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
        reach[i]=0;
    }
    printf("Enter the adjacent matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    }
    printf("Adjacent matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&v);
    if(v<=n)
    {
        printf("DFS traversal:%d",v);
        DFS(v);
        printf("\n");
        printf("BFS traversal:%d",v);
        BFS(v);
    }
    else
    {
        printf("INvalid vertex\n");
    }
}
void DFS(int v)
{
    int i;
    visited[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]&& !visited[i])
        {
            printf("->%d",i);
            DFS(i);
        }
    }
}
void BFS(int v)
{
    int i,j;
    q[++r]=v;
    reach[v]=1;
    while(f<=r)
    {
        f=q[f++];
        for(i=1;i<=n;i++)
        {
            if(a[i][j]&& !reach[j])
            q[++r]=i;
            printf("->%d",i);
            reach[i]=1;
        }
    }
}
