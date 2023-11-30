# Sắp xếp nhanh (Quick Sort)

Sắp xếp nhanh là một giải thuật chia để trị.
Sắp xếp nhanh chia một mảng lớn thành hai mảng con nhỏ hơn: mảng các phần tử nhỏ và các phần tử lớn. Sắp xếp nhanh có thể thiết kế bằng đệ quy.

Các bước : 

1. Chọn một phần tử gọi là chốt, từ mảng.
2. Phân vùng: sắp xếp lại thứ tự mảng để tất cả các phần tử có giá trị nhỏ hơn chốt đều nằm ở trước chốt, trong khi các phần tử có giá trị lớn hơn chốt đều đứng sau nó (các giá trị bằng chốt có thể nằm ở trước hay sau đều được). Sau khi phân vùng, chốt sẽ ở vị trí cuối cùng cùng nó. Đây được gọi là thao tác phân vùng.
3. Áp dụng đệ quy các bước trên cho mảng con gồm các phần tử có giá trị nhỏ hơn và cả mảng con gồm các phần tử có giá trị lớn hơn.

Ảnh động mô tả giải thuật sắp xếp nhanh, dòng ngang là giá trị chốt.

![Quicksort](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

## Độ phức tạp

| Name                  | Best            | Average             | Worst               | Memory    | Stable    | Comments  |
| --------------------- | :-------------: | :-----------------: | :-----------------: | :-------: | :-------: | :-------- |
| **Quick sort**        | n&nbsp;log(n)   | n&nbsp;log(n)       | n<sup>2</sup>       | log(n)    | No        |  Quicksort is usually done in-place with O(log(n)) stack space |


## Liên kết

- [Wikipedia](https://en.wikipedia.org/wiki/Quicksort)
- [YouTube](https://www.youtube.com/watch?v=SLauY6PpjW4&index=28&list=PLLXdhg_r2hKA7DPDsunoDZ-Z769jWn4R8)


# Sắp xếp trộn (Merge Sort)

Trong khoa học máy tính, sắp xếp trộn là một thuật toán sắp xếp đa dụng có hiệu quả rất cao. Nó được xếp vào thể loại sắp xếp so sánh. Trong hầu hết trường hợp nó sẽ bảo tồn thứ tự đầu vào của các phần tử bằng nhau sau khi sắp xếp. Sắp xếp trộn là một ví dụ về thuật toán chia để trị do John von Neumann phát minh năm 1945.

Ví dụ về sắp xếp trộn. Nó chia danh sách thành các đơn vị nhỏ nhất (1 phần tử), so sánh từng phần tử giữa các đơn vị liền kề, sắp xếp và hợp nhất hai danh sách liền kề. Cuối cùng tất cả các phần tử được sắp xếp theo thứ tự.

![Merge Sort](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

Sắp xếp trộn bằng đệ quy trên một mảng 7 phần tử. Đây là những bước sắp xếp trộn từ dưới lên.

![Merge Sort](https://upload.wikimedia.org/wikipedia/commons/e/e6/Merge_sort_algorithm_diagram.svg)

## Độ phức tạp

| Name                  | Best            | Average             | Worst               | Memory    | Stable    | Comments  |
| --------------------- | :-------------: | :-----------------: | :-----------------: | :-------: | :-------: | :-------- |
| **Merge sort**        | n&nbsp;log(n)   | n&nbsp;log(n)       | n&nbsp;log(n)       | n         | Yes       |           |

## Liên kết

- [Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)
- [YouTube](https://www.youtube.com/watch?v=KF2j-9iSf4Q&index=27&list=PLLXdhg_r2hKA7DPDsunoDZ-Z769jWn4R8)




# Sắp xếp vun đống (Heap Sort)

Sắp xếp vun đống thuộc loại sắp xếp so sánh.
Sắp xếp vun đống có thể coi là một cải tiến của sắp xếp chọn: nó chia đầu vào thành vùng đã sắp xếp và vùng chưa được sắp xếp, sau đó thu nhỏ vùng chưa sắp xếp bằng cách lấy phần tử lớn nhất và thêm nó vào mảng đã sắp xếp. Lặp đi lặp lại nhiều lần để có được mảng đã sắp xếp hoàn toàn. Cải tiến ở đây nằm ở việc sử dụng cấu trúc dữ liệu heap chứ vẫn là tìm kiếm giá trị lớn nhất theo thời gian tuyến tính.

![Algorithm Visualization](https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif)

![Algorithm Visualization](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif)

## Độ phức tạp

| Name                  | Best            | Average             | Worst               | Memory    | Stable    | Comments  |
| --------------------- | :-------------: | :-----------------: | :-----------------: | :-------: | :-------: | :-------- |
| **Heap sort**         | n&nbsp;log(n)   | n&nbsp;log(n)       | n&nbsp;log(n)       | 1         | No        |           |

## Liên kết

[Wikipedia](https://en.wikipedia.org/wiki/Heapsort)
