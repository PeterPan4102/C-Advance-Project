30. **Đoạn mã sau có in ra đúng giá trị ban đầu không? Tại sao?**
    ```c
    int main(void) {
        int a = 0x12345678;
        char *p = (char *)&a;
        p[0] = 0xAA;
        printf("a = 0x%x\n", a);
    }
    ```
    Không đúng giá trị ban đầu.
    Vì `p[0] = 0xAA` đã ghi 1 byte(`0xAA`) lên byte thấp nhất của a (a có 4 byte).
    Kết quả có thể là `0x123456AA`