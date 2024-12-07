#include <iostream>
#include <fstream>
using namespace std;

typedef char larik[100];

void enkripsi (string inFile, int geser){
    char karakter;
    larik encript;
    int i = 0;

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
        i++;
    }
}


int main (){
    string inFile;
    int geser;
    cout << "Masukkan nama file input: "; cin >> inFile;
    cout << "Masukkan besar pergesearannya: "; cin >> geser;
    enkripsi (inFile, geser);
}