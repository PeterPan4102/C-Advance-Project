26. **Đoạn mã sau có vấn đề gì không?**
    ```c
    void func(void) {
        char *p = malloc(10);
        strcpy(p, "Embedded");
    }
    ```
    - Hàm này thiếu `free(p)` => Có thể gây Leak Memory.