23. **Các biến sau được lưu ở đâu?**
    ```c
    int a = 5; // lưu ở .data
    int d;  // lưu ở .bss
    char b[6] = "hello"; // lưu ở .data
    const int c = 4; // lưu ở .rodata

    void myfunction(void)
    {
        static int g = 5; // lưu ở .data
        const int h = 6; // Hằng lưu trên stack
        char i; // lưu ở stack
    }
    ```

