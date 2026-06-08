/************************************************************
 * Matrix Operations Program
 * Developed by: Elias Zananiri
 * Date: June 2026
 * Description: Implements Matrix Addition, Multiplication,
 *              and Transpose using functions and 2D arrays.
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const char *matrixName);
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const char *matrixName);
void matrixAddition(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void matrixMultiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2);
void matrixTranspose(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void clearInputBuffer();
void printMenu();

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;
    
    printf("\n==================================================\n");
    printf("     MATRIX OPERATIONS PROGRAM - Elias Zananiri    ");
    printf("\n==================================================\n");
    
    do {
        printMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch(choice) {
            case 1:  // Matrix Addition
                printf("\n>>> MATRIX ADDITION <<<\n");
                printf("Enter number of rows and columns for both matrices: ");
                scanf("%d %d", &rowsA, &colsA);
                rowsB = rowsA;
                colsB = colsA;
                
                printf("\n");
                inputMatrix(A, rowsA, colsA, "Matrix A");
                printf("\n");
                inputMatrix(B, rowsB, colsB, "Matrix B");
                
                matrixAddition(A, B, result, rowsA, colsA);
                
                printf("\n=== RESULT ===\n");
                displayMatrix(A, rowsA, colsA, "Matrix A");
                displayMatrix(B, rowsB, colsB, "Matrix B");
                displayMatrix(result, rowsA, colsA, "Sum (A + B)");
                break;
                
            case 2:  // Matrix Multiplication
                printf("\n>>> MATRIX MULTIPLICATION <<<\n");
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &rowsB, &colsB);
                
                if(colsA != rowsB) {
                    printf("\n[ERROR] Matrix multiplication not possible!\n");
                    printf("Columns of A (%d) must equal rows of B (%d)\n", colsA, rowsB);
                    break;
                }
                
                printf("\n");
                inputMatrix(A, rowsA, colsA, "Matrix A");
                printf("\n");
                inputMatrix(B, rowsB, colsB, "Matrix B");
                
                matrixMultiplication(A, B, result, rowsA, colsA, rowsB, colsB);
                
                printf("\n=== RESULT ===\n");
                displayMatrix(A, rowsA, colsA, "Matrix A");
                displayMatrix(B, rowsB, colsB, "Matrix B");
                displayMatrix(result, rowsA, colsB, "Product (A × B)");
                break;
                
            case 3:  // Matrix Transpose
                printf("\n>>> MATRIX TRANSPOSE <<<\n");
                printf("Enter number of rows and columns for the matrix: ");
                scanf("%d %d", &rowsA, &colsA);
                
                inputMatrix(A, rowsA, colsA, "Matrix");
                matrixTranspose(A, result, rowsA, colsA);
                
                printf("\n=== RESULT ===\n");
                displayMatrix(A, rowsA, colsA, "Original Matrix");
                displayMatrix(result, colsA, rowsA, "Transpose Matrix");
                break;
                
            case 4:  // Exit
                printf("\nThank you for using Matrix Operations Program!\n");
                printf("Developed by Elias Zananiri. Goodbye!\n\n");
                break;
                
            default:
                printf("\n[ERROR] Invalid choice! Please enter 1-4.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const char *matrixName) {
    printf("Enter elements for %s (%d x %d):\n", matrixName, rows, cols);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("  %s[%d][%d] = ", matrixName, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const char *matrixName) {
    printf("\n%s:\n", matrixName);
    for(int i = 0; i < rows; i++) {
        printf("  [ ");
        for(int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("]\n");
    }
}

void matrixAddition(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], 
                    int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrixMultiplication(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE],
                          int result[MAX_SIZE][MAX_SIZE], int r1, int c1, int r2, int c2) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrixTranspose(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE],
                     int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void printMenu() {
    printf("\n==================================================\n");
    printf("                  MAIN MENU                        \n");
    printf("==================================================\n");
    printf("  [1] Matrix Addition                              \n");
    printf("  [2] Matrix Multiplication                        \n");
    printf("  [3] Matrix Transpose                             \n");
    printf("  [4] Exit                                         \n");
    printf("==================================================\n");
}
