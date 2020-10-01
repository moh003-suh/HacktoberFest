#include<stdio.h>
#include<stdlib.h>

int count = 0;

void DFS(int a[20][20], int n, int visited[20], int source)
{
    int i;
    count++;
    visited[source]=count;
    for(i=1; i<=n; i++)
    {
        if(a[source][i]==1 && visited[i]==0)
        {
            DFS(a,n,visited,i);
        }
    }
}

int main()
{
    int n, a[20][20], i, j, visited[20], source, visitorder[200];
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the matrix \n");
    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
    
    for(i=1;i<=n;i++)
        visited[i]=0;
    
    printf("Enter the source node\n");
    scanf("%d",&source);
    DFS(a, n, visited, source);

    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            DFS(a,n,visited,i);
        }
    }
    for(i=1;i<=n;i++)
    {
        visitorder[visited[i]]=i;
    }
    printf("DFS traversal is: \n");
    for(i=1;i<=n;i++)
    {
        printf("%c\t",64+visitorder[i]);
    }
}