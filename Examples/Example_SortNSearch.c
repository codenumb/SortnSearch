/*Example of sortser library*/
#include<stdio.h>
#include<stdlib.h>
#include"sortser.h" // includes library for mergesort fn
int main()
{
	int i,length;
	int A[]={8,3,2,55,7,4,1,6,12};int id=85;int *add;
	length=sizeof(A)/sizeof(int);// length of the array
	 mergesort(A,length);// passing array name and length to the merge fn
	 //printing sorted elements	 
	 for( i=0;i<length;i++)
 	 printf("%d ",A[i]);
 	 add=find(A,length,id);//searching
	printf("\nretun_Address=%d",add);
	return 0;
}
