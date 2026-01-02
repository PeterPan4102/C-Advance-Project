29. **Đoạn mã sau có vấn đề gì?**
    ```c
    void recursion(int x) {
        int a[100];
        recursion(x + 1);
    }
    ```
    Đây chính là kiểu hàm đệ quy vô hạn vì trong `recursion()` luôn gọi chính nó mà không có điều kiện dừng và luôn tạo mảng kích thước `100*sizeof(int)` byte mỗi lần gọi => Gây lỗi Stack Overflow.
    