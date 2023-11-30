<img src="https://raw.githubusercontent.com/MicaelliMedeiros/micaellimedeiros/master/image/computer-illustration.png" alt="ilustração de um computador" min-width="400px" max-width="400px" width="400px" align="right">

### ⭐ Thuật Toán QuickSort
### 
<h6 style="font-size=18px;">💻 Cách Hoạt Động Của Thuật Toán Sắp Xếp Phân Đoạn (QuickSort)</h6>
<p>Xét dãy có n phần tử cần sắp xếp tăng dần (hoặc giảm dần).</p>

### Bước 1:
<p>- Chọn phần tử làm mốc.</p>
### Bước 2:
<p>- Chuyển các phần tử lớn hơn phần tử mốc sang một bên.</p>
<p>- Chuyển các phần tử nhỏ hơn phần tử mốc sang một bên.</p>
<p>Lặp lại bước 1 và 2 cho các phần tử nhỏ hơn và lớn hơn phần tử mốc.</p>

### 📈 Độ Phức Tạp Của Thuật Toán
<p>
 O(n*log(n)) --> O(n2)
 (phụ thuộc vào cách chọn phần tử làm mốc)
</p>
 
### ⭐ Thuật Toán Sắp Xếp Vun Đồng (HeapSort)
### 💻 Cách Hoạt Động Của Thuật Toán HeapSort:
<p>- Là sự cải tiến tốt hơn của giải thuật Selection Sort</p>
<p>- Xét dãy n phần tử cần sắp xếp tăng dần (hoặc giảm dần)</p>
<p>- Bước 1: Xếp các phần tử vào cây nhị phân</p>
<p>- Bước 2: Chọn phần tử lớn nhất từ cây nhị phân</p>
<p>- Bước 3: Chèn phần tử lớn nhất đó vào phần đã sắp xếp </p>
<p>- Bước 4: Tạo lại cây</p>
<p>- Lặp lại cho đến hết dãy</p>

### Phân Loại
<p>- Max heap: Khóa nút cha luôn lớn hơn khóa nút con</p>
<p>- Min heap: Khóa nút cha luôn nhỏ hơn khóa nút con</p>

 ### 📈 Độ Phức Tạp Của Thuật Toán
<p>
 - O(n*log(n))
</p>

### ⭐ Thuật Toán Sắp Xếp Hòa Nhập (Merge Sort)
### 💻 Cách Hoạt Động Của Thuật Toán Merge Sort:
### Bước 1:
<p>- Tách dãy cần sắp xếp thành từng phần tử riêng rẽ</p>

### Bước 2:
<p>- Lần lượt trộn (ghép) k = 2 nhóm phần tử kề nhau lại </p>
<p>- Sắp xếp tăng dần (giảm dần) từng nhóm </p>
<p>Lặp lại bước 2 với k = k * 2</p>














