/* Đảo thứ tự từng nhóm 3 phần tử. Duyệt theo bước 3 và hoán đổi trong nhóm. */
#include <stdio.h>

void reverseInGroupsByThree(int arr[], int size)
{
    for(int i = 0; i < size; i += 3)
    {
        if(i + 2 < size)
        {
            arr[i] ^= arr[i + 2];
            arr[i + 2] ^= arr[i];
            arr[i] ^= arr[i + 2];
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

    reverseInGroupsByThree(numbers, array_size);

    printf("Mảng sau khi đảo ngược từng nhóm 3 phần tử: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
