/* Nhập 5 số nguyên, in tổng. Dùng vòng for và biến sum. */
#include <stdio.h>

int main()
{
    int numbers[5];
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Nhap so nguyen thu %d: ", i + 1);
        scanf("%d", &numbers[i]);
        
        sum+=numbers[i];
    }

    printf("Tong cua 5 so nguyen la: %d\n", sum);
    return 0;
}
