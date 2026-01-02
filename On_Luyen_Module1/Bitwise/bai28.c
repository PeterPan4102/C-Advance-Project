/* Viết 1 dòng code để tắt bit 1 ở ngoài cùng bên phải của n. */
/* Dùng n & (n-1) hoặc n-=(n&(-n)) để tắt bit 1 ngoài cùng bên phải */
#include <stdio.h>

int bai28(unsigned int n)
{
    return n & (n-1);
}

int main()
{
    unsigned int n;
    printf("Nhap n: ");
    scanf("%u", &n);

    unsigned int result = bai28(n);
    printf("Sau khi tat bit 1 o ngoai cung ben phai cua %u ta duoc: %u\n", n, result);
}
