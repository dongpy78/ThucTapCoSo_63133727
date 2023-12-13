#include <stdio.h>

int partition(int a[], int l, int r) {
  int i = l - 1; // cho chi so i = -1
  int pivot = a[r]; // chon khoa la phan tu cuoi cung trong mang
  for(int j = l; j < r; j++) {
    // neu a[j] > pivot : bo qua
    if(a[j] <= pivot) {
      // dua a[j] len dau
      ++i; // tang i len va hoan vi a[i] va a[j]
      int tam = a[i];
      a[i] = a[j];
      a[j] = tam;
    }
  }
  // dua chot vao giua
  ++i;
  int tam = a[i];
  a[i] = a[r];
  a[r] = tam;
  printf("\nphan hoach tu chi so: %d toi %d\n", l, r);
  for(int i = l; i <= r; i++) {
    printf("%5d", a[i]);
  }
  printf("\n");
  return i; // dung de goi de quy ben trai hoac ben phai
}

void quick_sort(int a[], int l, int r) {
  printf("\nloi goi ham quick sort: %d %d\n", l, r);
  if(l < r) {
    int pos = partition(a, l, r); // phan hoach left right    
    printf("\nGia tri cua pos la: %d", pos);
    quick_sort(a, l, pos-1); // xet de quy ve phia day ben trai    
    quick_sort(a, pos+1, r); // xet de quy ve phia day ben phai      
  }  
}

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  // nhap mang
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // goi ham
  quick_sort(a, 0, n-1);

  // xuat mang
  for(int i = 0; i < n; i++) {
    printf("%5d", a[i]);
  }
  return 0;
}