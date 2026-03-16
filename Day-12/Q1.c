// Q1.  Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

#include <stdio.h>
#include 

int main() {
    int m, n;
    int mat[100][100];
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    bool isSymmetric = true;
    
    // Check if square
    if (m != n) {
        isSymmetric = false;
    } else {
        // Check symmetry
        for (int i = 0; i < m && isSymmetric; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    isSymmetric = false;
                    break;
                }
            }
        }
    }
    
    printf("%s\n", isSymmetric ? "Symmetric Matrix" : "Not a Symmetric Matrix");
    return 0;
}
