7. - **Kết quả in ra là gì?**
   - **Nếu bỏ từ khóa static, kết quả có khác không?**
   - **Biến count được lưu ở vùng nhớ nào?**
    ```c
    void counter(void) {
        static int count = 0;
        count++;
        printf("%d ", count);
    }

    int main(void) {
        for (int i = 0; i < 3; i++)
            counter();
        return 0;
    }
    ```
    - **Kết quả in ra là:**
        ```c
        1 2 3
        ```
    - **Nếu bỏ từ khóa static:** thì biến `count` sẽ trở thành biến cục bộ và sẽ luôn bị xóa khi kết thúc hàm => mỗi vòng lặp for ở `main()` khi gọi hàm `counter()` thì biến cục bộ `count = 0` sẽ luôn được khởi tạo lại, thay vì chỉ khởi tạo 1 lần như là 1 biến toàn cục.
    Kết quả lúc này:
        ```c
        1 1 1
        ```
    - **Biến count được lưu ở vùng nhớ nào?**
        Biến count được lưu ở vùng .data

8. - **Code này có biên dịch được không?**
   - **Nếu không, compiler bão lỗi gì? Tại sao?**
    ```c
    int main(void) {
        register int x = 5;
        printf("%d\n", x);
        printf("%p\n", &x);
        return 0;
    }
    ```
    - **Code này có biên dịch được không?**
        Không thể biên dịch
    - **Nếu không, compiler báo lỗi gì? Tại sao?**
        Nó sẽ báo lỗi **address of register**, vì `int x = 5` được khai báo là `register`, mà `register` thì nằm trên thanh ghi chứ không nằm trên RAM => không thể lấy địa chỉ của x.