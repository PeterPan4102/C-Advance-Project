24. **Đoạn mã sau có vấn đề gì không?**
    ```c
    void main(void) {
        char array[20];
        for (int i = 0; i < 20; i++) {
            array[i] = i;
        }

        int *p = (int *)array;
        p++;
        p++;
        printf("Value at p: 0x%x\n", *p);
    }
    ```
    - Đầu tiên là đọc vùng nhớ `array` với kiểu khác là `int` khác kiểu đã ghi `char` sẽ gây ra UB (Undefined Behavior) vì theo chuẩn C, một vùng nhớ chỉ được đọc bằng kiểu "tương thích" với kiểu đã dùng để tạo đối tượng đó. Chương trình có thể vẫn chạy được nhưng kết quả sẽ không chính xác, nên dù có đúng alignment hay không thì Output vẫn sẽ sai.
    - Vấn dề tiếp theo ở đây là ép kiểu từ `char` -> `int *` có thể dẫn đến sai **alignment (căn chỉnh bộ nhớ)**. Có nghĩa là **địa chỉ** của dữ liệu trong RAM phải **chi hết cho kích thước truy cập tối ưu** CPU. Ở đây với kiểu `char` ban đầu thì địa chỉ chỉ cần chia hết cho 1 và điều này là luôn đúng. Tuy nhiên với ép kiểu `int *` thì địa chỉ phải chia hết cho 4. Mà rõ ràng thì với địa chỉ đầu tiên ban đầu của `char array[20]` chưa chắc đã chia hết cho 4 nên nếu ép kiểu thì điều này sẽ rất rủi ro