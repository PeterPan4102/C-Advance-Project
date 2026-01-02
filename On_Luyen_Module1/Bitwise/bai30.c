/* Viết 1 dòng code để kiểm tra n có phải bội của 8 không. */
#include <stdio.h>

/* Cách 1 là dùng if (n % 8) */

int bai30(int n)
{
    return (n % 8);
}

/* Cách 2 là dùng if(n & 0x7==0). Lưu ý là cách này chỉ phù hợp với lũy thừa của 2*/
// int bai30(int n)
// {
//     return n & 7;
// }

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int result = bai30(n);

    if (result == 0)
    {
        printf("%d la boi cua 8\n", n);
    }
    else
    {
        printf("%d khong phai la boi cua 8\n", n);
    }
}
