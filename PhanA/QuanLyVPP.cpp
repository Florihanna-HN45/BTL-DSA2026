#ifndef QUANLYVPP_CPP
#define QUANLYVPP_CPP

#include <iostream>
#include <vector>     
#include <algorithm>  
#include "VanPhongPham.cpp"

using namespace std;

class QuanLyVPP {
private:
    vector<VanPhongPham> ds; 

public:
    void nhapDanhSach() {
        int n;
        cout << "Nhap so luong van phong pham: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "--- Nhap san pham thu " << i + 1 << " ---\n";
            VanPhongPham vpp;
            cin >> vpp;
            ds.push_back(vpp); 
        }
    }

    void xuatDanhSach() {
        if (ds.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }
        cout << "\n=== KHO VAN PHONG PHAM ===\n";
        for (const auto& vpp : ds) {
            cout << vpp << "\n";
        }
        cout << "==========================\n";
    }

    void sapXep() {
        if (ds.empty()) return;
        sort(ds.begin(), ds.end());      
        cout << "Da sap xep tang dan theo don gia.\n";
    }

    void themSanPham() {
        cout << "\n--- Them van phong pham moi ---\n";
        VanPhongPham vpp;
        cin >> vpp;
        ds.push_back(vpp);
        cout << "Them thanh cong!\n";
    }

    void timMaxGia() {
        if (ds.empty()) {
            cout << "Danh sach trong!\n";
            return;
        }
        auto max_it = max_element(ds.begin(), ds.end());
        cout << "San pham co don gia cao nhat:\n" << *max_it << "\n";
    }

    void timKiemTheoMa(const string& ma) {
        bool found = false;
        for (const auto& vpp : ds) {
            if (vpp.getMaVPP() == ma) {
                cout << "Tim thay: " << vpp << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "Khong ton tai san pham ma: " << ma << "\n";
    }

    void xoaTheoMa(const string& ma) {
        for (auto it = ds.begin(); it != ds.end(); ++it) {
            if (it->getMaVPP() == ma) {
                ds.erase(it);
                cout << "Da xoa san pham ma " << ma << "\n";
                return;
            }
        }
        cout << "Khong ton tai ma " << ma << " de xoa.\n";
    }
};

#endif