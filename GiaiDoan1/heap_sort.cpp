#include <iostream>
using namespace std;

void heaptify(int a[], int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largets = i;
  if(l < n && a[l] > a[largets]) { // i co con ben trai
    largets = l;
  }
  if(r < n && a[r] > a[largets]) {
    largets = r;
  }
  if(largets != i) {
    swap(a[i], a[largets]);
    heaptify(a, n, largets);
  }
}

void heapsort(int a[], int n) {
  // xay dung max heap 
  for(int i = n/2-1; i >= 0; i--) {
    heaptify(a, n, i);
  }
  // 
  for(int i = n-1; i >= 0; i--) {
    swap(a[i], a[0]);
    heaptify(a, i, 0);
  }
}

int main() {
  system("cls");
  int n;
  cin >> n;
  int a[1000];
  for(int i = 0; i < n; i++) cin >> a[i];
  heapsort(a, n);
  for(int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}