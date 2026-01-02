10. **Hàm sau làm gì? Có vấn đề gì không?**
    ```c
    int divide(int a, int b)
    {
        return b / a;
    }
    ```
    Đây là hàm tính thương số từ 2 giá trị nguyên a và b, và hàm trả về 1 giá trị nguyên.
    Hàm này thiếu đi phần kiểm tra điều kiện mẫu số khác 0. Nếu như `a = 0` và thiếu đi bước kiểm tra thì hàm sẽ thực hiện `return b / 0` và đây chính là phép chi cho 0 => chương trình sẽ bị **crash** với **lỗi runtime**.
    Có thể sửa lại hàm này bằng cách thêm điều kiện kiểm tra mẫu số a vào thân hàm:
    ```c
    int divide(int a, int b)
    {
        if (a == 0)
        {
            return 0
        }

        return b / a;
    }
    ```
    