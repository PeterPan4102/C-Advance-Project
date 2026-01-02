27. **Đoạn mã sau có hợp lệ không?**
    ```c
    void test(void) {
        char *str = "Hello";
        str[0] = 'h';
    }
    ```
    Không hợp lệ vì `str` là một con trỏ ký tự, nó chỉ trỏ đến địa chỉ đầu tiên của chuỗi hằng `"Hello"` trong vùng khác không phải stack, có thể là `.rodata` => Và nó luôn không thể ghi chỉ có thể đọc chuỗi này. Vậy nên lệnh `str[0] = 'h'` sẽ không thể ghi và gây UB.
    **Sửa lại như sau:**
    ```c
    void test(void) {
        char str[] = "Hello"; // thay vì để str là con trỏ thì ta để nó là mảng => "Hello" sẽ được sao chép vào stack
        str[0] = 'h'; // lúc này chuỗi có thể được đọc và ghi
    }
    ```