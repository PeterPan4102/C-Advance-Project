/* Kiểm tra giá trị x có trong mảng không. Duyệt tuần tự so sánh từng phần tử. */
#include <stdio.h>

int containsValue(int arr[], int size, int x)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == x)
        {
            return 1; // Tìm thấy x trong mảng
        }
    }
    return 0; // Không tìm thấy x trong mảng
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

    int x;
    printf("Nhập giá trị cần kiểm tra: ");
    scanf("%d", &x);

    if (containsValue(numbers, array_size, x))
    {
        printf("Giá trị %d có trong mảng.\n", x);
    }
    else
    {
        printf("Giá trị %d không có trong mảng.\n", x);
    }
    return 0;
}