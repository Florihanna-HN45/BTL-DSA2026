#ifndef APP_CPP
#define APP_CPP

#include <iostream>
#include <string>
#include "QuanLyVPP.cpp"

using namespace std;

class App {
private:
    QuanLyVPP ql;

    void hienThiMenu() {
        cout << "\n=========================================\n";
        cout << "      QUAN LY KHO VAN PHONG PHAM         \n";
        cout << "=========================================\n";
        cout << "1. Nhap danh sach san pham ban dau\n";
        cout << "2. Hien thi kho hang\n";
        cout << "3. Sap xep danh sach theo gia (Tang dan)\n";
        cout << "4. Nhap them san pham vao kho\n";
        cout << "5. Tim san pham co gia MAX\n";
        cout << "6. Tim kiem san pham theo Ma\n";
        cout << "7. Xoa san pham theo Ma\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "=========================================\n";
        cout << "Chon chuc nang: ";
    }

public:
    void run() {
        int luaChon;
        string ma;
        do {
            hienThiMenu();
            cin >> luaChon;
            
            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            switch (luaChon) {
                case 1: ql.nhapDanhSach(); break;
                case 2: ql.xuatDanhSach(); break;
                case 3: 
                    ql.sapXep(); 
                    ql.xuatDanhSach(); 
                    break;
                case 4: ql.themSanPham(); break;
                case 5: ql.timMaxGia(); break;
                case 6:
                    cout << "Nhap Ma VPP can tim: ";
                    cin >> ma;
                    ql.timKiemTheoMa(ma);
                    break;
                case 7:
                    cout << "Nhap Ma VPP can xoa: ";
                    cin >> ma;
                    ql.xoaTheoMa(ma);
                    break;
                case 0:
                    cout << "Ket thuc chuong trinh!\n";
                    break;
                default:
                    cout << "Lua chon sai. Vui long nhap lai!\n";
            }
        } while (luaChon != 0);
    }
};

#endif