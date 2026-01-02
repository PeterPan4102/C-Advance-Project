/* Chèn phần tử vào vị trí bất kỳ. Dịch phần tử sang phải và gán giá trị mới. */
#include <stdio.h>

void insertElement(int arr[], int size, int k, int value)
{
    int i;
    if (k < 0 || k > size) {
        printf("Lỗi chỉ số không hợp lệ"); // Chỉ số không hợp lệ, không thay đổi mảng
    }
    else {
        // Dịch các phần tử từ k trở đi sang phải
        for (i = size; i > k; i--) {
            arr[i] = arr[i - 1];
        }
        arr[k] = value; // Gán giá trị mới vào vị trí k
    }
}

int main()
{
    int array_size;
    printf("Nhập kích thước mảng: ");
    scanf("%d", &array_size);

    int numbers[array_size + 1]; // Tăng kích thước mảng để chèn phần tử mới
    for (int i = 0; i < array_size; i++)
    {
        printf("Nhập số nguyên thứ %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int k, value;
    printf("Nhập vị trí cần chèn (0 đến %d): ", array_size);
    scanf("%d", &k);
    printf("Nhập giá trị cần chèn: ");
    scanf("%d", &value);

    insertElement(numbers, array_size, k, value);
    array_size++; // Tăng kích thước mảng sau khi chèn

    printf("Mảng sau khi chèn phần tử %d tại vị trí %d: ", value, k);
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}