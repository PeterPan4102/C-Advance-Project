/* Viết 1 dòng code để kiểm tra bit thứ n có bật không. */
// #include <stdio.h>

// int main()
// {
//     unsigned int x;
//     int n;
//     printf("Nhap x: ");
//     scanf("%u", &x);
//     printf("Nhap n: ");
//     scanf("%d", &n);

//     if (x & (1 << n))
//     {
//         printf("Bit thu %d cua %u la: Bat\n", n, x);
//     }
//     else
//     {
//         printf("Bit thu %d cua %u la: Tat\n", n, x);
//     }
// }

#include <stdio.h>

int bai20(unsigned int x, int n)
{
    return x & (1u << n);
}

int main()
{
    unsigned int x;
    int n;
    printf("Nhap x: ");
    scanf("%u", &x);
    printf("Nhap n: ");
    scanf("%d", &n);

    int result= bai20(x, n);

    if (result == 0)
    {
        printf("Bit thu %d cua %u la: Tat\n", n, x);
    }
    else
    {
        printf("Bit thu %d cua %u la: Bat\n", n, x);
    }
}