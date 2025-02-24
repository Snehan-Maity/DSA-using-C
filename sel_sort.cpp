#include<stdio.h>
int main()
{
	int n,i,j,small,temp;
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
		small=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[small])
			{
				small=j;
			}
		}
		temp=arr[small];
		arr[small]=arr[i];
		arr[i]=temp;
	}
	printf("\nSorted Array :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
