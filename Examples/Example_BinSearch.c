#include<stdio.h>
int*find(int*A,int size,int id);
int main ()
{
	int A[]={10,20,30,40,50,60,70,80},length,*add,id=80;
	length=sizeof(A)/sizeof(int);
	add=find(A,length,id);
	printf("\nAddress=%d",add);
	return 0;
}
int*find(int*A,int n,int id)
{
	int mid;
	mid=(n)/2;	
		if(id<A[0]||id>A[n-1])
		return NULL;
		if(A[mid]==id)
		return A+mid;
		else if(A[mid]>id)
		find(A,mid,id);
		else if(A[mid]<id)
		find(&A[mid+1],n-(mid+1),id);			
		else if(mid>n||mid<1)
		return NULL;	
}
