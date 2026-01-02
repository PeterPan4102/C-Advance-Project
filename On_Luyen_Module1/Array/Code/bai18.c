/* Gộp hai mảng A và B thành C. Copy từng phần tử của A rồi B vào C. */
#include <stdio.h>

void mergeArrays(int arrA[], int sizeA, int arrB[], int sizeB, int arrC[],int sizeC)
{
    int *ptrA;
    ptrA = arrA;
    int *ptrB = arrB;
    int *ptrC = arrC;

    for(int i = 0; i < sizeC; i++)
    {
        if(i < sizeA)
        {
            ptrC[i] = ptrA[i];
        }

        else
        {
            ptrC[i] = ptrB[i - sizeA];
        }
    }
}

int main()
{
    int array_sizeA;
    int array_sizeB;
    printf("Nhập kích thước mảng A: ");
    scanf("%d", &array_sizeA);
    printf("Nhập kích thước mảng B: ");
    scanf("%d", &array_sizeB);

    int numbersA[array_sizeA];
    for (int i = 0; i < array_sizeA; i++)
    {
        printf("Nhập số nguyên thứ %d của mảng A: ", i + 1);
        scanf("%d", &numbersA[i]);
    }
    int numbersB[array_sizeB];
    for (int i = 0; i < array_sizeB; i++)
    {
        printf("Nhập số nguyên thứ %d của mảng B: ", i + 1);
        scanf("%d", &numbersB[i]);
    }
    int sizeC = array_sizeA + array_sizeB;
    int numbersC[sizeC];

    mergeArrays(numbersA, array_sizeA, numbersB, array_sizeB, numbersC, sizeC);
    printf("Mảng C sau khi gộp: ");
    for (int i = 0; i < sizeC; i++)
    {
        printf("    Phần tử thứ %d: %d ", i + 1, numbersC[i]);
    }
}