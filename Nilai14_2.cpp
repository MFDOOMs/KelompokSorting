#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

struct waktu{
    int jam;
    int menit;
    int detik;
};

struct mahasiswa{
    string npm;
    string nama;
    float nilaiPenguji1;
    float nilaiPenguji2;
    float nilaiPenguji3;
    waktu mulai;
    waktu selesai;
};


typedef mahasiswa larikMahasiswa[10];
larikMahasiswa mhs;


void banyak(int & n){
    cout << "Banyak Data: ";
    cin >> n;
}

void inputWaktu(waktu& waktuMhs){    
    while (true) {
        cout << "Jam: ";
        cin >> waktuMhs.jam;
        if (waktuMhs.jam < 0 || waktuMhs.jam > 23) 
            cout << "Input tidak valid, coba lagi.\n";
        else 
            break;
    }
    
    while (true) {
        cout << "Menit: ";
        cin >> waktuMhs.menit;
        if (waktuMhs.menit > 60 || waktuMhs.menit < 0)
            cout << "Input tidak valid, coba lagi.\n";
        else 
            break;
    }

    while (true) {
        cout << "Detik: ";
        cin >> waktuMhs.detik;
        if (waktuMhs.detik > 60 || waktuMhs.detik < 0)
            cout << "Input tidak valid, coba lagi.\n";
        else 
            break;
    }
}

void inputData(larikMahasiswa& mhs,int n){
    for (int i = 0; i < n; i++)
    {
        cout << "\nData Mahasiswa ke-" << i+1 << " : " << endl;
        cout << "NPM  : "; cin >> mhs[i].npm;
        cout << "Nama : "; getline(cin >> ws,mhs[i].nama);

        do {
            cout << "Nilai Penguji 1 : ";
            cin >> mhs[i].nilaiPenguji1;
        } while (mhs[i].nilaiPenguji1 < 0 || mhs[i].nilaiPenguji1 > 100);

        do {
            cout << "Nilai Penguji 2 : ";
            cin >> mhs[i].nilaiPenguji2;
        } while (mhs[i].nilaiPenguji2 < 0 || mhs[i].nilaiPenguji2 > 100);

        do {
            cout << "Nilai Penguji 3 : ";
            cin >> mhs[i].nilaiPenguji3;
        } while (mhs[i].nilaiPenguji3 < 0 || mhs[i].nilaiPenguji3 > 100);

        cout << "\nWaktu mulai\n";
        inputWaktu(mhs[i].mulai);

        cout << "\nWaktu selesai\n";
        inputWaktu(mhs[i].selesai);
    }
}

float nilaiAkhir(mahasiswa mhs){
    return (mhs.nilaiPenguji1 + mhs.nilaiPenguji2 + mhs.nilaiPenguji3)/3;
}

float rataRataNilaiAkhir(larikMahasiswa mhs, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += nilaiAkhir(mhs[i]);
    }
    return total / n;
}

float NilaiTinggi(larikMahasiswa mhs,int n){
    float NilaiMax = nilaiAkhir(mhs[0]);
    for (int i = 1; i < n; i++)
    {
        float Nakhir = nilaiAkhir(mhs[i]);
        if(NilaiMax < Nakhir){
            NilaiMax = Nakhir;
        }
    }
    return NilaiMax;
}

float NilaiRendah(larikMahasiswa mhs,int n){
    float NilaiMin = nilaiAkhir(mhs[0]);
    for (int i = 1; i < n; i++)
    {
        float Nakhir = nilaiAkhir(mhs[i]);
        if(NilaiMin > Nakhir){
            NilaiMin = Nakhir;
        }
    }
    return NilaiMin;
}

char HurufMutu(float Nilai){
    char Mutu;
    if (Nilai >= 0 && Nilai < 55){
        Mutu = 'D';
    }
    else if (Nilai >= 55 && Nilai < 68){
        Mutu = 'C';
    }
    else if (Nilai >= 68 && Nilai < 80){
        Mutu = 'B';
    }
    else if (Nilai >= 80 && Nilai <= 100){
        Mutu = 'A';
    }
    return Mutu;
}

int detik(waktu x){
    return (x.jam * 3600 + x.menit * 60 + x.detik);
}

void hitungWaktu(mahasiswa mhs, waktu& lama) {
    int hasil = 0;

    if (detik(mhs.selesai) < detik(mhs.mulai)) {
        hasil = detik(mhs.selesai) + 24 * 3600 - detik(mhs.mulai);
    }
    else hasil = detik(mhs.selesai) - detik(mhs.mulai);
    
    lama.jam = hasil / 3600;
    lama.menit = (hasil % 3600) / 60;
    lama.detik = (hasil % 3600) % 60;
}

string statusMhs (float Nilai){
    if (Nilai >= 68 && Nilai <= 100) {
        return "Lulus";
    } else {
        return "Gagal";
    }
}

void output(larikMahasiswa mhs, int n){
    cout << "Daftar Nilai Sidang Program Studi TI" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "No" << setw(10) 
    << "NPM" << setw(13) 
    << "Nama" << setw(10)
    << "Nilai 1"<< setw(10)
    << "Nilai 2" << setw(10)
    << "Nilai 3" << setw(15)
    << "Nilai Akhir" << setw(15)
    << "Huruf Mutu" << setw(19)
    << "Waktu Mulai" << setw(19)
    << "Waktu Selesai" << setw(19)
    << "Lama Sidang" << setw(10)
    << "Status" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        waktu lamaSidang;
        hitungWaktu(mhs[i], lamaSidang);

        float nilaiAkhir1 = nilaiAkhir(mhs[i]);
        char Mutu = HurufMutu(nilaiAkhir1);
        string Stat = statusMhs(nilaiAkhir1);

        cout << i + 1 << setw(11)
        << mhs[i].npm << setw(13)
        << mhs[i].nama << setw(10)
        << mhs[i].nilaiPenguji1 << setw(10)
        << mhs[i].nilaiPenguji2 << setw(10)
        << mhs[i].nilaiPenguji3 << setw(15)
        << nilaiAkhir1 << setw(15)
        << Mutu << setw(15)
        << mhs[i].mulai.jam << ":" << mhs[i].mulai.menit << ":" << mhs[i].mulai.detik << setw(15)
        << mhs[i].selesai.jam << ":" << mhs[i].selesai.menit << ":" << mhs[i].selesai.detik << setw(15)
        << lamaSidang.jam << ":" << lamaSidang.menit << ":" << lamaSidang.detik << setw(10)
        << Stat << endl;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------\n";
    
}

int main(int argc, char const *argv[])
{
    larikMahasiswa mhs;
    int n;
    banyak(n);

    inputData(mhs,n);

    output(mhs,n);
    cout << "Rata-rata : " << rataRataNilaiAkhir(mhs,n) << endl;
    cout << "Nilai Tertinggi : " << NilaiTinggi(mhs,n) << endl;
    cout << "Nilai Terendah  : " << NilaiRendah(mhs,n) << endl;
    
    return 0;
}
