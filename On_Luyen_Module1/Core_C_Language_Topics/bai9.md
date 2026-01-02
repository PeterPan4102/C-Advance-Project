9. **Chương trình sau sẽ in ra gì?**
    ```c
    unsigned char c;
    for (c = 0; c < 999; c++) {
        printf("%d ", c);
    }
    ```
    Để trả lời câu hỏi này, trước tiên ta cần phân tích vòng lặp `for`. Đầu tiên gán `c = 0` sau đó đặt điều kiện là `c < 999` => Nếu đúng thì chạy thân vòng lặp `for`, sau đó `c++` tăng giá trị của c thêm 1.
    Tuy nhiên c ban đầu được lưu là kiểu `unsigned char` với *kích thước của kiểu này là 1 byte* thì c chỉ có thể **tăng từ 0 lên tối đa là 255**. Vậy nên khi đạt đến giá trị ngưỡng 255 thì khi `c++` sẽ trở về 0. Cư như vậy vòng lặp for sẽ in **vô hạn** từ 0 đến 255 rồi lại về 0 rồi tăng lên lại 255.
    ```c
    0 1 2 ... 254 255 0 1 2 ... 254 255 0 ....