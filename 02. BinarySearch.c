#include<stdio.h>
int bin_search(int a[],int l,int r,int x){
	while(l<=r)	{
		int m=(l+r)/2;
		if(a[m]==x){
			return m;
		}
		if(a[m]<x){
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	return -1;
}
int main(){
	int i,size,x;
	printf("Enter the size of the array : ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the array elements in sorted order : ");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&x);
	int result=bin_search(arr,0,size-1,x);
	if(result==-1){
		printf("Element is not present in the array");	
	}	
	else{
		printf("Element is present at index number : %d",result);
	}
}
