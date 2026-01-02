25. **Có vấn đề gì với hàm copy sau?**
    ```c
    int copy(char *scr, char *dst, unsigned int size) {
        char *s1;
        while (size--) {
            *s1++ = *scr++;
            *dst++ = *s1;
        }
        return 0;
    }
    ```
    - Con trỏ *s1 khởi tạo mà không có địa chỉ hợp lệ -> Wild Pointer. Cần phải cấp phát cho s1 **size** byte trong heap. Và cần lưu ý là phải free(s1) để giải phóng vùng đã cấp phát.
    - Logic phần vòng lặp `while()` chưa chính xác. Cụ thể là, s1 ghi xong tăng lên 1, và dst sẽ ghi lại giá trị tại s1++ (đây là vùng chưa được ghi) => cứ như vậy đến cuối dst không thể ghi được gì.
    **Sửa lại chương trình:**
    
        ```c
        int copy(char *scr, char *dst, unsigned int size) {
            char *s1 = malloc(size);

            while (size--) {
                *s1++ = *scr++;
                *dst++ = *(s1-1);
            }

            free(s1);
            return 0;
        }

