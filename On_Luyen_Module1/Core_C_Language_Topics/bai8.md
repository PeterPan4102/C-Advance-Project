8. **Viết lại hàm strcpy**
    ```c
    void strcpy(char *des, const char *src) {
    while (*src) {
        *des++ = *src++;
    }
    *des = '\0';
    }
    ```
    Thay cú pháp `while()` thành `for()` với điều kiện là đếm `i` đến khi nào vượt qua độ dài của chuỗi `src`, cú pháp: `strlen(src)`. Để tránh việc `*src++` vượt quá độ dài chuỗi.

    Thay vì dùng `void` thì đổi thành `char*` để nhận được con trỏ giá trị trả về => Tăng khả năng tái sử dụng kết quả linh hoạt hơn (in, nối, xử lý tiếp,...)
    Viết lại:

    ```c
    char* strcpy(char *des, const char *src) {
        for (i = 0, i < strlen(src), i++)
        {
            *des++ = *src++;
        }
        *des = '\0';
        return des
    }
    ```