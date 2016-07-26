#include<stdio.h>
#include<stdlib.h>
#include "sortser.h"
/*sorting*/
void mergesort(int *A,int n)
{
 int mid,i,*left,*right;
 if(n<2)
	 return;	//exit if array has single element
 mid=n/2;		// middle index
 /*create left and right sub arrays*/
  left = (int*)malloc(mid*sizeof(int)); // left sub array is 0 to mid
  right = (int*)malloc((n- mid)*sizeof(int)); // right sub array is mid to end
 for(i=0;i<mid;i++)// fill left array from parrent array(A[]
	 left[i]=A[i];
 for(i=mid;i<n;i++)// fill right array from parrent array(A[]
	 right[i-mid]=A[i];
 mergesort(left,mid);//left sub array[recursive]
 mergesort(right,n-mid);// right sub array[recursive]
 // merging left and right sub arrays;parameters are:parrent array,Left array and length,right array and length
 merge(A,left,mid,right,n-mid);
 free(left);// free up the malloc memmory
 free(right);
}
void merge(int *A,int *L,int lengthOfL,int*R,int lengthOfR)
{
/*  i=indexing left array
	j=indexing right
	k=indexing parrent array
*/	
	int i=0,j=0,k=0;	
	while(i<lengthOfL&&j<lengthOfR)
	{
		if(L[i]<R[j])
			A[k++]=L[i++];
		else
			A[k++]=R[j++];
	}
	while(i<lengthOfL)
		A[k++]=L[i++];
	while(j<lengthOfR)
		A[k++]=R[j++];
}
/*sorting_end*/

/*Searching*/
int*find(int*A,int n,int id)// array,length,and id is passing
{
	int mid;
	mid=(n)/2;	//middle index
		if(id<A[0]||id>A[n-1])
		return NULL;//if id are greater or less than min or max value in the array{exit condition}
		if(A[mid]==id)
		return &A[mid];//id found returns address{exit condition}
		else if(A[mid]>id)//if id less than middle value of the array
		find(A,mid,id);//reccursing:passing first half of the array
		else if(A[mid]<id)// if id grater than middle value of array
		find(&A[mid+1],n-(mid+1),id);//reccursing:passing second half of the array			
		else if(mid>n||mid<1)//if element not found 
		return NULL; //exit 	
}
