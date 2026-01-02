12. **Chương trình sau sẽ in ra gì?**
    ```c
    unsigned int x;
    for (x = 10; x >= 0; x--) {
        printf("%u ", x);
    }
    ```
    Vòng lặp for này khởi đầu với giá trị `x = 10`, câu lệnh điều kiện `x >= 0`, và in ra x nếu kết quả `True`, sau đó với hậu giảm `x--` giá trị của x sẽ giảm 1 sau mỗi lần lặp. Cứ lặp lại như vậy đến khi `x = 0`, vì x được khai báo ban đầu là kiểu `unsigned int` vậy nên khi hậu giảm thì giá trị `x = 0` sẽ tràn xuống giá trị cực đại, tức `UNIT_MAX` (hay gọi là tràn số **underflow**) => vòng lặp sẽ chạy vô hạn.
    Với `unsigned int x` thì có giá trị từ `0` đến `2^32 - 1 = 4294967295`
    Kết quả in ra sẽ là:
    ```c
    10 9 8 ... 0 4294967295 4294967294 ....
    ```