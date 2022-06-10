/*NAME : WAIDEHEE ARUN KELE
ROLL NO : 21     BATCH : S2
SUB : DESIGN ANALYSIS AND ALGORITHM
LAB 6 : WARSHAL'S ALGORITHM */

#include<stdio.h>
int main()
{
      int i,j,k,n;
      int a[4][4];
      printf("\n Enter the number of Vertices\n");
      scanf("%d",&n);
      printf("\n Enter the Adjacency Matrix\n");
           for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
               scanf("%d",&a[i][j]);

               for(k=1;k<=n;k++)
                   for(i=1;i<=n;i++)
                       for(j=1;j<=n;j++)
                          a[i][j]=a[i][j] || a[i][k] && a[k][j];
                          printf("\n\t The Tranitive Closure is\n");
                   for(i=1;i<=n;i++)
                   {
                       for(j=1;j<=n;j++) 
                       printf("\t %d",a[i][j]);
                       printf("\n");
                   }
}
------------------------------------------------------------------------
OUTPUT:
--------

svkm@DHIOT-LAB-PC4:~$ gcc PractWarshall.c
svkm@DHIOT-LAB-PC4:~$ ./a.out

 Enter the number of Vertices
4

 Enter the Adjacency Matrix
1 2 3 4
2 3 4 5
4 5 6 7
2 8 5 4

	 The Tranitive Closure is
	 1	 1	 1	 1
	 1	 1	 1	 1
	 1	 1	 1	 1
	 1	 1	 1	 1
*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)

