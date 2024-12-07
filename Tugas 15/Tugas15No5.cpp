/*
Nama         : Fardan Fadhilah Andicha Putra
NPM          : 140810240084
Bagian       : Membuat menu program 1, merapikan output dan membuat laporan
Tanggal Buat : 5 Desember 2024
Deskripsi    : Membuat menu program daftar nilai mahasiswa tanpa waktu ujian, Merapikan output yang dihasilkan dari penyimpanan data-data mahasiswa dan membuat laporannya.

Nama         : Tristan Bonardo Silalahi
NPM          : 140810240058
Bagian       : Daftar nilai mahasiswa tanpa ada waktu ujian
Tanggal Buat : 5 Desember 2024
Deskripsi    : Menyimpan data mahasiswa dengan menggunakan array of data (struct)

Nama         : Noell Valentino Timothy
NPM          : 140810240064
Bagian       : Daftar nilai mahasiswa dengan waktu ujian
Tanggal Buat : 5 Desember 2024
Deskripsi    : Menyimpan data mahasiswa dengan menggunakan array of data (struct), ditambah dengan waktu ujian mahasiswa dan menunya.
*/

#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct Mahasiswa{
    string npm;
    string nama;
    float NilaiPenguji1;
    float NilaiPenguji2;
    float NilaiPenguji3;
};

typedef Mahasiswa larikMahasiswa[10];
larikMahasiswa mhs;

void Banyak(int & n){
    cout<<"Banyak Data: ";cin>>n;
}

void inputData(string nFile, larikMahasiswa& mhs,int n){
    ofstream fo;
    fo.open(nFile, ios::binary | ios::app);
    for (int i = 0; i < n; i++)
    {
        cout<<"\nData Mahasiswa ke-"<<i+1<<": "<<endl;
        cout<<"NPM: ";cin>>mhs[i].npm;
        cout<<"Nama: ";cin.ignore();getline(cin,mhs[i].nama);
        do {
            cout << "Nilai Penguji 1: ";
            cin >> mhs[i].NilaiPenguji1;
        } while (mhs[i].NilaiPenguji1 < 0 || mhs[i].NilaiPenguji1 > 100);
        do {
            cout << "Nilai Penguji 2: ";
            cin >> mhs[i].NilaiPenguji2;
        } while (mhs[i].NilaiPenguji2 < 0 || mhs[i].NilaiPenguji2 > 100);
        do {
            cout << "Nilai Penguji 3: ";
            cin >> mhs[i].NilaiPenguji3;
        } while (mhs[i].NilaiPenguji3 < 0 || mhs[i].NilaiPenguji3 > 100);
        fo.write((char *) &mhs[i], sizeof(mhs[i]));
    }
    
}

float NilaiAkhir(Mahasiswa mhs){
    return(mhs.NilaiPenguji1+mhs.NilaiPenguji2+mhs.NilaiPenguji3)/3.0;
}

float rataRataNilaiAkhir(larikMahasiswa mhs, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += NilaiAkhir(mhs[i]);
    }
    return total / n;
}

float NilaiTinggi(larikMahasiswa mhs,int n){
    float NilaiMax=NilaiAkhir(mhs[0]);
    for (int i = 1; i < n; i++)
    {
        float Nakhir=NilaiAkhir(mhs[i]);
        if(NilaiMax<Nakhir){
            NilaiMax=Nakhir;
        }
    }
    return NilaiMax;
}

float NilaiRendah(larikMahasiswa mhs,int n){
    float NilaiMin=NilaiAkhir(mhs[0]);
    for (int i = 1; i < n; i++)
    {
        float Nakhir=NilaiAkhir(mhs[i]);
        if(NilaiMin>Nakhir){
            NilaiMin=Nakhir;
        }
    }
    return NilaiMin;
}

char HurufMutu(float Nilai){
    char Mutu;
    if(Nilai>=0&&Nilai<55){
        Mutu='D';
    }
    else if(Nilai>=55&&Nilai<68){
        Mutu='C';
    }
    else if(Nilai>=68&&Nilai<80){
        Mutu='B';
    }
    else if(Nilai>=80&&Nilai<=100){
        Mutu='A';
    }
    return Mutu;
}

string statusMhs(float Nilai){
    if (Nilai >= 68 && Nilai <= 100) {
        return "Lulus";
    } else {
        return "Gagal";
    }

}

string daftarTabel(larikMahasiswa mhs,int n){
    ostringstream output;
    output << "Daftar Nilai Sidang Program Studi TI" << endl;
    output <<"--------------------------------------------------------------------------------------------------------"<<endl;
    output << "No" << setw(10) 
    << "NPM" << setw(13) 
    << "Nama" <<setw(10)
    << "Nilai 1"<< setw(10)
    << "Nilai 2" << setw(10)
    << "Nilai 3" << setw(15)
    << "Nilai Akhir" << setw(15)
    << "Huruf Mutu" << setw(10)
    << "Status" << endl;
    output <<"--------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i <n; i++)
    {
        float NilaiAkhir1=NilaiAkhir(mhs[i]);
        char Mutu=HurufMutu(NilaiAkhir1);
        string Stat =statusMhs(NilaiAkhir1);
        output << i+1 << setw(11)
        << mhs[i].npm << setw(13)
        << mhs[i].nama << setw(10)
        << mhs[i].NilaiPenguji1 << setw(10)
        << mhs[i].NilaiPenguji2 << setw(10)
        << mhs[i].NilaiPenguji3 << setw(15)
        << NilaiAkhir1 << setw(15)
        << Mutu << setw(10)
        << Stat << endl;
    }
    output <<"--------------------------------------------------------------------------------------------------------"<<endl;
    return output.str(); 
}

void outputFile (string nFile, larikMahasiswa mhs, int n, float rata, float tinggi, float rendah){
    ifstream fi;
    Mahasiswa m;
    int i=0;
    fi.open (nFile, ios::binary);    
    while (fi.read((char *) &m, sizeof(m))){    
        mhs[i] = m;
        cout << daftarTabel(mhs, n) << endl;
        cout << "Rata-rata nilai: " << rata << endl;
        cout << "Nilai tertinggi: " << tinggi << endl;
        cout << "Nilai terendah: " << rendah;
        i++;
    }
    fi.close();

}

int main(int argc, char const *argv[])
{
    larikMahasiswa mhs;
    int n;
    string nFile;
    cout << "Masukkan nama file yang akan dioutput: "; cin >> nFile;
    Banyak(n);
    inputData(nFile, mhs, n);
    cout << endl;
    float rata=rataRataNilaiAkhir(mhs,n);
    float Tertinggi=NilaiTinggi(mhs,n);
    float Terendah=NilaiRendah(mhs,n);
    outputFile(nFile,mhs,n,rata,Tertinggi,Terendah);
    return 0;
}
