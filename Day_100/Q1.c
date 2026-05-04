#include <stdio.h>
#include <stdlib.h>

// Fenwick Tree functions
void update(int *BIT, int n, int i) {
    while (i <= n) {
        BIT[i] += 1;
        i += (i & -i);
    }
}

int query(int *BIT, int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

// Coordinate compression
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* countSmaller(int *nums, int n) {
    int *res = (int*)calloc(n, sizeof(int));
    int *sorted = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sorted[i] = nums[i];

    // Sort for compression
    qsort(sorted, n, sizeof(int), cmp);

    // Map values to ranks
    int *rank = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int *pos = (int*)bsearch(&nums[i], sorted, n, sizeof(int), cmp);
        rank[i] = (pos - sorted) + 1; // 1-indexed
    }

    // Fenwick Tree
    int *BIT = (int*)calloc(n+1, sizeof(int));

    // Traverse from right to left
    for (int i = n-1; i >= 0; i--) {
        res[i] = query(BIT, rank[i]-1);
        update(BIT, n, rank[i]);
    }

    free(sorted);
    free(rank);
    free(BIT);
    return res;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums)/sizeof(nums[0]);

    int *res = countSmaller(nums, n);

    printf("Counts of smaller elements to the right:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}
