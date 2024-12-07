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

/*
Cek isi
buka(nama file)
int jKonsonan=0;
int JVokal=0;
cek jika bukan AaIiEeUuOo
jika bukan(jKonsonan++)
jika iya(jVokal++) 
*/