/* Tính trung bình cộng các phần tử. Tổng chia cho số phần tử. */
#include <stdio.h>

int calculateAverage(int arr[], int size)
{
    int sum = 0;
    int average = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    average = sum / size;

    return average;
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

    int average = calculateAverage(numbers, array_size);
    printf("Giá trị trung bình cộng trong mảng là: %d\n", average);

    return 0;
}