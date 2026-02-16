// Q16. Given an array of integers, count the frequency of each distinct element and print the result.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of an array");
    scanf("%d",&n);

    int arr[n]; int visited[n];
    printf("Enter %d Array Elements: ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        if (visited[i]) continue;
        int c = 1;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] == arr[i]) 
            {
                c++;
                visited[j] = 1;
            }
        }
        printf("%d : %d\n", arr[i], c);
    }
    return 0;
}
