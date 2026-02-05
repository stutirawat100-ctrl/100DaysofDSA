//  Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

#include <stdio.h>

int main() 
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d array elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int p;
    printf("Enter the position at which the element is to be deleted: ");
    scanf("%d", &p);

    // Shift elements left from position p
    for (int i = p-1; i < n - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }

    // Print new array of size n-1
    printf("New Array:\n");
    for (int i = 0; i < n - 1; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

  
