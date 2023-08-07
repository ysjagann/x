#include <stdio.h>

void findElements(int arr[], int size) {
    int maxRight = arr[size - 1];
    
    printf("Elements that are greater than all elements to their right: ");
    
    for(int i = size - 2; i >= 0; i--){
        if (arr[i] > maxRight) {
            printf("%d ", arr[i]);
            maxRight = arr[i];
        }
    }
    
    printf("\n");
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    findElements(arr, n);
    
    return 0;
}

