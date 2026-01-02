/* Viết 1 dòng code để tìm vị trí LSB (bit có trọng số nhỏ nhất). */
/* Dùng n = (-n) để cô lập 1 ở vị trí LSB sau đó dùng log2(n)*/
#include <stdio.h>
#include <math.h>

int bai27(unsigned int n)
{
    return (int)log2(n & -n);
}

int main()
{
    unsigned int n;
    printf("Nhap n: ");
    scanf("%u", &n);

    int result = bai27(n);
    printf("Vi tri LSB cua %u la: %d\n", n, result);
}