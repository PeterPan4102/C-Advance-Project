#include<stdio.h>

unsigned char Add(unsigned char a, unsigned char b) {
    return (a + b);
}

int main() {
    unsigned char x;
    unsigned char y;
    printf("Nhap 2 so nguyen duong (0-255): ");
    scanf("%hhu %hhu", &x, &y);

    unsigned char sum = Add(x, y);
    printf("Tong: %hhu\n", sum);

    return 0;
}