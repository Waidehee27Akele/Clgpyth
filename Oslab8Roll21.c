#include<stdio.h>
int main()
{
    int queue[20],n,head,i,j,k,seek=0,max,diff;
    float avg;
    printf("Enter the max range of disc\n");
    scanf("%d",&max);
    printf("Enter the size of queue request\n");
    scanf("%d",&n);
    printf("Enter the queue of disk positions to be read\n");
    for(i=1;i<=n;i++)
    scanf("%d",&queue[i]);
    printf("Enter the initial head position\n");
    scanf("%d",&head);
    queue[0]=head;
    for(j=0;j<=n;j++)
    {
        diff=abs(queue[j+1]-queue[j]);
        seek+=diff;
        printf("Disc head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
    }
    printf("Total head Movement seek distance/time is %d\n",seek);
    avg=seek/(float)n;
    printf("Average seek time is %f\n",avg);
    return 0;
}

-----------------------------------------------------------------------------------------------
#OUTPUT#
-----------------------------------------------------------------------------------------------

Enter the max range of disc
50
Enter the size of queue request
6
Enter the queue of disk positions to be read
12 13 14 15 16 17 18 19 10
Enter the initial head position
Disc head moves from 18 to 12 with seek 6
Disc head moves from 12 to 13 with seek 1
Disc head moves from 13 to 14 with seek 1
Disc head moves from 14 to 15 with seek 1
Disc head moves from 15 to 16 with seek 1
Disc head moves from 16 to 17 with seek 1
Disc head moves from 17 to 32767 with seek 32750
Total head Movement seek distance/time is 32761
Average seek time is 5460.166504


...Program finished with exit code 0
Press ENTER to exit console.
