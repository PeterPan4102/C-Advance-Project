31. **Đoạn mã sau có vấn đề gì?**
    ```c
    char *getString(void) {
        char str[] = "hello";
        return str;
    }
    int main(void) {
        char *s = getString();
        printf("%s\n", s);
    }
    ```
    hàm `getString` trả về con trỏ trỏ đến mảng `str`, nhưng vì khi kết thúc hàm thì stack frame bị thu hồi mảng`str` bị xóa => con trỏ trỏ đến địa chỉ đã bị giải phóng, đây là lỗi Dangling Pointer => Chương trình không thể cho kết quả mang đợi, gây UB.
    **Cách xử lý** ta chỉ cần khai báo `str` là kiểu biến toàn cục, thì khi hàm kết thúc biến toàn cục vẫn tồn tại => không bị xóa theo stack frame vì biến toàn cục được lưu tại .data/.bss chứ không phải trên stack frame.
    ```c
    char *getString(void) {
        static char str[] = "hello";
        return str;
    }
    int main(void) {
        char *s = getString();
        printf("%s\n", s);
    }
    ```