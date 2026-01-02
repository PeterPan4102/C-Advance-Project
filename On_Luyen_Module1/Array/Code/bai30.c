/* Nhân hai ma trận 3x3. arrC[i][j] = Σ arrA[i][k]*arrB[k][j]. */
#include <stdio.h>

void MultipleMatrix(int arrA[3][3], int arrB[3][3], int arrC[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for (int k = 0; k <3; k++)
            {
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
}

int main()
{
    int matrixA[3][3];
    int matrixB[3][3];
    int matrixC[3][3] = {0}; // Khởi tạo ma trận C với tất cả phần tử bằng 0

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

    MultipleMatrix(matrixA, matrixB, matrixC);

    printf("Ma trận C (A * B) là:\n");
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