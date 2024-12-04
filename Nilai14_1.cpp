/*
Nama         : Fardan Fadhilah Andicha Putra
NPM          : 140810240084
Bagian       : Membuat menu program 1, merapikan output dan membuat laporan
Tanggal Buat : 3 Desember 2024
Deskripsi    : Membuat menu program daftar nilai mahasiswa tanpa waktu ujian, Merapikan output yang dihasilkan dari penyimpanan data-data mahasiswa dan membuat laporannya.

Nama         : Tristan Bonardo Silalahi
NPM          : 140810240058
Bagian       : Daftar nilai mahasiswa tanpa ada waktu ujian
Tanggal Buat : 3 Desember 2024
Deskripsi    : Menyimpan data mahasiswa dengan menggunakan array of data (struct)

Nama         : Noell Valentino Timothy
NPM          : 140810240064
Bagian       : Daftar nilai mahasiswa dengan waktu ujian
Tanggal Buat : 3 Desember 2024
Deskripsi    : Menyimpan data mahasiswa dengan menggunakan array of data (struct), ditambah dengan waktu ujian mahasiswa dan menunya.
*/

#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

struct waktu{
    int jam;
    int menit;
    int detik;
};

struct Mahasiswa{
    string npm;
    string nama;
    float NilaiPenguji1;
    float NilaiPenguji2;
    float NilaiPenguji3;
    waktu mulai;
    waktu selesai;
};

typedef Mahasiswa larikMahasiswa[10];
larikMahasiswa mhs;

void Banyak(int & n){
    cout<<"Banyak Data: ";cin>>n;
}

void inputData(larikMahasiswa& mhs,int n){
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

void daftarTabel(larikMahasiswa mhs,int n){
    cout<< "Daftar Nilai Sidang Program Studi TI" << endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout << "No" << setw(10) 
    << "NPM" << setw(13) 
    << "Nama" <<setw(10)
    << "Nilai 1"<< setw(10)
    << "Nilai 2" << setw(10)
    << "Nilai 3" << setw(15)
    << "Nilai Akhir" << setw(15)
    << "Huruf Mutu" << setw(10)
    << "Status" << endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i <n; i++)
    {
        float NilaiAkhir1=NilaiAkhir(mhs[i]);
        char Mutu=HurufMutu(NilaiAkhir1);
        string Stat =statusMhs(NilaiAkhir1);
        cout << i+1 << setw(11)
        << mhs[i].npm << setw(13)
        << mhs[i].nama << setw(10)
        << mhs[i].NilaiPenguji1 << setw(10)
        << mhs[i].NilaiPenguji2 << setw(10)
        << mhs[i].NilaiPenguji3 << setw(15)
        << NilaiAkhir1 << setw(15)
        << Mutu << setw(10)
        << Stat << endl;
    }
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
}

void outputAkhir(larikMahasiswa mhs, int n) {
    int pilihan = 0;
    cout << "Pilih output yang diinginkan: \n";
    cout << "1. Tabel\n";
    cout << "2. Rata-rata nilai\n";
    cout << "3. Nilai tertinggi\n";
    cout << "4. Nilai terendah\n";
    cout << "5. Keluar dari program\n";
    cout << "Masukkan pilihan: ";
    do {
        cin >> pilihan;
    } while (pilihan < 1 || pilihan > 5);

    switch (pilihan)
    {
    case 1: cout << "\n"; daftarTabel(mhs, n); outputAkhir(mhs, n);;
    case 2: cout << "\nRata-rata : " << rataRataNilaiAkhir(mhs,n) << "\n\n"; outputAkhir(mhs, n);;
    case 3: cout << "\nNilai Tertinggi : " << NilaiTinggi(mhs,n) << "\n\n"; outputAkhir(mhs, n);;
    case 4: cout << "\nNilai Terendah  : " << NilaiRendah(mhs,n) << "\n\n"; outputAkhir(mhs, n);;
    case 5: exit(0);
    default: break;
    }    
}

int main(int argc, char const *argv[])
{
    larikMahasiswa mhs;
    int n;
    Banyak(n);
    inputData(mhs,n);
    cout << endl;
    float rata=rataRataNilaiAkhir(mhs,n);
    float Tertinggi=NilaiTinggi(mhs,n);
    float Terendah=NilaiRendah(mhs,n);
    outputAkhir(mhs,n);
    cout<<"Rata-rata: "<<rata<<endl;
    cout<<"Nilai Tertinggi: "<<Tertinggi<<endl;
    cout<<"Nilai Terendah: "<<Terendah<<endl;
    
    return 0;
}
