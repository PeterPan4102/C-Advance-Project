13. **Có vấn đề gì với hàm sau?**
    ```c
    unsigned char Add(unsigned char a, unsigned char b) {
        return (a + b);
    }
    ```
    - Vấn đề đầu tiên là tràn số (Overflow), ta có thể dễ nhận ra là hàm Add được khai báo với giá trị trả về là giá trị kiểu `unsigned char` có giá trị từ 0 đến 255. trong khi đó tham số truyền vào cũng có giá trị kiểu `unsigned char`. Rõ ràng với khoảng giá trị của hàm Add thì có thể tràn giá trị cộng từ a và b nếu tổng > 255, **tràn về 0** theo modulo 256.
    - Vấn đề thứ hai là quy tắc nâng kiểu số nguyên (Integer Promotion), trong biểu thức (a + b), cả a và b đều là kiểu `unsigned char` sẽ được **tự động ép kiểu lên** `int` trước khi cộng theo chuẩn C. Vậy nên phép cộng sẽ thực sự được diễn ra theo kiểu `int` chứ không phải `unsigned char`. Sau đó kết quả ấy sẽ **ép ngược** lại về `unsigned char` khi trả về hàm. Nếu kết quả vượt quá 255 thì sẽ dẫn đến việc **mất đi dữ liệu**, cụ thể là tràn số.