#include <stdio.h>
int main() {
    int i, n, x, found = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements :\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Number is found at position %d (index %d)\n", i + 1, i);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Number is not present in the array.\n");
    }

    return 0;
}

