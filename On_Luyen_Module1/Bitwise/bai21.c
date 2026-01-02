/* Viết 1 dòng code để hoán đổi 2 số a và b không dùng biến tạm. */
#include <stdio.h>

int bai21(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return 0;
}

int main()
{
    int a;
    int b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    int result = bai21(&a, &b);
    printf("Sau khi hoan doi, a = %d, b = %d\n", a, b);
    return 0;
}