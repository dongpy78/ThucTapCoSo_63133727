#include<iostream>
using namespace std;

class Nguoi {
  private:
    string ten;
    int tuoi;

  public:
    Nguoi(string ten, int tuoi) {
      this->ten = ten;
      this->tuoi = tuoi;
    }

    void ThongTin() {
      cout << "Ten: " << ten << endl;
      cout << "Tuoi: " << tuoi << endl;
    }

    void setTen(string ten) {
      this->ten = ten;
    }

    string getTen() {
      return ten;
    }
};

int main() {
  system("cls");
  Nguoi a = Nguoi("Nguyen Anh Quan", 20);
  a.ThongTin();
  a.setTen("Bui Van Dong");
  cout << a.getTen();
}