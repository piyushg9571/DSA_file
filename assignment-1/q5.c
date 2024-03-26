//Q- 5) Write a program to input a matrix and to determine if it is the asymmetrical matrix ( a matrix is said to be symmetric when A-A’).
#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, column;
    // Input the number of rows and columns
    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &column);
    if (rows <= 0 || rows > MAX_SIZE || column <= 0 || column > MAX_SIZE) {
        printf("Invalid input for rows or columns.\n");
        return 1;
    }
    // Input the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is asymmetric
    int Asymmetric = 1;
    for (int i = 0; i < rows && Asymmetric; i++) {
        for (int j = 0; j < column && Asymmetric; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                Asymmetric = 0;  // Not symmetric
            }
        }
    }
    // Output the result
    if (Asymmetric) {
        printf("The matrix is asymmetric.\n");
    } else {
       printf("The matrix is not asymmetric.\n");
    }

    return 0;
}
