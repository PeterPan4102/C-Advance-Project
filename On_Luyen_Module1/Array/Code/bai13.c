/* Đếm số chẵn và lẻ trong mảng. Kiểm tra từng phần tử bằng toán tử %.*/
#include <stdio.h>
void countEvenOdd(int arr[], int size, int *even_count, int *odd_count)
{
    *even_count = 0;
    *odd_count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] & 1)
        {
            (*odd_count)++;
        }
        else
        {
            (*even_count)++;
        }
    }
}

int main()
{
    int array_size;
    printf("Nhập kích thước mảng: ");
    scanf("%d", &array_size);

    int numbers[array_size];
    for (int i = 0; i < array_size; i++)
    {
        printf("Nhập số nguyên thứ %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int even_count, odd_count;
    countEvenOdd(numbers, array_size, &even_count, &odd_count);

    printf("Số lượng số chẵn: %d\n", even_count);
    printf("Số lượng số lẻ: %d\n", odd_count);

    return 0;
}