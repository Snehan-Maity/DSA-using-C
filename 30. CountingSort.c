#include<stdio.h>
// Function to find maximum element
int findMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort function
void countingSort(int arr[], int n){
    int max = findMax(arr, n);
    int count[max + 1];

    // Initialize count array
    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }

    // Count frequency of elements
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    // Reconstruct the sorted array
    int k = 0;
    for(int i = 0; i <= max; i++){
        while(count[i] > 0){
            arr[k] = i;
            k++;
            count[i]--;
        }
    }
}

// Function to display array
void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    printf("Original array:\n");
    display(arr,n);

    countingSort(arr,n);

    printf("Sorted array:\n");
    display(arr,n);

    return 0;
}
