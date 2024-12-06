#include <iostream>
#include <fstream>
using namespace std;

string inputFileTxt();
void periksaFile(string namaFile);
int hitungKurawal(string namaFile);

int main() {
    string teks = inputFileTxt();

    periksaFile(teks);
    
    cout << "Jumlah pasangan kurung kurawal yang ada pada file teks tersebut yaitu : " << hitungKurawal(teks) << " pasang";
}

string inputFileTxt(){
    string txt;
    cout << "Masukkan nama file txt: "; cin >> txt;
    return txt;
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