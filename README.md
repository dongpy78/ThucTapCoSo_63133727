# Sắp xếp nhanh (Quick Sort)

Sắp xếp nhanh là một giải thuật chia để trị.
Sắp xếp nhanh chia một mảng lớn thành hai mảng con nhỏ hơn: mảng các phần tử nhỏ và các phần tử lớn. Sắp xếp nhanh có thể thiết kế bằng đệ quy.

Các bước : 

1. Chọn một phần tử gọi là chốt, từ mảng.
2. Phân vùng: sắp xếp lại thứ tự mảng để tất cả các phần tử có giá trị nhỏ hơn chốt đều nằm ở trước chốt, trong khi các phần tử có giá trị lớn hơn chốt đều đứng sau nó (các giá trị bằng chốt có thể nằm ở trước hay sau đều được). Sau khi phân vùng, chốt sẽ ở vị trí cuối cùng cùng nó. Đây được gọi là thao tác phân vùng.
3. Áp dụng đệ quy các bước trên cho mảng con gồm các phần tử có giá trị nhỏ hơn và cả mảng con gồm các phần tử có giá trị lớn hơn.

Ảnh động mô tả giải thuật sắp xếp nhanh, dòng ngang là giá trị chốt.

![Quicksort](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)
