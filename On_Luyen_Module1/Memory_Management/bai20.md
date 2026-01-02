20. **a và b được cấp phát và lưu trữ ở đâu?**
    ```c
    void main(void) {
        char a[4] = "foo";
        char *b = "bar";
    }
    ```
    Cả 2 biến a và b đều được cấp phát trên stack.
    - Với biến a là mảng ký tự cục bộ, nó được cấp phát tự động trong stack. Khi hàm main chạy thì compiler sẽ copy các ký tự `'f'`, `'o'`, `'o'`, `'\0'` vào vùng nhớ của a trên Stack => mảng a được cấp phát và lưu trữ chuỗi đã được compiler copy nội dung vào vùng trên Stack
    - Với biến b, đây là con trỏ ký tự, bản thân nó sẽ được cấp phát trên Stack khi hàm main chạy. Tuy nhiên chuỗi hằng `"bar"` sẽ không được lưu trữ cùng với b trên stack vì b là con trỏ, và con trỏ thì chỉ lưu địa chỉ. Vậy nên chuỗi `"bar"` sẽ được compiler lưu trong vùng .rodata, và biến b sẽ trỏ đến vùng nhớ của chuỗi hằng này. => con trỏ b được cấp phát trên stack, trỏ đến chuỗi lưu trữ ở vùng .rodata