/* Xóa phần tử tại vị trí k. Dịch các phần tử sau k sang trái. */
#include <stdio.h>

void deleteElement(int arr[], int size, int k)
{
    int i;
    if (k < 0 || k >= size) {
        printf("Lỗi chỉ số không hợp lệ"); // Chỉ số không hợp lệ, không thay đổi mảng
    }
    else {
        // Dịch các phần tử sau k sang trái
        for (i = k; i < size; i++) {
            arr[i] = arr[i + 1];
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

    int k;
    printf("Nhập vị trí phần tử cần xóa (0 đến %d): ", array_size - 1);
    scanf("%d", &k);

    deleteElement(numbers, array_size, k);
    array_size--; // Giảm kích thước mảng sau khi xóa

    printf("Mảng sau khi xóa phần tử tại vị trí %d: ", k);
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}