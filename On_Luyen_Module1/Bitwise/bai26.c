/* Viết 1 dòng code để tìm vị trí MSB (bit có trọng số lớn nhất). */

/* Cách 1: Dùng log2(n) */
#include <stdio.h>
#include <math.h>

int bai26(unsigned int n)
{
    return (int)log2(n);
}

int main()
{
    unsigned int n;
    printf("Nhap n: ");
    scanf("%u", &n);

    int result = bai26(n);
    printf("Vi tri MSB cua %u la: %d\n", n, result);
}

/* Cách 2: Dùng vòng lặp dịch bit (bitwise)*/
// #include <stdio.h>
//int bai26(unsigned int n)
//{
//    int pos = -1;
//    while (n!=0)
//    {
//        if(n&1)
//        {
//            pos++;
//        }
//        n = n >> 1;
//    }
//    return pos;
//}

//int main()
//{
//    unsigned int n;
//    printf("Nhap n: ");
//    scanf("%u", &n);

//    int result = bai26(n);
//    printf("Vi tri MSB cua %u la: %d\n", n, result);
//}