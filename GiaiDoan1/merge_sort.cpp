#include <stdio.h>
#include <windows.h>

// Thao tac tron co nhiem vu tron cac phan tu tu chi so left => mid va cac phan tu tu chi mid + 1 +. right
// thanh cac phan tu tang dan 
// O(N + M)

void merge(int a[], int l, int m, int r) {
  // tam thoi luu cac phan tu tu chi so l => r vao 1 mang
  // luu cac phan tu tu chi so m + 1 => r vao 1 mang
  int n1 = m - l + 1, n2 = r - m;
  int x[n1], y[n2];
  // dua cac phan tu tu chi so l => m vao mang x
  for(int i = 0; i < n1; i++) {
    x[i] = a[l+i];    
  }
  // dua cac phan tu chi so m + 1 => r vao mang y
  for(int i = 0; i < n2; i++) {
    y[i] = a[m + i + 1];
  }
  // tron 2 mang x, y => gan lai cho mang a[l, r]
  int index = l;
  int i = 0, j = 0;
  while(i < n1 && j < n2) {
    if(x[i] <= y[j]) {
      a[index++] = x[i++];
    } else {
      a[index++] = y[j++];
    }
  }
  while(i < n1) {
    a[index++] = x[i++];
  }
  while(j < n2) {
    a[index++] = y[j++];
  }
}

void mergeSort(int a[], int l, int r) {
  if(l < r) {
    int m = (l + r) / 2; // tinh chi so o giua
    mergeSort(a, l, m); // goi de quy ben trai
    mergeSort(a, m+1, r); // goi de quy ben phai
    merge(a, l, m, r);
  }
}

int main() {
  system("cls");
  int n; 
  scanf("%d", &n);
  int a[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  mergeSort(a, 0, n-1);
  for(int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}