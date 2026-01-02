21. **Đoạn mã sau có vấn đề gì không? Với RAM = 2000 byte?**
    ```c
    void myfunction() {
        char *q;
        for (int i = 0; i < 1000; i++) {
            q = (char *)malloc(8);
            if (q != NULL) {
                memcpy(q, "hello", 6);
            }
        }
    }
    ```
    - Với vòng lặp for tăng `i++` mỗi vòng lặp tức là vòng lặp này sẽ lặp lại 1000 lần. Ở thân vòng lặp sẽ cấp phát động 8 byte ở vùng heap cho q, với `q = (char *)malloc(8)` và không có free để giải phóng 8 byte này mỗi lần kết thúc vòng lặp => Các khối 8 byte cũ vẫn chiếm đóng RAM nhưng không có con trỏ nào trỏ đến dẫn đến **rò rỉ bộ nhớ (Memory Leak)**
    - Mặt khác với RAM = 2000 byte sẽ không thể đủ để thực hiện hết 1000 vòng lặp. Ta có mỗi vòng cấp phát 8 byte, tức là tổng sẽ là 8000 byte chiếm RAM sau khi kết thúc vòng lặp => Vậy đến vòng lặp thứ 250 thì sẽ có 2000 byte chiếm trong RAM và không thể giải phóng, lúc này Heap cạn kiện. Khi đó nếu tiếp tục `malloc(8)` thì sẽ trả về `NULL` và **dẫn đến Out of Memory**