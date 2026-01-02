/* Nhập ma trận 3x3, tính tổng đường chéo chính. Cộng các phần tử arr[i][i]. */
#include <stdio.h>

int sumMainDiagonal(int arr[3][3])
{
    int sum = 0;

    for(int i = 0; i < 3; i++)
    {
        sum += arr[i][i];
    }

    return sum;
}

int main()
{
    int matrix[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Nhập phần tử ma trận [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = sumMainDiagonal(matrix);
    printf("Tổng các phần tử trên đường chéo chính là: %d\n", sum);

    return 0;
}