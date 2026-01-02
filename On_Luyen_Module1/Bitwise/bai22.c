/* Viết 1 dòng code để kiểm tra n có phải lũy thừa của 2 không. */
#include <stdio.h>

int bai22(int n)
{
    return n&(n-1);
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = bai22(n);

    if (result == 0)
    {
        printf("%d la luy thua cua 2\n", n);
    }
    else
    {
        printf("%d khong phai la luy thua cua 2\n", n);
    }
}