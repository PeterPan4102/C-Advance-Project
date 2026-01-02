18. **Đoạn mã sau có vấn đề gì trong đoạn mã sau không?**
    ```c
    void myfunction(char *q) {
        memcpy(q, "hello", 5);
    }

    int main(void) {
        char *p;
        myfunction(p);
        return 0;
    }
    ```
    - Vấn đề 1: Ở hàm `void myfunction()`, với `memcpy(q, "hello", 5)` thì giá trị số byte cần sao chép phải là 6 vì cần **sao chép cả kí tự `\0`**.
    - Vấn đề 2: **con trỏ `p` chưa được khởi tạo**, ở đây nó chỉ mới được khai báo `char *p` và đang trỏ đến 1 địa chỉ rác. Nếu truyền nó vào `myfunction()` thì `memcpy` sẽ ghi vào vùng nhớ không hợp lệ.
    **Cách xử lý:**
    - Đầu tiên ta cần đảm bảo số byte cần sao chép phải đủ độ dài của chuỗi và cộng thêm 1 vì cần sao chép cả kí tự `\0`. Để an toàn thì ta có thể dùng `strlen` để lấy đúng độ dài chuỗi và cộng thêm 1.
        ```c
        memcpy(q, "hello", strlen("hello") + 1)
        ```
    - Tiếp theo ta cần khởi tạo con trỏ `p`, có 2 cách có thể thực hiện. Một là dùng mảng cục bộ để cấp phát đủ bộ nhớ `char p[10]`. Hai là dùng cáp phát động `char *p = malloc(6)`, lưu ý phải `free(p)` trước khi kết thúc hàm `main()`
        ```c
        Cách 1:
        int main(void)
        {
            char p[10];
            ...
        }

        Cách 2:
        int main(void)
        {
            char *p = malloc(6);
            ...
            free(p);
            return 0;
        }