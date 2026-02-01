/* Q1 Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. 
   Shift existing elements to the right to make space.                                                          */

   #include <stdio.h>
int main() 
{
    int n;
    printf("Enter no. of elements for an array: ");
    scanf("%d",&n);

    int arr[n+1];   // +1 for new element
    printf("Enter %d array elements: ",n);
    for(int i=0; i<n; i++) 
    {
        scanf("%d",&arr[i]);
    }

    int p, x;
    printf("Enter position (1 to %d): ", n+1);
    scanf("%d",&p);


    printf("Enter integer to insert: ");
    scanf("%d",&x);

    for(int i=n; i>=p; i--) 
    {
        arr[i] = arr[i-1];
    }
    
    arr[p-1] = x;

    printf("New Array:\n");
    for(int i=0; i<=n; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
