ÔN LUYỆN MODULE 1 – C ADVANCED
===============================

I. NHÓM THAO TÁC BITS
----------------------
1. **Bật (set) một bit cụ thể:**  
   Dùng toán tử OR `|` với mặt nạ bit:  
   ```c
   REGISTER |= (1 << BIT_POSITION);
   ```

2. **Đảo (toggle) một bit:**  
   Dùng toán tử XOR `^`:  
   ```c
   REGISTER ^= (1 << BIT_POSITION);
   ```

3. **Kiểm tra một bit đã bật hay chưa:**  
   ```c
   if (REGISTER & (1 << BIT_POSITION)) {...}
   ```

4. **Hoán đổi hai số không dùng biến tạm:**  
   ```c
   a ^= b;
   b ^= a;
   a ^= b;
   ```

5. **Kiểm tra số có phải lũy thừa của 2:**  
   ```c
   if (n & (n - 1)) == 0
   ```

6. **Đếm số bit 1 trong số nhị phân:**  
   Dùng vòng lặp:
   ```c
   while (n) { count += n & 1; n >>= 1; }
   ```
   Hoặc thuật toán Brian Kernighan:
   ```c
   while (n) { n &= (n - 1); count++; }
   ```

7. **Kiểm tra số chẵn/lẻ:**  
   `if (n & 1)` → lẻ; ngược lại là chẵn.

8. **Tìm bù 2 của số:**  
   `(~n) + 1`

9. **Kiểm tra hai số bằng nhau (không dùng ==):**  
   `(a ^ b) == 0`

10. **Tìm bit 1 có trọng số lớn nhất (MSB):**  
   Dùng `floor(log2(n))` hoặc vòng lặp dịch bit.

11. **Tìm bit 1 có trọng số nhỏ nhất (LSB):**  
   `n & (-n)`

12. **Tắt bit 1 ngoài cùng bên phải:**  
   `n &= (n - 1)`

13. **Cô lập bit 1 ngoài cùng bên phải:**  
   `n & (-n)`

14. **Kiểm tra số có phải bội của 8:**  
   `if (n % 8 == 0)` hoặc `(n & 0x7) == 0`


II. CORE C LANGUAGE TOPICS
---------------------------
15. **typedef:** Tạo bí danh cho kiểu dữ liệu → giúp code ngắn gọn, dễ đọc.

16. **So sánh số thực:** Không nên dùng `==`. Thay vào đó kiểm tra:
   ```c
   if (fabs(a - b) < EPSILON)
   ```

17. **Macro:** Là tính năng tiền xử lý (#define).  
   Dùng để:
   - Định nghĩa hằng số: `#define SIZE 256`
   - Tạo hàm inline: `#define ABS(x) ((x)<0?-(x):(x))`
   - Chống trùng lặp mã, điều kiện biên dịch, debug, logging.

18. **Mảng con trỏ hàm:** Mảng chứa các con trỏ đến hàm cùng kiểu.
   ```c
   int (*ops[4])(int,int) = {add, sub, mul, divi};
   ```

19. **const vs #define:**  
   - `const`: có kiểu dữ liệu, được cấp phát bộ nhớ.  
   - `#define`: thay thế văn bản, không kiểm tra kiểu.

20. **inline function:** Hàm nhỏ, được compiler chèn trực tiếp vào nơi gọi để giảm chi phí gọi hàm.

21. **& và &&:**  
   - `&`: Bitwise AND / lấy địa chỉ biến.  
   - `&&`: Logical AND trong điều kiện.

22. **Phân đoạn bộ nhớ:**  
   - Stack: biến local  
   - Heap: cấp phát động  
   - .data: biến global/static khởi tạo ≠ 0  
   - .bss: biến global/static khởi tạo = 0 hoặc không khởi tạo  
   - .text (.rodata): mã lệnh, const.

23. **Tại sao chia vùng nhớ:** Quản lý dữ liệu hiệu quả, tách biệt vùng tĩnh, động, code.

24. **Biến global không khởi tạo:** nằm ở `.bss`.

25. **Tại sao biến 0 và 10 ở hai vùng khác nhau:**  
   - 0 → `.bss`  
   - 10 → `.data`

26. **Đệ quy nhiều lần ảnh hưởng vùng nào:** Stack.

27. **Biến const đặt ở .rodata:** Vì chỉ đọc, tiết kiệm RAM.

28. **Dữ liệu tồn tại suốt chương trình:** đặt ở `.data` hoặc `.bss`.

29. **.bss không chiếm dung lượng file:** Vì chỉ lưu kích thước, không lưu dữ liệu.

30. **Vì sao static giữ giá trị sau khi hàm kết thúc:**  
   Vì nằm trong `.data`/`.bss`, không nằm trên Stack.


III. LỖI BỘ NHỚ & CƠ CHẾ BẢO VỆ
--------------------------------
31. **Memory Leak:** Cấp phát mà không giải phóng. Dùng Valgrind kiểm tra.

32. **Stack Overflow:** Gọi hàm lồng nhau/quá nhiều biến local → tràn stack. Debug bằng gdb.

33. **Stack Smashing:** Tràn bộ đệm ghi đè địa chỉ trả về. Compiler phát hiện bằng **Stack Canary**.

34. **Heap Corruption:** Ghi sai vùng heap. Dùng **AddressSanitizer** để phát hiện.

35. **Dangling Pointer:** Trỏ tới vùng nhớ đã free. Khắc phục: `free(p); p = NULL;`

36. **ASan vs Valgrind:**  
   - ASan: nhanh, tích hợp CI, yêu cầu biên dịch lại.  
   - Valgrind: không cần biên dịch lại, bắt lỗi sâu hơn nhưng chậm.

37. **Wild Pointer:** Con trỏ chưa khởi tạo.


IV. STORAGE CLASS
------------------
38. **Các lớp lưu trữ:** auto, static, extern, register.

39. **auto:** Mặc định cho biến local; lifetime tự động (tạo khi vào hàm, hủy khi ra).

40. **static:**  
   - Với local: giữ giá trị giữa các lần gọi.  
   - Với global/hàm: giới hạn phạm vi trong file.

41. **extern:** Khai báo biến/hàm định nghĩa ở file khác, chia sẻ giữa nhiều file.

42. **register:** Gợi ý compiler lưu trong thanh ghi; không lấy được địa chỉ; nay ít dùng.

43. **volatile:** Ngăn compiler tối ưu hóa biến có thể thay đổi bất ngờ (ISR, thread, hardware).


V. DATA TYPES
--------------
44. **struct vs array:**  
   - struct: chứa nhiều biến khác kiểu.  
   - array: các phần tử cùng kiểu.

45. **Kích thước struct:** Tổng kích thước các thành viên + padding.

46. **Căn chỉnh bộ nhớ (alignment):** Compiler thêm padding để dữ liệu thẳng hàng.

47. **Padding:** Byte trống để căn chỉnh. Dùng `#pragma pack(1)` hoặc `__attribute__((packed))` để bỏ.

48. **Gán giữa 2 struct cùng kiểu:** Hợp lệ, copy byte-by-byte.

49. **So sánh 2 struct:** Không dùng `==`, phải so từng trường hoặc `memcmp()`.

50. **Truyền struct vào hàm:** Nên truyền con trỏ để tiết kiệm bộ nhớ.

51. **#pragma pack(1):** Bỏ padding, dữ liệu liên tục từng byte.

52. **Padding khác MCU:** Có, cần `packed` để đảm bảo layout giống nhau.

53. **union:** Nhiều thành viên dùng chung vùng nhớ.

54. **Kích thước union:** Bằng kích thước thành viên lớn nhất.

55. **Dùng union khi:** Cần tiết kiệm RAM hoặc dữ liệu có thể có nhiều dạng.

56. **Ghi 1 thành viên, đọc thành viên khác:** Undefined behavior.

57. **Khởi tạo nhiều thành viên cùng lúc:** Không thể.

58. **Union chứa struct:** Được; struct cũng có thể chứa union.

59. **Union trong embedded:** Map thanh ghi hoặc giao tiếp dữ liệu.

60. **enum:** Kiểu liệt kê, gán tên cho hằng số nguyên.

61. **Giá trị đầu tiên của enum:** Mặc định là 0.

62. **Gán giá trị cụ thể cho phần tử:** Có thể.

63. **Phần tử tiếp theo:** Tăng +1 tự động.

64. **enum vs #define:** enum rõ ràng, dễ debug, có kiểm tra kiểu.

65. **Enum có thể âm không:** Có, vì lưu dưới dạng signed int.
