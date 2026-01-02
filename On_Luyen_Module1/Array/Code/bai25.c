/* Tính tổng phần tử ở vị trí chẵn. Cộng arr[i] với i % 2 == 0. */
#include <stdio.h>

int sumEvenIndexElements(int arr[], int size)
{
    int sum = 0;

    for(int i = 0; i < size; i +=2)
    {
        sum += arr[i];
    }

    return sum;
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

    int sum = sumEvenIndexElements(numbers, array_size);
    printf("Tổng các phần tử ở vị trí chẵn là: %d\n", sum);

    return 0;
}