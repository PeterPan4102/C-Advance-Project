/* Đảo ngược mảng. Hoán đổi arr[i] và arr[n-1-i]. */
#include <stdio.h>
void reverseArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] ^= arr[size - 1 - i];
        arr[size - 1 - i] ^= arr[i];
        arr[i] ^= arr[size - 1 - i];
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

    reverseArray(numbers, array_size);

    printf("Mảng sau khi đảo ngược: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}