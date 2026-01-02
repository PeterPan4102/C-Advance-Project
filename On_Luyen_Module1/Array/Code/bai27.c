/* Tính tổng đường chéo phụ ma trận 3x3. Cộng arr[i][n-1-i]. */
#include <stdio.h>

int sumSecondaryDiagonal(int arr[3][3])
{
    int sum = 0;

    for(int i = 0; i < 3; i++)
    {
        sum += arr[i][2 - i];
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

    int sum = sumSecondaryDiagonal(matrix);
    printf("Tổng các phần tử trên đường chéo phụ là: %d\n", sum);

    return 0;
}