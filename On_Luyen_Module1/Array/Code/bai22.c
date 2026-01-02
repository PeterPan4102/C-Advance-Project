/* Tìm phần tử xuất hiện nhiều nhất. Đếm tần suất từng giá trị. */
#include <stdio.h>

void findMostFrequent(int arr[], int size, int *most_frequent_value, int *frequent_count)
{
    int max_count = 0;
    int max_frequency = 0;
    int value = arr[0];
    for (int i = 0; i < size; i++)
    {
        max_count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                max_count++;
            }
        }
        if (max_count > max_frequency)
        {
            max_frequency = max_count;
            value = arr[i];
        }
    }
    
    if (max_frequency == 1)
    {
        value = -1; // Không có phần tử nào lặp lại
        *frequent_count = 0;
        *most_frequent_value = value;
    } else {
        *most_frequent_value = value;
        *frequent_count = max_frequency;
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

    int most_frequent_value, frequent_count;
    findMostFrequent(numbers, array_size, &most_frequent_value, &frequent_count);

    if(most_frequent_value == -1) {
        printf("Không có phần tử nào xuất hiện nhiều hơn 1 lần.\n");
        return 0;
    } else {
        printf("Phần tử xuất hiện nhiều nhất là: %d\n", most_frequent_value);
        printf("Số lần xuất hiện của phần tử đó là: %d\n", frequent_count);
    }
    return 0;
}
