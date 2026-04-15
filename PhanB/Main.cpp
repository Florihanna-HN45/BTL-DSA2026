#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "Hashtable.cpp" 
#include "myvector.cpp" // Xay dung ham vector

using namespace std;

// Thuật toán băm
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
        if (isalpha(c)) cleaned += tolower(c);
    }
    return cleaned;
}

int main() {
    Hashtable<string, bool> dictionary(10007);
    myvector<string> wordList; 
    
    string filename = "dictionary.txt";
    string word;

    /* 1. NẠP TỪ ĐIỂN */
    ifstream inFile(filename);
    if (inFile) {
        while (inFile >> word) {
            string cw = cleanWord(word);
            if (cw != "" && !dictionary.Contains(cw, stringHash)) {
                dictionary.Add(cw, true, stringHash);
                wordList.push_back(cw); 
            }
        }
        inFile.close();
        cout << "Da nap thanh cong " << wordList.size() << " tu vung.\n";
    }

    /* 2. NHẬP VÀ KIỂM TRA */
    cout << "Nhap doan van can kiem tra (Go 'END' de ket thuc):\n";
    string line, paragraph = "";
    while (getline(cin, line) && line != "END") {
        paragraph += line + " ";
    }

    stringstream ss(paragraph);
    myvector<string> misspelledWords; 
    bool hasError = false;

    cout << "\n[ KET QUA QUET LOI ]\n";
    while (ss >> word) {
        string cw = cleanWord(word);
        if (cw != "" && !dictionary.Contains(cw, stringHash)) {
            cout << "  -> Tu sai/chua biet: '" << cw << "'\n";
            misspelledWords.push_back(cw);
            hasError = true;
        }
    }

    /* 3. CẬP NHẬT TỪ MỚI */
    if (hasError) {
        cout << "\nCap nhat tu moi vao tu dien? (Y/N): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            for (int i = 0; i < misspelledWords.size(); i++) {
                string w = misspelledWords[i]; 
                if (!dictionary.Contains(w, stringHash)) { 
                    dictionary.Add(w, true, stringHash);
                    wordList.push_back(w);
                }
            }
        }
    }

    /* 4. GHI FILE */
    ofstream outFile(filename);
    if (outFile) {
        for (int i = 0; i < wordList.size(); i++) {
            outFile << wordList[i] << "\n"; 
        }
        outFile.close();
        cout << "\n[+] Da ghi toan bo vao file.\n";
    }

    return 0;
}