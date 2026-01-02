1. **Mảng trong C là gì?**
   - Là tập hợp các phần tử cùng kiểu dữ liệu, lưu liên tiếp trong bộ nhớ và được truy cập bằng chỉ số (index).
2. **Cách khai báo và khởi tạo mảng một chiều?**
   - Cú pháp khai báo mảng 1 chiều: **<kiểu_dữ_liệu>** tên_mảng[kích_thước];
3. **Kích thước của mảng được xác định khi nào?**
   - **Mảng cục bộ** trong hàm:
       - Khi hàm chạy: vùng nhớ cho mảng được cấp phát trên stack.
       - Khi hàm kết thúc: vùng nhớ này bị thu hồi, mảng không còn tồn tại.
   - **Mảng global/static**:
       - Được cấp phát một lần duy nhất, tồn tại từ lúc chương trình bắt đầu cho đến khi kết thúc.
4. **Tên mảng biểu diễn điều gì?**
   - Tên mảng chính là con trỏ trỏ đến phần tử đầu tiên của mảng.
     - **a** (tên mảng) thường “tự động biến thành” con trỏ trỏ tới phần tử đầu tiên.

      - **a ≈ &a[0]** (địa chỉ phần tử đầu tiên).

      - ***(a + i)** chính là **a[i]**.
5. **Phân biệt arr[i] và * (arr + i)?**
    - Đây là 2 cách truy cập tương đương nhau trong C.
6. **Làm sao tính số phần tử trong mảng tĩnh?**
    - Ta có thể dùng công thức sau:
      - **sizeof(arr)/sizeof(arr[0])**
7. **Sự khác nhau giữa mảng tĩnh và mảng động?**
    - Mảng tĩnh có kích thước cố định, mảng động được cấp phát bằng malloc().
      - Mảng tĩnh:
      ```c
      int a[5];        // global - tồn tại suốt chương trình
        ```
        - Mảng động:
        ```c
        int *a = (int*)malloc(5 * sizeof(int)); // nằm trên heap
        ```
8. **Truyền mảng vào hàm khác thế nào so với truyền biến?**
    - Khi truyền mảng thì thực chất là truyền địa chỉ, chỉ truyền địa chỉ của phần tử đầu tiên vào hàm.
    - Khi truyền biến thì thường là truyền giá trị.
9. **Mảng hai chiều lưu trong bộ nhớ theo thứ tự nào?**
    - Mảng hai chiều được lưu trong bộ nhớ theo thứ tự dòng (row-major order).
        - Các phần tử trên cùng một hàng sẽ nằm liên tiếp nhau trong bộ nhớ.
        - Hết hàng 0 mới đến hàng 1, rồi hàng 2, …
    - Ví dụ:
        ```c
        int a[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };
        ```
        |        | cột 0     | cột 1     | cột 2     |
        | ------ | --------- | --------- | --------- |
        | hàng 0 | a[0][0]=1 | a[0][1]=2 | a[0][2]=3 |
        | hàng 1 | a[1][0]=4 | a[1][1]=5 | a[1][2]=6 |
10. **Có thể gán arr1 = arr2 không?**
    - Không, phải sao chép từng phần tử (dùng vòng lặp hoặc memcpy).
        - Cách 1: Dùng vòng lặp.
            ```c
            int arr1[5] = {1, 2, 3, 4, 5};
            int arr2[5];

            for (int i = 0; i < 5; i++) {
                arr2[i] = arr1[i];
            }
            ```
        - Cách 2: Dùng `mempy` (thư viện string.h)
            ```c
            #include <string.h>

            int arr1[5] = {1, 2, 3, 4, 5};
            int arr2[5];

            memcpy(arr2, arr1, 5 * sizeof(int));
            ```