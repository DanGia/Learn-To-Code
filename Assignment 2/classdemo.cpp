#include <iostream>
using namespace std;

class SinhVien
{
public:
    SinhVien(int n, string ht);
    void Display();

    void setHoTen(string ht);
    string getHoTen();

    // che giau du lieu, casc thanh phan private
private:
    int MaSV;
    string HoTen;
};

SinhVien::SinhVien(int n, string ht)
{
    MaSV = n;
    HoTen = ht;
}

void SinhVien::setHoTen(string ht)
{
    HoTen = ht;
}
string SinhVien::getHoTen()
{
    return HoTen;
}
void SinhVien::Display()
{
    cout << "Ma sinh vien: " << MaSV << endl;
    cout << "Ho va ten   : " << HoTen << endl;
}

int main()
{
    SinhVien sv(1, "Dang Hoang Gia");
    sv.Display();
    sv.setHoTen("Nguyen Ngoc Thanh Truc");

    cout << "Ho va ten   :" << sv.getHoTen() << endl;

    sv.Display();
    // system("pause");
    return 0;
}