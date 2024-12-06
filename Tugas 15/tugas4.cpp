#include <iostream>
#include <fstream>
using namespace std;

typedef char larik[100];

void enkripsi (string inFile, string outFile){
    char karakter;
    larik encript;
    int i = 0;
    ifstream fi;
    ofstream fo;
    fi.open (inFile);
    fo.open (outFile);
    if (!fi){
        cerr << "File tidak ada.";
    }
    while (fi.get(karakter)){
        if (karakter >= 65 && karakter <= 88){
            karakter += 2;
        }
        else if (karakter >=89 && karakter <= 90){
            karakter -= 24;
        }
        fo << karakter;
        i++;
    }
}


int main (){
    string inFile;
    string outFile;
    cout << "Masukkan nama file input: "; cin >> inFile;
    cout << "Masukkan nama file output: "; cin >> outFile;
    enkripsi (inFile, outFile);
}