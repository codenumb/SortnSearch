
#include<stdio.h>
#include<stdlib.h>
#include "sortser.h"
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
