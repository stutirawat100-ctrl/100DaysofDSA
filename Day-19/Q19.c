// Q19. Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) 
    {
        printf("Need at least two elements.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Simple bubble sort (inside main)
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int left = 0, right = n - 1;
    int minSum = __INT_MAX__;
    int pair1 = arr[left], pair2 = arr[right];

    while (left < right) 
    {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) 
        {
            minSum = sum;
            pair1 = arr[left];
            pair2 = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("The two elements whose sum is closest to zero are %d and %d\n", pair1, pair2);
    return 0;
}
