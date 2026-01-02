11. **Chương trình sau in ra gì?**
    ```c
    int i = 10;
    while (i) {
        printf("%d", --i);
    }
    printf("\n");
    ```
    Hàm này sẽ in ra giá trị i giảm dần với `--i` là tiền giảm (pre-decrement), tức là giảm i trước khi dùng giá trị. Vậy với `i = 10`, khi qua tiền giảm `--i` sẽ là 9, sau đó in ra giá trị 9. Quay lại vòng lặp với `i = 9` và cứ tiếp tục như vậy đến khi `--i = 0` và in giá trị cuối là 0. Khi quay lại với `i = 0` thì thoát khỏi vòng lặp và in tiếp một dấu xuống dòng.
    Giá trị in ra sẽ là:
    ```c
    9876543210
    ```