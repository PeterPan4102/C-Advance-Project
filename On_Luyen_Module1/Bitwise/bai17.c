/*Bật bit thứ n của x*/
#include <stdio.h>

unsigned int bai17(unsigned int x, int n)
{
    return x |= (1 << n);
}

int main()
{
    unsigned int x;
    int n;
    printf("Nhap x: ");
    scanf("%u", &x);
    printf("Nhap n: ");
    scanf("%d", &n);

    unsigned int result = bai17(x, n);

    printf("Ket qua: %u\n", result);
    return 0;
}