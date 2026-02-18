// Q18. Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

int main() 
{
    int n, k;
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    k = k % n;              // handle k > n
    int arr[n];

    // place rotated elements in arr
    for (int i = 0; i < n; i++) 
    {
        arr[(i + k) % n] = a[i];
    }

    // copy back to nums
    for (int i = 0; i < n; i++) 
    {
        a[i] = arr[i];
    }

    printf("Rotated Array: ");
    for(int j=0; j<n; j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}
