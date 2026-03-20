#include<stdio.h>

// Function to get maximum element in array
int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Counting sort according to digit represented by exp
void countSort(int arr[], int n, int exp){
    int output[n];      // output array
    int count[10] = {0};

    // Count occurrences of digits
    for(int i = 0; i < n; i++){
        count[(arr[i]/exp) % 10]++;
    }

    // Convert count[i] so it contains actual position
    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    // Build output array
    for(int i = n-1; i >= 0; i--){
        int digit = (arr[i]/exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output array to arr[]
    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n){
    int max = getMax(arr, n);

    // Do counting sort for every digit
    for(int exp = 1; max/exp > 0; exp *= 10){
        countSort(arr, n, exp);
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
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    display(arr, n);

    radixSort(arr, n);

    printf("Sorted Array: ");
    display(arr, n);

    return 0;
}
