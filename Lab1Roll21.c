#include<stdio.h>
int binarySearch(int array[],int x,int low,int high){
if(high>=low){
int mid=(low+high)/2;

//if found at mid then return
if (array[mid]==x)
return mid;

//search the left half
if(array[mid]>x)
return binarySearch(array,x,low,mid-1);

//Search the right half
return binarySearch(array,x,mid+1,high);
}
return-1;
}

int main(void)
{
int array[]={3,4,5,6,7,8,9};
int n=sizeof(array)/sizeof(array[0]);
int x;
printf("Enter the Element you want to search");
scanf("%d",&x);

int result = binarySearch(array,x,0,n-1);
if(result == -1)
printf("Not found");
else
printf("Element is found at index %d",result);
}


