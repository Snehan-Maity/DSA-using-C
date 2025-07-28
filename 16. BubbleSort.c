#include<stdio.h>
int main()
{
	int n,i,j,temp;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Original array :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("\nSorted Array :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
