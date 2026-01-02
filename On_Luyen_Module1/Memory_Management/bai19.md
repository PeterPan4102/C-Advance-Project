19. **Hàm hoạt động ra sao? Các biến được cấp phát ở đâu?**
    ```c
    int a;
    char *b;
    const char c[20] = "I am a string";

    void func(char d, int c_param, char *f) {
        int g = 0;
        static int h = 2;
        char *i = NULL;
        i = (char *)malloc(20);
        if (i != NULL) {
            free(i);
        }
    }
    ```
    **Hàm hoạt động**: 
    - Hàm `void func(char d, int c_param, char *f)` với 3 tham số truyền vào là `char d`, `int c_param`, `char *f`. 
    - Khởi tạo biến cục bộ `int g = 0`, khởi tạo 1 lần biến tĩnh cục bộ `static int h = 2`, và cuối cùng là khởi tạo con trỏ cục bộ `char *i = NULL`, sau đó cấp phát động 20 byte trên heap cho `i` với `i = (char *)malloc(20)`, ép kiểu `char *` cho `malloc`. 
    - Tiếp theo qua câu lệnh điều kiện `if (i != NULL) { free(i); }` nếu i đã được cấp phát động thì sẽ giải phóng với `free(i)`.
    **Nơi cấp phát các biến**

        ```c
        int a; /* Cấp phát ở .bss */
        char *b; /* Cấp phát ở .bss */
        const char c[20] = "I am a string"; /* Cấp phát ở .rodata */

        void func(char d, int c_param, char *f) /* Tham số d, c_param, f được cáp phát ở Stack Frame */
        {
            int g = 0; /* Cấp phát ở stack */
            static int h = 2; /* Cấp phát ở .data */
            char *i = NULL; /* Cấp phát ở stack */
            i = (char *)malloc(20); /* Cấp phát 20 byte trên Heap */
            if (i != NULL) {
                free(i);
            }
        }
        ```
        Lưu ý: Code trên không nên ép kiểu `char *` đối với `malloc`. Nên set `i = NULL` ngay sau khi `free`.