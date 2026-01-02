/* Loại bỏ phần tử trùng lặp. So sánh và tạo mảng mới không trùng vẫn giữ lại 1 phần tử có trùng. */
#include <stdio.h>

void removeDuplicates(int arr[], int size, int result[], int *new_size)
{
    int index_result = 0;
    for(int i = 0; i < size; i++)
    {
        int is_duplicate = 0;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                is_duplicate = 1;
                break;
            }
        }
        if(!is_duplicate)
        {
            result[index_result] = arr[i];
            index_result++;
        }
    }
    *new_size = index_result;
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

    int result[array_size];
    int new_size = 0;
    removeDuplicates(numbers, array_size, result, &new_size);

    printf("Mảng sau khi loại bỏ phần tử trùng lặp: ");
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}