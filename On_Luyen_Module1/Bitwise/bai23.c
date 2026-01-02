/* Viết 1 dòng code để kiểm tra n là chẵn hay lẻ. */
#include <stdio.h>

int bai23(int n)
{
    return n & 1;
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = bai23(n);

    if (result == 0)
    {
        printf("%d la so chan\n", n);
    }
    else
    {
        printf("%d la so le\n", n);
    }
}