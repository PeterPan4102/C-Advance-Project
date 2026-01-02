28. **Các biến a, b, c, d được lưu ở đâu trong bộ nhớ?**
    ```c
    int a = 10; // .data
    const int b = 5; // .rodata
    static int c = 3; // .data
    int func(void) {
        int d = 2; // stack frame
        return a + b + c + d; // nằm trong thanh ghi
    }
    ```
