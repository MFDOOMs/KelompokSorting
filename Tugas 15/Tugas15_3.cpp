#include <iostream>
#include <fstream>
using namespace std;

void inputFileTxt(string &txt);
void periksaFile(string namaFile);
int hitungKurawal(string namaFile);
void outputDariTeks(string namaFile);

int main() {
    string teks = "";
    
    inputFileTxt(teks);
    periksaFile(teks);
    outputDariTeks(teks);
}

void inputFileTxt(string &txt){
    cout << "Masukkan nama file txt: "; cin >> txt;
}

void periksaFile(string namaFile) {
    ifstream fileTeks;
    fileTeks.open(namaFile);

    if (fileTeks.fail()) {
        cerr << "Error saat membuka file!" << endl;
        exit(1);
    } else {
        cout << "File ditemukan\n";
    }

    fileTeks.close();
}

int hitungKurawal(string namaFile) {
    int kurawal = 0;

    ifstream fileTeks;
    fileTeks.open(namaFile);   

    char ch;
    while(fileTeks.get(ch)){
        if (ch == '{') {    // setiap satu pasang kurawal pasti memiliki satu { dan satu }, sehingga hanya perlu menghitung salah satu
            kurawal++;
        }
    }

    fileTeks.close();
    return kurawal;
}

void outputDariTeks(string namaFile){
    string namaProgram;

    ifstream fileTeks;
    fileTeks.open(namaFile);

    while(getline(fileTeks, namaProgram)) {
        cout << "Nama Program : " << namaProgram << "\n";
        cout << "Jumlah kurung kurawal : " << hitungKurawal(namaProgram) << " pasang.\n";
    }
}

