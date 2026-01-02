# Ôn luyện Module 1

## Nhóm thao tác Bits

1. **Làm thế nào để bật (set) một bit cụ thể trong một biến?**  
   Dùng toán tử OR (`|`) với một mặt nạ bit (bitmask)  
   Kỹ thuật:  
   ```c
   REGISTER |= (1 << BIT_POSITION);
   ```
   - `1 << BIT_POSITION` tạo ra một số nhị phân có duy nhất bit ở vị trí `BIT_POSITION` là 1.  
     Phép OR sẽ bật bit tương ứng trong thanh ghi lên mà không làm thay đổi các bit khác.

2. **Làm thế nào để đảo (toggle) một bit cụ thể trong một biến?**  
   Dùng toán tử XOR (`^`) với một mặt nạ bit (bitmask)  
   Kỹ thuật:  
   ```c
   REGISTER ^= (1 << BIT_POSITION);
   ```
   - Phép XOR với 1 sẽ đảo trạng thái của bit (0 thành 1, 1 thành 0). Rất hữu ích để nhấp nháy đèn LED.

3. **Làm thế nào để kiểm tra một bit cụ thể đã được bật hay chưa?**  
   Dùng toán tử AND (`&`)  
   Kỹ thuật:
   ```c
   if (REGISTER & (1 << BIT_POSITION)) { ... }
   ```
   - Phép AND sẽ cho ra một kết quả khác 0 nếu bit cần kiểm tra là 1, và bằng 0 nếu bit đó là 0.

4. **Làm thế nào để hoán đổi hai số mà không cần biến thứ ba?**  
   Dùng phép gán XOR:
   ```c
   a ^= b;
   b ^= a;
   a ^= b;
   ```
   Hoán đổi bằng XOR dựa trên tính chất đối xứng của phép XOR (`X ^ Y ^ X = Y`).

5. **Làm thế nào để kiểm tra một số có phải là lũy thừa của 2 hay không?**  
   Số `n` là lũy thừa của 2 nếu:
   ```c
   (n & (n - 1)) == 0
   ```
   - Một số là lũy thừa của 2 nếu trong dạng nhị phân, nó chỉ có duy nhất 1 bit bằng 1.  
   - Khi trừ đi 1, bit 1 đó và các bit sau nó đảo ngược, khiến `n & (n-1)` xóa sạch tất cả bit 1 → kết quả = 0.

6. **Làm thế nào để đếm số bit 1 trong biểu diễn nhị phân của một số?**  
   Dùng vòng lặp hoặc dùng hàm builtin `__builtin_popcount(n)` (tùy compiler).  
   Cách dùng vòng lặp có 2 cách:

   - Duyệt từng bit một:
     ```c
     int count_bit(unsigned int n) {
       int count = 0;
       while (n) {
         if (n & 1) count++;
         n >>= 1;
       }
       return count;
     }
     ```

   - Thuật toán Brian Kernighan:
     ```c
     int count_bit(unsigned int n) {
       int count = 0;
       while (n) {
         n &= (n - 1);
         count++;
       }
       return count;
     }
     ```

7. **Làm thế nào để kiểm tra một số là chẵn hay lẻ?**  
   Kiểm tra bit 0:
   ```c
   if (n & 1) { /* lẻ */ } else { /* chẵn */ }
   ```

8. **Làm thế nào để tìm bù 2 (2’s complement) của một số nhị phân?**  
   Đảo bit và cộng 1:
   ```c
   (~n) + 1
   ```

9. **Làm thế nào để kiểm tra hai số có bằng nhau hay không mà không dùng toán tử so sánh?**  
   Dùng XOR:
   ```c
   if ((a ^ b) == 0) { /* bằng nhau */ }
   ```

10. **Làm thế nào để tìm bit có trọng số lớn nhất (Most Significant Bit - MSB)?**  
    “Bit có trọng số lớn nhất” là bit 1 nằm xa bên trái nhất.  
    - Dùng `log2(n)`:
      ```c
      int MSB_pos = (int)floor(log2(n));
      ```
    - Hoặc dùng dịch bit:
      ```c
      int msp(unsigned int n) {
        if (n == 0) return -1;
        int pos = -1;
        while (n) {
          pos++;
          n >>= 1;
        }
        return pos;
      }
      ```

11. **Làm thế nào để tìm bit có trọng số nhỏ nhất (Least Significant Bit - LSB)?**  
    Dùng công thức:
    ```c
    n & (-n)
    ```
    (Với `-n` là bù 2, tức `-n = ~n + 1`.)

12. **Làm thế nào để tắt bit 1 ở ngoài cùng bên phải?**  
    Dùng công thức:
    ```c
    n &= (n - 1);
    // hoặc
    n -= (n & (-n));
    ```

13. **Làm thế nào để cô lập bit 1 ở ngoài cùng bên phải?**  
    Cô lập LSB:
    ```c
    n & (-n)
    ```

14. **Làm thế nào để kiểm tra một số có phải là bội số của 8 hay không?**  
    ```c
    (n % 8 == 0)
    ```
    *Lưu ý:* Kiểm tra bitwise chia hết chỉ dùng được cho dạng `2^k`:
    ```c
    (n & 0x7) == 0  // tương đương n % 8 == 0
    ```

---

## Core C Language Topics

15. **Ý nghĩa của `typedef` trong các trường hợp sử dụng là gì?**  
    Tạo bí danh cho một kiểu dữ liệu ⇒ Định nghĩa một “tên kiểu” mới.

16. **Có vấn đề gì khi so sánh hai giá trị số thực (`if (a == b)`)?**  
    Do sai số làm tròn nên so sánh trực tiếp rủi ro. Thay vì kiểm tra bằng nhau tuyệt đối, kiểm tra “gần bằng” với `EPSILON`:
    ```c
    if (fabs(a - b) < EPSILON) { ... }
    ```

17. **Macro là gì? Các ứng dụng điển hình là gì?**  
    Macro là tính năng tiền xử lý cho phép định nghĩa tên/biểu thức được thay thế trước khi biên dịch.  

    Cú pháp:  
    ```c
    #define TEN_GOI gia_tri_thay_the
    #define TEN_GOI(tham_so) bieu_thuc
    ```

    Ứng dụng | Mô tả | Ví dụ
    ---|---|---
    Định nghĩa hằng số | Dễ bảo trì, đổi 1 nơi | `#define BUFFER_SIZE 256`
    Tạo “hàm” inline | Tránh chi phí gọi hàm | `#define ABS(x) ((x)<0?-(x):(x))`
    Chống trùng lặp mã | Tổng quát cho nhiều kiểu | 
    Điều khiển biên dịch có điều kiện | Cho nền tảng khác nhau | 
    Debug/Logging linh hoạt | Bật/tắt log nhanh | 
    Tối ưu code nhúng | Truy cập thanh ghi HW | 

    Ví dụ swap dạng macro:
    ```c
    #define SWAP(a,b) do { int t = (a); (a) = (b); (b) = t; } while(0)
    ```

18. **Mảng con trỏ hàm là gì? Viết ví dụ.**  
    - Mảng: tập hợp phần tử cùng kiểu.  
    - Con trỏ hàm: biến lưu địa chỉ của hàm.  
    - Mảng con trỏ hàm: mảng chứa các con trỏ tới các hàm cùng prototype.
    ```c
    int add(int a,int b){return a+b;}
    int sub(int a,int b){return a-b;}
    int mul(int a,int b){return a*b;}
    int divi(int a,int b){return a/b;}

    int (*ops[4])(int,int) = { add, sub, mul, divi };

    for (int i = 0; i < 4; ++i) {
      printf("%d ", ops[i](2, 3));
    }
    ```

19. **Sự khác biệt giữa `const` và `#define` là gì?**  
    - `const`: là biến thật, có kiểu dữ liệu, được cấp phát bộ nhớ.  
    - `#define`: thay thế văn bản, không kiểm tra kiểu.

20. **Hàm `inline` là gì?**  
    Hàm bình thường có thêm từ khóa `inline` để gợi ý compiler “cắm” mã vào chỗ gọi (phù hợp với hàm nhỏ).
    ```c
    inline int square(int x) { return x * x; }
    ```

21. **Toán tử `&` và `&&`?**

    Toán tử | Tên | Dùng cho | Ý nghĩa
    ---|---|---|---
    `&` | Bitwise AND / Address-of | Bit, số, biến | AND từng bit hoặc lấy địa chỉ
    `&&` | Logical AND | Biểu thức điều kiện | AND logic (true/false)

22. **Có những phân đoạn vùng nhớ nào?**  
    - **Stack (RAM):** Biến local  
    - **Heap (RAM):** Dữ liệu cấp phát động (`malloc`, `calloc`, `realloc`)  
    - **Initialized data (.data) (RAM):** Biến `static` + `global` khởi tạo khác 0  
    - **Uninitialized data (.bss) (RAM):** Biến `static` + `global` không khởi tạo hoặc khởi tạo 0  
    - **Text / .rodata (ROM):** Code instructions, biến `const` toàn cục (chỉ-đọc)

23. **Tại sao bộ nhớ trong C được chia thành .text, .data, .bss, heap và stack?**  
    Để quản lý dữ liệu hiệu quả, tách biệt dữ liệu tĩnh, động, mã lệnh, và biến tạm thời.

24. **Biến toàn cục không khởi tạo nằm ở đâu?**  
    `.bss`

25. **Hai biến global có cùng giá trị khởi tạo 0 và 10 — tại sao không nằm cùng một vùng nhớ?**  
    - `0` lưu ở `.bss`  
    - `10` lưu ở `.data`  
    Vì `.bss` không cần ghi dữ liệu vào file nhị phân (tối ưu kích thước, thời gian load).

26. **Khi chương trình gọi một hàm lồng nhau nhiều lần (đệ quy), vùng nhớ nào bị ảnh hưởng nhiều nhất?**  
    **Stack** (tạo nhiều stack frame) → có thể dẫn đến tràn stack.

27. **Tại sao biến `const` thường ở `.rodata` thay vì `.data`?**  
    `.rodata` là dữ liệu chỉ đọc, giúp bảo vệ và tiết kiệm RAM.

28. **Nếu muốn dữ liệu tồn tại suốt vòng đời chương trình, đặt ở vùng nhớ nào?**  
    `.data` hoặc `.bss`

29. **Tại sao `.bss` không chiếm nhiều dung lượng trong file `.bin`, nhưng chiếm RAM khi chạy?**  
    `.bss` chỉ lưu kích thước; khi chạy, HĐH cấp phát RAM tương ứng và điền 0.

30. **Điều gì xảy ra với Stack khi hàm kết thúc, nhưng biến `static` trong hàm vẫn được giữ giá trị?**  
    Stack frame bị thu hồi, nhưng biến `static` nằm ở `.data/.bss` nên vẫn giữ giá trị đến khi chương trình kết thúc.

31. **Lỗi Memory Leak xảy ra khi nào? Tại sao? Cách debug.**  
    - Xảy ra khi cấp phát động nhưng không giải phóng sau khi dùng xong → chiếm RAM dần, thiếu bộ nhớ, crash.  
    - Debug bằng **Valgrind (Linux)**:
      ```bash
      gcc -g -O0 main.c -o app
      valgrind --leak-check=full --show-leak-kinds=all \
               --track-origins=yes --num-callers=25 ./app
      ```

32. **Lỗi Stack Overflow xảy ra khi nào? Tại sao? Cách debug.**  
    - Ghi dữ liệu vượt quá kích thước vùng nhớ đã cấp phát (stack/heap), đệ quy vô hạn, mảng local quá lớn…  
    - Debug bằng **gdb (backtrace)**:
      ```bash
      gcc -g -O0 main.c -o main
      gdb ./main
      (gdb) run
      (gdb) bt
      ```

**Lỗi Segmentation Fault** xảy ra khi truy cập vùng nhớ không hợp lệ (NULL/dangling, OOB, stack overflow, ghi vào vùng chỉ-đọc, call sai function pointer, format string sai…). HĐH bảo vệ vùng nhớ; vi phạm → `SIGSEGV`.  
Debug tương tự với `gdb bt`.

33. **Lỗi Stack Smashing là gì? Cách compiler phát hiện bằng cơ chế Canary.**  
   Thông báo “Stack Smashing detected” cho thấy tràn bộ đệm trên stack đã bị phát hiện/ngăn chặn.  
   Cơ chế:
   1) **Prologue:** đặt giá trị canary ngẫu nhiên lên stack.  
   2) **Thực thi**  
   3) **Tấn công:** dữ liệu tràn làm thay đổi canary  
   4) **Epilogue:** so sánh canary hiện tại với giá trị gốc  
   - Khớp → an toàn;  
   - Không khớp → gọi `__stack_chk_fail`, in lỗi và kết thúc chương trình.

34. **Lỗi Heap Corruption là gì? Cách phát hiện bằng AddressSanitizer.**  
   “Heap corruption” xảy ra khi đọc/ghi sai vùng heap hoặc hỏng metadata của allocator.  
   Phát hiện bằng **ASan**:
   ```bash
   gcc -g -O1 -fsanitize=address -fno-omit-frame-pointer app.c -o app
   ./app
   ```
   Chú ý: tiêu đề lỗi, callstack, và nơi cấp phát/giải phóng.

35. **Lỗi Dangling Pointer là gì? Tại sao nguy hiểm? Cách khắc phục.**  
   Con trỏ trỏ tới vùng nhớ đã được giải phóng/không còn hợp lệ → hành vi không xác định, khó debug, rủi ro bảo mật (UAF).  
   Khắc phục: **đặt con trỏ về `NULL` ngay sau `free`**.
   ```c
   free(p);
   p = NULL;
   ```

36. **Khi nào nên dùng AddressSanitizer thay vì Valgrind để debug lỗi bộ nhớ?**  

   Tiêu chí | AddressSanitizer (ASan) | Valgrind (Memcheck)
   ---|---|---
   Cách hoạt động | Gắn kiểm tra khi biên dịch (`-fsanitize=address`) | Phân tích khi chạy nhị phân
   Tốc độ | Nhanh hơn (chậm ~2–3×) | Rất chậm (10–50×)
   Bắt lỗi | OOB, UAF, Double Free | OOB, UAF, Leak, Uninitialized
   Leak | Có (với `detect_leaks=1`) | Có (`--leak-check=full`)
   Tích hợp CI | Rất tốt | Khó vì chậm
   Cần rebuild | Có | Không
   Nền tảng | Linux/macOS/Windows (Clang/MSVC) | Chủ yếu Linux
   Khuyến nghị | Phát triển, test nhanh, CI/CD | Kiểm tra sâu, không rebuild được

   - **Dùng ASan** khi có mã nguồn, cần debug nhanh/chính xác/tích hợp CI.  
   - **Dùng Valgrind** khi không biên dịch lại được, hoặc cần kiểm tra uninitialized memory kỹ hơn.

37. **Lỗi Wild Pointer là gì?**  
   Con trỏ **chưa được khởi tạo** mà đã sử dụng → chứa địa chỉ rác, trỏ tới vùng nhớ không hợp lệ.

---

## Storage Class

38. **Các lớp lưu trữ (Storage classes) là gì?**  
   Từ khóa xác định nơi lưu trữ, phạm vi (scope), vòng đời (lifetime) và liên kết (linkage) của biến.  
   → Gồm: `auto`, `static`, `extern`, `register`.

39. **Từ khóa `auto` dùng để làm gì? Khi nào thì dùng?**  
   - Mặc định cho biến cục bộ trong hàm.  
   - Vòng đời tự động (tạo khi vào hàm, hủy khi ra khỏi hàm), lưu trên **stack**.  
   - Thường **không cần ghi rõ**.

40. **Từ khóa `static` dùng để làm gì? Khi nào thì dùng?**  
   - Với biến cục bộ: đổi vòng đời thành **tĩnh**, tồn tại suốt chương trình (lưu `.data/.bss`).  
   - Với biến/hàm toàn cục: **giới hạn phạm vi trong file** (ẩn với file khác).  
   - Dùng khi cần **giữ giá trị giữa các lần gọi** hoặc muốn **đóng gói nội bộ**.

41. **Từ khóa `extern` dùng để làm gì? Khi nào thì dùng?**  
   - **Khai báo** (không định nghĩa) biến/hàm **được định nghĩa** ở file khác.  
   - Chia sẻ biến/hàm toàn cục giữa nhiều file.  
   - Lỗi thường gặp: khai báo mà **không có định nghĩa** → “undefined reference”.

42. **Từ khóa `register` dùng để làm gì? Khi nào thì dùng?**  
   - Gợi ý compiler lưu biến trong **thanh ghi CPU** để truy cập nhanh.  
   - **Không thể lấy địa chỉ** (`&`) của biến `register`.  
   - Chỉ áp dụng cho biến cục bộ/tham số hàm.  
   - Ngày nay **hiếm dùng** vì compiler đã tối ưu tốt.

43. **Từ khóa `volatile` dùng để làm gì? Khi nào thì dùng?**  
   - Báo cho compiler rằng **giá trị biến có thể thay đổi bất ngờ** (phần cứng/ISR/thread khác).  
   - **Ngăn tối ưu hóa** truy cập biến.  
   - Dùng cho: **thanh ghi phần cứng**, biến dùng trong **ISR**, hoặc biến **chia sẻ giữa luồng**.  
   - **Không đảm bảo tính nguyên tử** và **không thay thế** cơ chế đồng bộ.

---

## Data Types

44. **Khác nhau giữa `struct` và `array`?**  
   - `array`: các phần tử **cùng kiểu**.  
   - `struct`: nhóm các biến **khác kiểu** trong một đơn vị.

45. **Kích thước `struct` được tính như thế nào?**  
   Tổng kích thước các thành viên **+ padding** (byte căn chỉnh).

46. **Căn chỉnh bộ nhớ trong `struct` hoạt động như thế nào?**  
   Compiler chèn **padding** để mỗi thành viên nằm ở địa chỉ phù hợp (2, 4 byte…), giúp truy cập nhanh/đúng.

47. **Padding là gì trong `struct`? Làm sao tránh padding?**  
   - Padding: các byte trống dùng để căn chỉnh.  
   - Tránh/giảm: `#pragma pack(1)` hoặc `__attribute__((packed))` (chỉ dùng khi thật sự cần).

48. **Có thể gán trực tiếp giữa 2 `struct` cùng kiểu không?**  
   Có. Trình biên dịch copy byte-by-byte.

49. **`struct` có thể so sánh bằng toán tử `==` không?**  
   Không. Cần so sánh từng trường hoặc dùng `memcmp()`.

50. **`struct` có thể dùng làm tham số hàm không?**  
   Có, nhưng **nên truyền bằng con trỏ** để tiết kiệm bộ nhớ/sao chép.

51. **`#pragma pack(1)` có ý nghĩa gì?**  
   Yêu cầu compiler bỏ padding, căn dữ liệu liên tục từng byte – dùng khi giao tiếp/định dạng dữ liệu cố định.

52. **Khi truyền `struct` vào hàm, có thể bị padding sai khi giao tiếp giữa vi điều khiển khác nhau không?**  
   Có. Cần `__attribute__((packed))` hoặc `#pragma pack` để đồng nhất layout.

53. **`union` là gì?**  
   Kiểu cho phép **nhiều thành viên chia sẻ cùng vùng nhớ**.

54. **Kích thước của `union` là bao nhiêu?**  
   Bằng kích thước của **thành viên lớn nhất**.

55. **`union` dùng khi nào?**  
   Khi cần **tiết kiệm bộ nhớ** hoặc biểu diễn dữ liệu ở **nhiều dạng** nhưng **chỉ dùng một** tại một thời điểm.

56. **Nếu ghi vào một thành viên `union` rồi đọc thành viên khác thì sao?**  
   **Undefined behavior** (hành vi không xác định) theo chuẩn C (trừ một số ngoại lệ).

57. **Có thể khởi tạo nhiều thành viên của `union` cùng lúc không?**  
   Không.

58. **`union` có thể chứa `struct` không?**  
   Có, và ngược lại (`struct` cũng có thể chứa `union`).

59. **`union` thường dùng trong embedded để làm gì?**  
   **Map bit/byte của thanh ghi** hoặc **ánh xạ dữ liệu giao tiếp** (protocol mapping).

60. **`enum` là gì?**  
   Kiểu dữ liệu liệt kê, gán **tên** cho các hằng số **nguyên**.

61. **Mặc định giá trị đầu tiên của `enum` là gì?**  
   `0`

62. **`enum` có thể gán giá trị cụ thể cho phần tử không?**  
   Có.

63. **Giá trị của phần tử tiếp theo nếu không chỉ định?**  
   **Tự động tăng 1** từ giá trị trước đó.

64. **Tại sao nên dùng `enum` thay vì `#define`?**  
   Dễ debug, có phạm vi rõ ràng, được compiler kiểm tra kiểu.

65. **`enum` có thể âm không?**  
   Có, vì `enum` lưu dưới dạng `int` (signed).

---

> Hết.
