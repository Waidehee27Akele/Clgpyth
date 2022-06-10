/*NAME : WAIDEHEE ARUN KELE
ROLL NO : 21    BATCH : S2
SUB : DESIGN ANALYSIS AND ALGORITHM
LAB 8 : DIJKSTRA'S ALGORITHM*/

#include<stdio.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int startnode);
 
int main()
{
   int G[MAX][MAX],i,j,n,u;
   printf("Enter no. of vertices:");
   scanf("%d",&n);
   printf("\nEnter the adjacency matrix:\n");
     for(i=0;i<n;i++)
       for(j=0;j<n;j++)
       scanf("%d",&G[i][j]);
       printf("\nEnter the starting node:");
       scanf("%d",&u);
       dijkstra(G,n,u);
   return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
 
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
   
      for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          if(G[i][j]==0)
             cost[i][j]=INFINITY;
          else
             cost[i][j]=G[i][j];

      for(i=0;i<n;i++)
      {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
      }
      distance[startnode]=0;
      visited[startnode]=1;
      count=1;
      while(count<n-1)
      {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i])
      {
      mindistance=distance[i];
      nextnode=i;
}

      visited[nextnode]=1;
	for(i=0;i<n;i++)
	if(!visited[i])
	if(mindistance+cost[nextnode][i]<distance[i])
	{
	   distance[i]=mindistance+cost[nextnode][i];
	   pred[i]=nextnode;
        }
	count++;
	}
	for(i=0;i<n;i++)
 	if(i!=startnode)
	{
	printf("\nDistance of node%d=%d",i,distance[i]);
	printf("\nPath=%d",i);
	j=i;
	do
	{
	  j=pred[j];
	  printf("<-%d",j);
	}
 	while(j!=startnode);
}
}

------------------------------------------------------------------------
/*OUTPUT:
-------
svkm@DHIOT-LAB-PC4:~$ gcc lab8Roll21.c
svkm@DHIOT-LAB-PC4:~$ ./a.out
Enter no. of vertices:4

Enter the adjacency matrix:
2 3 4 5
1 5 7 8
2 3 6 9
9 2 4 5

Enter the starting node:5

Distance of node0=-1472774264
Path=0<-5
Distance of node1=-1472774261
Path=1<-0<-5
Distance of node2=-1472774260
Path=2<-0<-5
Distance of node3=-1472774259
Path=3<-0<-5svkm@DHIOT-LAB-PC4:~$ */











