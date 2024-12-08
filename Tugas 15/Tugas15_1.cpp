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
#include <cctype>
using namespace std;

void IsiNama(string& Namafile){
    cout << "Masukan Nama file : "; cin >> Namafile;
}

void hitungJumlah(string Namafile, int& jVokal,int& jKonsonan){
    ifstream teksfile;
    teksfile.open(Namafile);

    if(teksfile.fail()){
        cerr<<"Error saat membuka file."<<endl;
    }
    else{
        cout<<"file ditemukan."<<endl;
        char ch;
        while(teksfile.get(ch)){
            if(isalpha(ch)){
                ch = toupper(ch);
                if(ch == 'A' ||ch == 'E' ||ch == 'I' ||ch == 'O' ||ch == 'U'){
                    jVokal++;
                }
                else{
                    jKonsonan++;
                }
            }
        }
    }
    teksfile.close();

}

void output(string Namafile,int jVokal,int jKonsonan){
    cout<<"Nama File : "<<Namafile<<endl;
    cout<<"Jumlah Vokal : "<<jVokal<<endl;
    cout<<"Jumlah Konsonan : "<<jKonsonan<<endl;
}

int main(int argc, char const *argv[])
{
    string NamaFile;
    IsiNama(NamaFile);

    int jVokal = 0, jKonsonan = 0;
    hitungJumlah(NamaFile,jVokal,jKonsonan);
    output(NamaFile,jVokal,jKonsonan);
    return 0;
}