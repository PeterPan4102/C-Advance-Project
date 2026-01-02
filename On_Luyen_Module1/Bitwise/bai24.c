/* Viết 1 dòng code để lấy bù 2 (two’s complement) của n. */
#include <stdio.h>

int bai24(unsigned int n)
{
    return ~n + 1;
}

int main()
{
    unsigned int n;
    printf("Nhap n: ");
    scanf("%u", &n);

    unsigned int result = bai24(n);
    printf("Bu 2 cua %u la: %u\n", n, result);
}
