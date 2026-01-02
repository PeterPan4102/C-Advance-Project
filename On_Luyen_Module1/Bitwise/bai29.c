/* Viết 1 dòng code để cô lập bit 1 ở ngoài cùng bên phải của n. */
#include <stdio.h>

int bai29(unsigned int n)
{
    return n &= -n;
}

int main()
{
    unsigned int n;
    printf("Nhap n: ");
    scanf("%u", &n);

    unsigned int result = bai29(n);
    printf("Bit 1 o ngoai cung ben phai cua %u la: %u\n", n, result);
}