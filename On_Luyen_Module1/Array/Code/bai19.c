/* Sắp xếp mảng tăng dần. Dùng bubble sort hoặc selection sort. */
/* - Bubble sort  là thuật toán sắp xếp đơn giản nhất hoạt động bằng cách hoán đổi nhiều lần các phần tử liền kề nếu chúng sai thứ tự
   - Selection sort còn được gọi là thuật toán sắp xếp chọn. Thuật toán này sẽ giúp so sánh các phần tử trong mảng với nhau để tìm các
phần tử có giá trị nhỏ nhất hoặc lớn nhất (tùy theo thứ tự sắp xếp). Sau đó đẩy các giá trị ấy về phía đầu của mảng để tạo thành một dãy
số sắp xếp theo thứ tự hoàn chỉnh.*/
#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    int min_index = 0;
    for (int i = 0; i < size; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;

                arr[i] ^= arr[min_index];
                arr[min_index] ^= arr[i];
                arr[i] ^= arr[min_index];
            }
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

    // bubbleSort(numbers, array_size);
    selectionSort(numbers, array_size);

    printf("Mảng sau khi sắp xếp tăng dần: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}