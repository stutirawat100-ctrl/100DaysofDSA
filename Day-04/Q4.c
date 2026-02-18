// Q4. Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>

int main() 
{
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter array elements: ");

    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    
    // Reverse using two pointers
    int left = 0, right = n - 1;
    while (left < right) 
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    
    // Print result
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
