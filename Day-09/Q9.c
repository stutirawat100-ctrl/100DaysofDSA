// Q9. A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char str[1000];
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) 
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    
    printf("%s\n", str);
    return 0;
}
