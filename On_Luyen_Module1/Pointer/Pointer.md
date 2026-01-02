1. **Con trỏ (pointer) trong C là gì?**
    - Là một biến lưu địa chỉ một biến khác.
2. **Khai báo con trỏ như thế nào?**
    - Khai báo `kiểu + *`
      Ví dụ:
      ```c
      int *p;
      ```
3. **Toán tử & và * có ý nghĩa gì?**
    - Toán tử & là lấy **địa chỉ**.
    - Toán tử * là truy cập **giá trị** tại địa chỉ.
4. **Khi nào cần dùng con trỏ?**
    - Khi cần **truy cập** trực tiếp bộ nhớ hoặc **truyền tham chiếu** vào hàm.
5. **Sự khác nhau giữa con trỏ và mảng?**
    - Tên mảng là hằng địa chỉ còn con trỏ là biến có thể thay đổi địa chỉ.
6. **Con trỏ null là gì?**
    - Con trỏ không trỏ tới địa chỉ hợp lệ nào (NULL).
7. **Làm sao kiểm tra con trỏ hợp lệ trước khi dùng?**
    - Kiểm tra if(ptr != NULL) trước khi dereference.
8. **Khi gán con trỏ cho con trỏ khác, điều gì xảy ra?**
    - Cả hai cùng trỏ tới cùng vùng nhớ. (Con trỏ bậc hai và con trỏ đểu cùng trỏ đến giá trị tại một địa chỉ).
9. **Con trỏ có thể trỏ tới hàm không?**
    - Có, để gọi hàm gián tiếp.
    - **Hàm trong C có địa chỉ** (nằm trong vùng `.text` – mã lệnh).
    - **Con trỏ hàm** là biến **lưu địa chỉ của một hàm**.
        Cú pháp:
        ```c
        return_type (*pointer_name)(parameter_types);
        ```

        Ví dụ:
        ```c
        int (*fp)(int, int);
        ```
10. **Cấp phát động bằng malloc() trả về gì?**
    - Trả về con trỏ `void *` trỏ đến vùng nhớ cấp phát.
    - Vì malloc() không biết mình sẽ dùng vùng nhớ đó cho kiểu dữ liệu nào nên nó sẽ trả về một con trỏ trung lập `(void *)`.
11. **Khác nhau giữa hằng con trỏ và con trỏ hằng?**
    - Con trỏ hằng: Không đổi địa chỉ.
        Ví dụ:
        ```c
        const int *p;
        ```
    - Hằng con trỏ: Không đổi giá trị trỏ tới.
        ```c
        int const *p;
        ```
12. **Con trỏ void là gì và dùng khi nào?**
    - Là **con trỏ tổng quát, chỉ lưu dữ liệu, không có kiểu cụ thể**, dùng trong các **hàm tổng quát (generic)**, cần tính linh hoạt hoặc trừu tượng hóa kiểu nhưng phải ép kiểu trước khi sử dụng.
    Ví dụ:
        ```c
        int cmp(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
        }
        ```
13. ***Pointer arithmetic là gì?**
    - Là **các phép toán số học được thực hiện trên con trỏ**, cho phép **dịch chuyển con trỏ theo đơn vị phần tử, không phải theo byte**.
    - Nó cho phép con trỏ **duyệt mảng, vùng nhớ liên tiếp** một cách chính xác và hiệu quả.
    **Ví dụ trực quan:**
    int a[5];
    int *p = a;   // &a[0]
    Giả sử:
        ```c
        int a[5];
        int *p = a;   // &a[0]
        ```
      - sizeof(int) = 4
      - a bắt đầu tại địa chỉ 1000

        | Biểu thức | Địa chỉ | Trỏ tới |
        | --------- | ------- | ------- |
        | `p`       | 1000    | `a[0]`  |
        | `p + 1`   | 1004    | `a[1]`  |
        | `p + 2`   | 1008    | `a[2]`  |
14. **Sự khác nhau giữa *p++ và (*p)++?**
    - *p++ là tăng địa chỉ p, còn (*p)++ là tăng giá trị mà p trỏ tới.
15. **Con trỏ đến con trỏ (double pointer) dùng để làm gì?**
    - Con trỏ đến con trỏ (T **) là **con trỏ lưu địa chỉ của một con trỏ khác**.
    - Nói cách khác: **nó cho phép truy cập gián tiếp hai mức vào dữ liệu**.
16. **Khi nào cần free() vùng nhớ động?**
    - Khi vùng nhớ malloc không còn dùng nữa để tránh rò rỉ bộ nhớ.
17. **Làm sao truyền con trỏ hàm vào hàm khác?**
    - Khai báo dạng tham số:
        ```c
        void func(void (*callback)(int));
        ```
18. **Giải thích con trỏ hàm và cách sử dụng với mảng hàm.**
    - **Con trỏ hàm (function pointer)** là **con trỏ lưu địa chỉ của một hàm**.
        - Trong C, **hàm có địa chỉ trong bộ nhớ (.text)**.
        - Ta có thể lưu địa chỉ đó vào một biến → gọi gián tiếp hàm.
    - Dùng để chọn hàm động tại runtime.
    Ví dụ runtime selection bằng con trỏ hàm:
        ```c
        int add(int a, int b) { return a + b; }
        int sub(int a, int b) { return a - b; }
        int mul(int a, int b) { return a * b; }

        int (*ops[])(int, int) = { add, sub, mul };
        ```
19. **Con trỏ tới mảng khác với mảng con trỏ thế nào?**
    - **Con trỏ tới mảng** là **con trỏ trỏ tới TOÀN BỘ một mảng**, không phải từng phần tử.
    Cú pháp: `int (*p)[];`
    Ví dụ:
        ```c
        int a[5] = {1, 2, 3, 4, 5};
        int (*p)[5] = &a;
        ```
        Quan hệ bộ nhớ: `p ──► a[0] a[1] a[2] a[3] a[4]`
    - **Mảng con trỏ** là **một mảng**, trong đó **mỗi phần tử là một con trỏ**.
    Cú pháp: `int *p[5];`
    Ví dụ:
        ```c
        int x = 10, y = 20, z = 30;
        int *p[3] = { &x, &y, &z };
        ```
        Quan hệ bộ nhớ:
        `p[0] ──► x`
        `p[1] ──► y`
        `p[2] ──► z`
20. **Làm sao dùng con trỏ để xử lý mảng đa chiều?**
    - Dùng con trỏ tới mảng (int (*p)[col]) và phép toán địa chỉ.
    - `p[i][j] == *(*(p + i) + j)`








