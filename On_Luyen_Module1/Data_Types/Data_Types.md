23. **sizeof(struct ab) và sizeof(struct ba) là bao nhiêu?**
    ```c
    struct
    {
        int a;
        char b;
    } ab; // sizeof(struct ab) = 8 byte, 3 byte padding

    #pragma pack(push, 1)
    struct
    {
        char a;
        int b;
    } ba;
    #pragma pack(pop) // sizeof(struct ba) = 5 byte
    ```
25. **sizeof(mystruct) sẽ in ra gì?**
    ```c
    typedef struct {
        char x;
        int y;
    } mystruct; // sizeof(mystruct) = 8
    ```
26. **sizeof(struct A) là bao nhiêu trên hệ thống 32-bit?**
    ```c
    struct A {
        char a;
        int b;
        short c;
    }; // sizeof(struct A) = 12 byte, với 5 byte padding
    ```
27. **Ảnh hưởng của #pragma pack(1) là gì? Kết quả sizeof(struct B) là bao nhiêu trên hệ thống 32-bit?**
    ```c
    #pragma pack(push, 1)
    struct B {
        char a;
        int b;
        short c;
    };
    #pragma pack(pop)
    ```
    | Lệnh                    | Ý nghĩa                                | Dùng khi nào                      |
    | ----------------------- | -------------------------------------- | --------------------------------- |
    | `#pragma pack(n)`       | Căn chỉnh cố định (toàn file)          | Khi chỉ có 1 kiểu struct đặc biệt |
    | `#pragma pack(push, n)` | Tạm đổi căn chỉnh và lưu trạng thái cũ | Khi có nhiều struct khác nhau     |
    | `#pragma pack(pop)`     | Phục hồi căn chỉnh trước đó            | Khi muốn quay về mặc định         |
    **Ảnh hưởng của #pragma pack(1)** là bật chế độ căn từng 1 byte (không padding) cho toàn file. Thường sẽ có `#pragma pack()` khi ghi khởi tạo struct để trở lại căn chỉnh mặc định.