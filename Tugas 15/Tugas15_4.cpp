/*
Nama         : Fardan Fadhilah Andicha Putra
NPM          : 140810240084
Bagian       : Mengerjakan script tugas nomor 4 dan 5
Tanggal Buat : 8 Desember 2024

Nama         : Tristan Bonardo Silalahi
NPM          : 140810240058
Bagian       : Mengerjakan script tugas nomor 1 dan 2
Tanggal Buat : 8 Desember 2024

Nama         : Noell Valentino Timothy
NPM          : 140810240064
Bagian       : Mengerjakan script tugas nomor 3 dan laporan
Tanggal Buat : 8 Desember 2024
*/

#include <iostream>
#include <fstream>
using namespace std;


void enkripsi (string inFile, int geser){
    char karakter;

    ifstream fi;
    fi.open (inFile);

    ofstream fo;
    fo.open ("Tugas15_4_output.txt");

    if (!fi){
        cerr << "File tidak ada.";
    }

    while (fi.get(karakter)){
        if (karakter >= 65 && karakter <= 90-geser){
            karakter += geser;
        }
        else if (karakter > 90-geser && karakter <= 90){
            karakter -= 26-geser;
        }
        fo << karakter;
    }
}


int main (){
    string inFile;
    int geser;
    cout << "Masukkan nama file input: "; cin >> inFile;
    cout << "Masukkan besar pergesearannya: "; cin >> geser;
    enkripsi (inFile, geser);
}