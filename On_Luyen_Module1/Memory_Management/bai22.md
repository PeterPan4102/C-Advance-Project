22. **Đoạn mã sau có vấn đề gì không? Làm sao để in ra "hello"?**
    ```c
    void myfunction(char *q) {
        q = (char *)malloc(8);
        if (q) {
            memcpy(q, "hello", 6);
        }
    }

    void main(void) {
        char *p = NULL;
        myfunction(p);
    }
    ```
    **Đoạn mã này có 2 vấn đề:**
    - Vấn đề thứ nhất là **truyền con trỏ theo giá trị sẽ không thay đổi được p**. Tại hàm `main()` dù con trỏ đã được khai báo nhưng vẫn nó là giá trị NULL, việc truyền `p` vào tham trị `char *q` thì `q = NULL`, lưu ý là `p` và `q` lúc này là 2 con trỏ **hoàn toàn độc lập**. Khi cấp phát động 8 byte trên heap thì gán 1 địa chỉ của vùng cấp phát ấy vào `q`, tuy nhiên thì vì `p` và `q` là 2 con trỏ độc lập nên địa chỉ cấp phát sẽ không được gán cho `p` => khi kết thúc hàm `myfuntio()` thì `p = NULL` và `q` sẽ bị pop khỏi hàm lúc này 8 byte đã cấp phát không thể truy cập lại nữa => Gây Leak Memory.
    - Vấn đề tiếp theo là **không giải phóng vùng nhớ đã cấp phát** khi kết thúc chương trình `main()` không `free` để giải phóng 8 byte đã chiếm trong RAM => Lâu dài sẽ gây ra rò rỉ bộ nhớ (Leak Memory).
    **In ra "hello":**
    - Đầu tiên ta cần sửa lại ở hàm `main()`, sau khi khai báo con trỏ ký tự `p`, ta cần truyền vào **địa chỉ của con trỏ `p`**, tức là `myfunction(&p)` chứ không phải truyền vào giá trị của `p = NULL`. Điều này là để có thể thay đổi được giá trị của p sau khi hàm `myfunction()` kết thúc.
    - Vì tham số truyền vào là `&p` nên tham số trong hàm cần phải là kiểu con trỏ đến con trỏ `char **`, tức là `void myfunction(char **q)`, vì `p` vốn đã là **con trỏ đến char**, tức `char *`, nên `&p` là kiểu `char **`. Lúc này `q` sẽ sao chép giá trị của `&p`, tiếp theo ta cần trỏ tới `p` với `*q` và cấp phát động 8 byte tên heap `*q = (char *)malloc(8)`, giá trị trả về sẽ là địa chỉ của vùng cấp phát. Vậy cả `p` và `*q` đề đang trỏ về cùng địa chỉ là địa chỉ của vùng cấp phát trên heap. => Chuỗi "hello" được gán sẽ không biến mất khi kết thúc hàm vì khi này chỉ có q được pop ra, còn `p` vẫn đang tiếp tục trỏ tới địa chỉ vùng heap.
    - Ta chỉ thêm câu lệnh `printf("%s \n", p)` sau khi gọi hàm `myfunction(&p)` trong `main()`.
    - Cuối cùng trước khi kết thúc hàm `main()` ta cần giải phóng vùng heap với `free(p)`. => Không gây ra Leak Memory không mong muốn.
