let bars = [];
const def = "#fd0081",
  chng = "#431f91",
  finished = "#20c997",
  selected = "yellow";

// Gọi hàm setup khi cửa sổ đã được tải hoàn toàn.
window.onload = setup();

// Khởi tạo ứng dụng khi cửa sổ được tải hoàn toàn.
// Tạo thanh dựa trên giá trị đầu vào ban đầu.
async function setup() {
  let b = document.getElementById("bars");
  let d = document.getElementById("delay");
  document.getElementById("b").innerText = b.value;
  document.getElementById("d").innerText = d.value + "ms";

  if (bars.length != parseInt(b.value)) {
    generateBars(parseInt(b.value));
  }
}

// Tải lại trang trở về trạng thái ban đầu
function reset() {
  location.reload();
}

// Vô hiệu hóa tất cả các phần tử đầu vào trên trang và trả về giá trị độ trễ được nhập từ người dùng.
function Disable_The_Input() {
  let x = document.getElementsByTagName("input");
  for (let i = 0; i < x.length; i++) x[i].disabled = true;
  return parseInt(document.getElementById("delay").value);
}

// Tô màu tất cả các thanh trong mảng với màu đã hoàn thành.
function Finished_Sorting() {
  let x = document.getElementsByClassName("bar");
  for (let i = 0; i < x.length; i++) x[i].style.backgroundColor = finished;
  x = document.getElementsByTagName("input");
  for (let i = 0; i < x.length; i++) x[i].disabled = false;
}

// Tạo ra một mảng các thanh (bars) có chiều cao ngẫu nhiên để đại diện cho một mảng các giá trị.
// n: Số lượng thanh cần tạo (giá trị mặc định là một số ngẫu nhiên từ 0 đến 20).
function generateBars(n = -1) {
  bars = [];
  let container = document.getElementById("container");
  n = n < 0 ? Math.random() * 20 : n;
  for (let i = 0; i < n; i++) {
    bars.push(
      '<div class="bar" id="' +
        i +
        '" style="height:' +
        Math.floor(2 + Math.random() * 98) +
        '%"></div>'
    );
  }
  container.innerHTML = bars.join("");
}

// Trả về một promise, làm chậm thực hiện chương trình trong một khoảng thời gian cụ thể (theo miligiây).
function Sleep(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

// Ánh xạ một giá trị từ một khoảng giá trị sang một khoảng giá trị khác.
// Nhận giá trị đầu vào (value) và ánh xạ nó từ khoảng (in_min đến in_max) sang khoảng (out_min đến out_max).
function MapRange(value, in_min, in_max, out_min, out_max) {
  return ((value - in_min) * (out_max - out_min)) / (in_max - in_min) + out_min;
}
//=============================== Thuật Toán Sắp Xếp ==================================//

// 1
// MERGE SORT
// Di chuyển thanh tại vị trí r về vị trí trái nhất l bằng cách trượt các thanh khác sang phải.
function Slide_down(l, r) {
  let temp = bars[r];
  for (let i = r - 1; i >= l; i--) {
    bars[i + 1] = bars[i];
  }
  bars[l] = temp;
}

// Gộp hai mảng con từ vị trí l đến m và từ m+1 đến r thành một mảng đã sắp xếp.
// Sử dụng hình ảnh và thay đổi màu sắc để hiển thị các bước so sánh và gộp.
async function merge(l, m, r, d) {
  let y = l;
  let i = l;
  let j = m + 1;

  while (i < j && j <= r) {
    let curr_id = bars[j].split('id="')[1].split('"')[0];
    let nxt_ele = bars[i].split('id="')[1].split('"')[0];
    document.getElementById(curr_id).style.backgroundColor = selected;
    document.getElementById(nxt_ele).style.backgroundColor = chng;
    let a = parseInt(bars[j].split(/[:%]/)[1]);
    let b = parseInt(bars[i].split(/[:%]/)[1]);

    if (a > b) i++;
    else {
      Slide_down(i, j);
      i++;
      j++;
    }
    await Sleep(d / 2.0);
    container.innerHTML = bars.join("");
    document.getElementById(curr_id).style.backgroundColor = selected;
    document.getElementById(nxt_ele).style.backgroundColor = chng;
    let sound = MapRange(
      document.getElementById(curr_id).style.height.split("%")[0],
      2,
      100,
      500,
      1000
    );

    await Sleep(d / 2.0);
    document.getElementById(curr_id).style.backgroundColor = def;
    document.getElementById(nxt_ele).style.backgroundColor = def;
    sound = MapRange(
      document.getElementById(curr_id).style.height.split("%")[0],
      2,
      100,
      500,
      1000
    );
  }
}

// Chia đệ quy mảng thành hai nửa cho đến khi mỗi mảng con chỉ có một phần tử, sau đó gộp chúng lại theo thứ tự.
async function mergeSort(l, r, d) {
  if (l < r) {
    let m = parseInt(l + (r - l) / 2);
    await mergeSort(l, m, d);
    await mergeSort(m + 1, r, d);
    await merge(l, m, r, d);
  }
}

async function MergeSort() {
  let delay = Disable_The_Input();
  await mergeSort(0, bars.length - 1, delay);
  Finished_Sorting();
}

// 2
// QUICK SORT
// Chọn phần tử cuối cùng r làm chốt và đặt nó vào vị trí đúng trong mảng.
// Sử dụng hình ảnh và thay đổi màu sắc để hiển thị các bước so sánh và đổi chỗ.
async function Partition(l, r, d) {
  let i = l - 1;
  let j = l;
  let id = bars[r].split('id="')[1].split('"')[0];
  document.getElementById(id).style.backgroundColor = selected;
  for (j = l; j < r; j++) {
    let a = parseInt(bars[j].split(/[:%]/)[1]);
    let b = parseInt(bars[r].split(/[:%]/)[1]);
    if (a < b) {
      i++;
      let curr_id = bars[i].split('id="')[1].split('"')[0];
      let nxt_ele = bars[j].split('id="')[1].split('"')[0];
      document.getElementById(curr_id).style.backgroundColor = chng;
      document.getElementById(nxt_ele).style.backgroundColor = chng;

      let temp = bars[i];
      bars[i] = bars[j];
      bars[j] = temp;

      await Sleep(d / 3.0);
      container.innerHTML = bars.join("");
      document.getElementById(curr_id).style.backgroundColor = chng;
      document.getElementById(nxt_ele).style.backgroundColor = chng;
      document.getElementById(id).style.backgroundColor = selected;
      let sound = MapRange(
        document.getElementById(curr_id).style.height.split("%")[0],
        2,
        100,
        500,
        1000
      );
      await Sleep(d / 3.0);
      document.getElementById(curr_id).style.backgroundColor = def;
      document.getElementById(nxt_ele).style.backgroundColor = def;
    }
  }

  let temp = bars[i + 1];
  bars[i + 1] = bars[r];
  bars[r] = temp;

  container.innerHTML = bars.join(" ");
  document.getElementById(id).style.backgroundColor = selected;
  await Sleep(d / 3.0);
  document.getElementById(id).style.backgroundColor = def;
  return i + 1;
}

// Chọn chốt và phân chia mảng thành hai nửa cho đến khi toàn bộ mảng được sắp xếp.
async function quickSort(l, r, d) {
  if (l < r) {
    let p = await Partition(l, r, d);
    await quickSort(l, p - 1, d);
    await quickSort(p + 1, r, d);
  }
}

async function QuickSort() {
  let delay = Disable_The_Input();
  await quickSort(0, bars.length - 1, delay);
  Finished_Sorting();
}

// 3
// HEAP SORT
// Đảm bảo rằng cây con tại i tuân theo tính chất max-heap.
// Sử dụng hình ảnh và thay đổi màu sắc để hiển thị các bước so sánh và đổi chỗ.
async function Heapfiy(n, i, d) {
  let largest = i;
  let l = 2 * i + 1; // lft
  let r = 2 * i + 2; // rgt
  let curr_id = bars[i].split('id="')[1].split('"')[0];
  let nxt_ele;
  let id3;

  document.getElementById(curr_id).style.backgroundColor = selected;
  if (r < n) {
    id3 = bars[r].split('id="')[1].split('"')[0];
    document.getElementById(id3).style.backgroundColor = chng;
  }
  if (l < n) {
    nxt_ele = bars[l].split('id="')[1].split('"')[0];
    document.getElementById(nxt_ele).style.backgroundColor = chng;
  }
  await Sleep(d / 3.0);
  if (
    l < n &&
    parseInt(bars[l].split(/[:%]/)[1]) >
      parseInt(bars[largest].split(/[:%]/)[1])
  )
    largest = l;
  if (
    r < n &&
    parseInt(bars[r].split(/[:%]/)[1]) >
      parseInt(bars[largest].split(/[:%]/)[1])
  )
    largest = r;

  if (largest != i) {
    let t = bars[i];
    bars[i] = bars[largest];
    bars[largest] = t;
    container.innerHTML = bars.join(" ");
    document.getElementById(curr_id).style.backgroundColor = selected;
    let sound = MapRange(
      document.getElementById(curr_id).style.height.split("%")[0],
      2,
      100,
      500,
      1000
    );
    // beep(100, sound, d);
    if (r < n) document.getElementById(id3).style.backgroundColor = chng;
    if (l < n) document.getElementById(nxt_ele).style.backgroundColor = chng;
    await Sleep(d / 3.0);
    container.innerHTML = bars.join(" ");
    await Heapfiy(n, largest, d);
  }
  container.innerHTML = bars.join(" ");
}

// Xây dựng một max heap và lặp đi lặp lại việc trích xuất phần tử tối đa để sắp xếp mảng.
async function HeapSort() {
  let delay = Disable_The_Input();
  let n = bars.length;
  for (
    let i = n / 2 - 1;
    i >= 0;
    i-- // Build the heap
  )
    await Heapfiy(n, i, delay);

  for (let i = n - 1; i >= 0; i--) {
    let t = bars[0]; // Swaping
    bars[0] = bars[i];
    bars[i] = t;

    container.innerHTML = bars.join(" ");
    await Heapfiy(i, 0, delay);
  }
  Finished_Sorting();
}
