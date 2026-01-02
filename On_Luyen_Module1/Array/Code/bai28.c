/* Kiểm tra ma trận đối xứng. So sánh arr[i][j] và arr[j][i]. */
#include <stdio.h>

int isSymmetric(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                return 0; // Ma trận không đối xứng
            } else {
                return 1; // Ma trận đối xứng
            }
        }
    }
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

    if (isSymmetric(matrix))
    {
        printf("Ma trận đối xứng.\n");
    }
    else
    {
        printf("Ma trận không đối xứng.\n");
    }

    return 0;
}