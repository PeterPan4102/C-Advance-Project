/* Tìm phần tử lớn nhất và vị trí của nó. Ghi lại chỉ số khi tìm max. */
#include <stdio.h>

void checkMAX(int arr[], int size, int *max_value, int *max_index)
{
    *max_value = arr[0];
    *max_index = 0;
    if (size <= 0)
    {
        return -1; // Trả về -1 nếu mảng rỗng
    }

    int arr_max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr_max)
        {
            arr_max = arr[i];
            *max_index = i;
        }
    }
    *max_value = arr_max;
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

    int max_value, max_index;
    checkMAX(numbers, array_size, &max_value, &max_index);

    printf("Giá trị lớn nhất trong mảng là: %d\n", max_value);
    printf("Vị trí của giá trị lớn nhất là: %d\n", max_index);

    return 0;
}