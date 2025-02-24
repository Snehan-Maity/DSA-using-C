#include<stdio.h>
int main()
{
	int n,i,j,key;
	printf("Enter the number of elements ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the array elements ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		printf("%d\t",arr[i]);
	}
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
	printf("\nSorted Array :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
