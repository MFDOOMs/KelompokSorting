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

void isiNama(string& NamaFile){
    cout<<"Masukan Nama file : ";cin>>NamaFile;
}

 void inputChar(char& inpChar){
    cout<<"Karakter yang ingin dicari : ";cin>>inpChar;
}

void hitungJumlah(string NamaFile, int& jChar,char inpChar){
    ifstream teksfile;
    teksfile.open(NamaFile);

    if(teksfile.fail()){
        cerr << "Error saat membuka file. "<< endl;
    }
    else{
        cout<<"File ditemukan."<<endl;
        char ch;
        while(teksfile.get(ch)){
            inpChar = toupper(inpChar);
            ch = toupper(ch);
            if(ch == inpChar){
                jChar++;
            }
        }
    }
}

void output(string NamaFile,int jChar,char inpChar){
    cout<<"Nama File : "<<NamaFile<<endl;
    cout<<"Karakter yang ingin yang ingin dicari : "<<inpChar<<endl;
    cout<<"Jumlah karakter '"<<inpChar<<"' dalam file : "<<jChar<<endl;
}

int main(int argc, char const *argv[])
{
    string NamaFile;
    int jChar = 0;
    char inpChar;
    
    isiNama(NamaFile);
    inputChar (inpChar);
    hitungJumlah(NamaFile,jChar,inpChar);
    output(NamaFile,jChar,inpChar);
    return 0;
}
 