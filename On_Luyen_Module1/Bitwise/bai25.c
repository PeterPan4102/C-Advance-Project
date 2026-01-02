/* Viết 1 dòng code để kiểm tra hai số a, b có bằng nhau không mà không dùng ==. */
#include <stdio.h>

int bai20(int a, int b)
{
    return (a^b);
}

int main()
{
    int a;
    int b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    int result= bai20(a, b);
    if (result == 0)
    {
        printf("%d va %d bang nhau\n", a, b);
    }
    else
    {
        printf("%d va %d khong bang nhau\n", a, b);
    }
}