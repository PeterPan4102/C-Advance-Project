/*Cộng hai ma trận 3x3. arrC[i][j] = arrA[i][j] + arrB[i][j].*/
#include <stdio.h>

void SumMatrix(int arrA[3][3], int arrB[3][3], int arrC[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
}

int main()
{
    int matrixA[3][3];
    int matrixB[3][3];
    int matrixC[3][3];

    printf("Nhập ma trận A:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhập phần tử ma trận A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Nhập ma trận B:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhập phần tử ma trận B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    SumMatrix(matrixA, matrixB, matrixC);

    printf("Ma trận C (A + B) là:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}