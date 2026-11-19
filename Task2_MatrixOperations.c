#include <stdio.h>

void addMatrix(int r, int c, int A[10][10], int B[10][10]);
void multiplyMatrix(int r1, int c1, int r2, int c2, int A[10][10], int B[10][10]);
void transposeMatrix(int r, int c, int A[10][10]);

int main()
{
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;
    int i, j, choice;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter elements of Matrix A:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d%d", &r2, &c2);

    printf("Enter elements of Matrix B:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\n===== MATRIX OPERATIONS =====\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            if(r1 == r2 && c1 == c2)
                addMatrix(r1, c1, A, B);
            else
                printf("Addition not possible!\n");
            break;

        case 2:
            multiplyMatrix(r1, c1, r2, c2, A, B);
            break;

        case 3:
            transposeMatrix(r1, c1, A);
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}

void addMatrix(int r, int c, int A[10][10], int B[10][10])
{
    int i, j;

    printf("\nAddition Result:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int r1, int c1, int r2, int c2, int A[10][10], int B[10][10])
{
    int result[10][10] = {0};
    int i, j, k;

    if(c1 != r2)
    {
        printf("Matrix multiplication not possible!\n");
        return;
    }

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            for(k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMultiplication Result:\n");

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int r, int c, int A[10][10])
{
    int i, j;

    printf("\nTranspose Matrix:\n");

    for(i = 0; i < c; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
}