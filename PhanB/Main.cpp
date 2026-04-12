#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include "Hashtable.cpp" 

using namespace std;

int stringHash(string key, int m) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash % m;
}

string cleanWord(string word) {
    string cleaned = "";
    for (char c : word) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

int main() {
    Hashtable<string, bool> dictionary(10007);
    vector<string> wordList;
    string filename = "dictionary.txt";
    string word;

    ifstream inFile(filename);
    if (!inFile) {
        cout << "[!] Chua co file tu dien (" << filename << "). He thong se tao file moi o cuoi chuong trinh.\n";
    } else {
        while (inFile >> word) {
            string cw = cleanWord(word);
            if (cw != "" && !dictionary.Contains(cw, stringHash)) {
                dictionary.Add(cw, true, stringHash);
                wordList.push_back(cw);
            }
        }
        inFile.close();
        cout << "[+] Da nap thanh cong " << wordList.size() << " tu vung vao he thong.\n";
    }

    cout << "\n--- BO KIEM TRA CHINH TA ---\n";
    cout << "Nhap doan van can kiem tra (Go 'END' tren 1 dong moi va an Enter de ket thuc):\n";
    
    string line, paragraph = "";
    while (getline(cin, line) && line != "END") {
        paragraph += line + " ";
    }

    stringstream ss(paragraph);
    vector<string> misspelledWords;
    bool hasError = false;

    cout << "\n[ KET QUA QUET LOI ]\n";
    while (ss >> word) {
        string cw = cleanWord(word);
         if (cw != "" && !dictionary.Contains(cw, stringHash)) {
            cout << "  -> Phat hien tu sai hoac chua biet: '" << cw << "'\n";
            misspelledWords.push_back(cw);
            hasError = true;
        }
    }

    if (!hasError) {
        cout << " Khong phat hien loi chinh ta nao.\n";
    } else {
         cout << "\n[?] Ban co muon cap nhat cac tu moi nay vao tu dien khong? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            for (string w : misspelledWords) {
                if (!dictionary.Contains(w, stringHash)) { 
                    dictionary.Add(w, true, stringHash);
                    wordList.push_back(w);
                }
            }
            cout << "[+] Da dua tu vung moi vao bo nho tam.\n";
        }
    }

    ofstream outFile(filename);
    if (outFile) {
        for (string w : wordList) {
            outFile << w << "\n";
        }
        outFile.close();
        cout << "\n[+] Hoan tat! Da ghi toan bo " << wordList.size() << " tu vao file '" << filename << "'.\n";
    } else {
        cout << "\n[-] LOI: Khong the mo file de ghi du lieu.\n";
    }

    return 0;
}