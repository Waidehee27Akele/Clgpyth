#include<stdio.h>
#define V 4
#define INF 99999

void printSolution(int dist[][V]);
void floydWarshall(int graph[][V])
{
     int dist[V][V], i, j, k;
     for (i=0; i < V; i++)
            for (j=0 ;j < V; j++)
                  dist[i][j] = graph[i][j];
     for (k=0; k < V; k++)
     {
           for(i=0; i<V; i++)
           {
                for(j=0; j<V; j++)
                {
                     if (dist[i][k] + dist[k][j] < dist[i][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
                }
           }
     }
   
     printSolution(dist);
}

void printSolution(int dist[][V])
{
        printf("The following matrix shows the shortest distances" " between every pair of vertices \n");
        
        for(int i = 0; i < V; i++)
        {
               for(int j=0; j < V; j++)
               {
                        if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	
	int graph[V][V] = { 
						{0, 3, INF, INF },
						{INF, 0, 12, 15},
						{4, INF, 0, -1},
                                                {2, -4, INF, 0}
					};

	floydWarshall(graph);
	return 0;
}




OUTPUT:
-----------

svkm@DHIOT-LAB-PC4:~$ gcc PractFloydWarshall21.c
svkm@DHIOT-LAB-PC4:~$ ./a.out
The following matrix shows the shortest distances between every pair of vertices 
      0      3     15     14
     13      0     12     11
      1     -5      0     -1
      2     -4      8      0

                    
       
