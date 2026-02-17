// Q17. Write a program to find the maximum and minimum values present in a given array of integers.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of an array");
    scanf("%d",&n);

    int arr[n]; 
    printf("Enter %d Array Elements: ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int min=arr[0];
    int max=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]<min)
            min=arr[i];

        if(arr[i]>max)
            max=arr[i];
    }
    printf("Max: %d\n",max);
    printf("Min: %d",min);

    return 0;
}
