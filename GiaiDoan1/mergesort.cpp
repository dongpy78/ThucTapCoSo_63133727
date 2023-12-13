// Thuật toán Merge Sort
#include <iostream>
#include <conio.h>
using namespace std;

void print(int arr[], int l, int r) {
  for (int i = l; i <= r; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
  getch();
}

// Gộp mảng sau khi sắp xếp
void Merge(int arr[], int left, int right, int mid) {
  int size_left = mid - left + 1, size_right = right - mid;
  int a[size_left], b[size_right];
  int max = 999999999;

  // Mảng trái
  for (int i = 0, j = left; i < size_left; i++, j++) {
    a[i] = arr[j];
  }

  // Mảng phải
  for (int i = 0, j = mid+1; i < size_right; i++, j++) {
    b[i] = arr[j];
  }

  a[size_left] = b[size_right] = max; 
  // Ráp 2 mảng con theo thứ tự tăng dần
  int _a = 0, _b = 0;
  for (int i = left; i <= right; i++) {
    if (a[_a] < b[_b]) arr[i] = a[_a++];
    else arr[i] = b[_b++];
  }
  cout << "Gop 2 mang tren thanh: ";
  print(arr, left, right);
}

// Phân chia
void MergeSort(int arr[], int left, int right) {
  if (left >= right) return;
  int mid = (left + right) / 2;

  cout << "Xu ly mang trai tu: ";
  print(arr, left, mid);
  MergeSort(arr, left, mid);

  cout << "Xu ly mang phai tu: ";
  print(arr, mid+1, right);
  MergeSort(arr, mid+1, right);

  Merge(arr, left, right, mid);
}

int main() {
  system("cls");
  // int arr[] = {2, 1, 4, 0, 5, 12, 7, 0, 2, 45, 98, 20};
  int arr[] = {9, 2, 3, 0, 12, 4, 7};
  int size = sizeof(arr)/sizeof(int);

  cout << "Mang ban dau: ";
  print(arr, 0, size-1);
  MergeSort(arr, 0, size-1);
  // for (int i = 0; i < size; i++) {
  //   cout << arr[i] << " ";
  // }
}