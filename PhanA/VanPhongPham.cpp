//"""
//Nguyen Thi Hoa
//maSV: _6
//Vector
// de tai: Quan ly van phong pham.
//"""

//BUOC 1 - KHAI BAO THU VIEN
#ifndef VANPHONGPHAM_CPP
#define VANPHONGPHAM_CPP

#include <iostream>
#include <string>

using namespace std;

class VanPhongPham {
private:
    string maVPP;
    string tenVPP;
    string phanLoai;
    double donGia;

public:
    VanPhongPham() : maVPP(""), tenVPP(""), phanLoai(""), donGia(0.0) {}

    string getMaVPP() const { return maVPP; }
    double getDonGia() const { return donGia; }

    friend istream& operator>>(istream& is, VanPhongPham& vpp) {
        cout << "Nhap ma VPP: ";
        is >> vpp.maVPP;
        is.ignore(); 
        cout << "Nhap ten san pham: ";
        getline(is, vpp.tenVPP);
        cout << "Nhap phan loai (But/So/Keo...): ";
        getline(is, vpp.phanLoai);
        cout << "Nhap don gia: ";
        is >> vpp.donGia;
        return is;
    }

    friend ostream& operator<<(ostream& os, const VanPhongPham& vpp) {
        os << "Ma: " << vpp.maVPP 
           << " | Ten: " << vpp.tenVPP 
           << " | Loai: " << vpp.phanLoai 
           << " | Gia: " << vpp.donGia;
        return os;
    }

    bool operator<(const VanPhongPham& other) const {
        return this->donGia < other.donGia;
    }
};

#endif