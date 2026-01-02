/* Tìm giá trị lớn nhất trong mảng. Duyệt mảng và so sánh max.*/
#include <stdio.h>

int checkMAX(int arr[], int size)
{
    if (size <= 0)
    {
        return -1; // Trả về -1 nếu mảng rỗng
    }

    int arr_max = arr[0];
    for (int i = 1; i < size; i++)
    {
        arr_max = (arr[i] > arr_max) ? arr[i] : arr_max;
    }
    return arr_max;
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

    printf("%d", numbers);

    int max = checkMAX(numbers, array_size);
    printf("Giá trị lớn nhất trong mảng là: %d\n", max);
    return 0;
}