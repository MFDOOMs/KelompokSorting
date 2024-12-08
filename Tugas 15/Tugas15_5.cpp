#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>

using namespace std;

struct mahasiswa{
    char npm[10];
    char nama[50];
    float NilaiPenguji1;
    float NilaiPenguji2;
    float NilaiPenguji3;
};

char hurufMutu(float Nilai){
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

bool statusMhs(float Nilai){
    if (Nilai >= 68 && Nilai <= 100) {
        return 1;
    } else {
        return 0;
    }

}

float countNilaiAkhir(int nilai1, int nilai2, int nilai3){
    float totalNilai = 0;
        totalNilai += nilai1+nilai2+nilai3;
    return(totalNilai)/3.0;
}

void cetakTabel(mahasiswa mhs){
    int i = 0;
    char mutu;
    float nilaiAkhir;
    bool status;
    ifstream fi;
    fi.open("Tugas5.dat", ios::binary);
    int j = 1;
    cout << "Daftar Nilai Sidang Program Studi TI" << endl;
    cout <<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout << "No" << setw(10) 
    << "NPM" << setw(13) 
    << "Nama" << setw(10)
    << "Nilai 1"<< setw(10)
    << "Nilai 2" << setw(10)
    << "Nilai 3" << setw(15)
    << "Nilai Akhir" << setw(15)
    << "Huruf Mutu" << setw(10)
    << "Status" << endl;
    while(fi.read((char *) &mhs, sizeof(mhs))){
        nilaiAkhir = countNilaiAkhir(mhs.NilaiPenguji1, mhs.NilaiPenguji2, mhs.NilaiPenguji3);
        mutu = hurufMutu (nilaiAkhir);
        status = statusMhs (nilaiAkhir);
        cout << j++ << setw(11)
        << mhs.npm << setw(13)
        << mhs.nama << setw(10)
        << mhs.NilaiPenguji1 << setw(10)
        << mhs.NilaiPenguji2 << setw(10)
        << mhs.NilaiPenguji3 << setw(15)
        << nilaiAkhir << setw(15)
        << mutu << setw(10);
        if (status){        
            cout << "Lulus";
        }
        else {
            cout << "Gagal";
        }
        cout << endl;
    }
    cout <<"--------------------------------------------------------------------------------------------------------"<<endl;
    fi.close();
}

float rataRata (mahasiswa mhs){
    float totalNilai;
    int i = 0;
    ifstream fi;
    fi.open ("Tugas5.dat", ios::binary);
    while(fi.read((char *) &mhs, sizeof(mhs))){
        totalNilai += countNilaiAkhir(mhs.NilaiPenguji1, mhs.NilaiPenguji2, mhs.NilaiPenguji3);
        i++;
    }
    return (totalNilai /= i);
}

float nilaiTinggi(mahasiswa mhs){
    float temp;
    float nilaiMaks = 0;
    ifstream fi;
    fi.open ("Tugas5.dat", ios::binary);
    while(fi.read((char *) &mhs, sizeof(mhs))){
        temp = countNilaiAkhir(mhs.NilaiPenguji1, mhs.NilaiPenguji2, mhs.NilaiPenguji3);
        if (temp > nilaiMaks){
            nilaiMaks = temp;
        }
    }
    return nilaiMaks;
}

float nilaiRendah(mahasiswa mhs){
    float temp;
    float nilaiMin = 100;
    ifstream fi;
    fi.open ("Tugas5.dat", ios::binary);
    while(fi.read((char *) &mhs, sizeof(mhs))){
        temp = countNilaiAkhir(mhs.NilaiPenguji1, mhs.NilaiPenguji2, mhs.NilaiPenguji3);
        if (temp < nilaiMin){
            nilaiMin = temp;
        }
    }
    return nilaiMin;
}

void outputAkhir(mahasiswa mhs) {
    int pilihan = 0;
    cout << "\nPilih output yang diinginkan:\n";
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
    case 1: cout << "\n"; cetakTabel(mhs); outputAkhir(mhs);
    case 2: cout << "\nRata-rata : " << rataRata(mhs) << "\n"; outputAkhir(mhs);
    case 3: cout << "\nNilai Tertinggi : " << nilaiTinggi(mhs) << "\n"; outputAkhir(mhs);
    case 4: cout << "\nNilai Terendah  : " << nilaiRendah(mhs) << "\n"; outputAkhir(mhs);
    case 5: exit(0);
    default: break;
    }    
}

int main(){
    ifstream fi;
    ofstream fo;
    mahasiswa mhs;
    int n;
    cout << "Masukkan jumlah mahasiswa: "; cin >> n;
    fo.open("Tugas5.dat", ios::binary | ios::app);
    for(int i = 0; i<n; i++){
        cout << "\nMahasiswa " << i+1;
        cout << "\nNIM: "; cin >> mhs.npm;
        cout << "Nama: "; cin >> mhs.nama;
        do {
            cout << "Nilai Penguji 1: ";
            cin >> mhs.NilaiPenguji1;
        } while (mhs.NilaiPenguji1 < 0 || mhs.NilaiPenguji1 > 100);
        do {
            cout << "Nilai Penguji 2: ";
            cin >> mhs.NilaiPenguji2;
        } while (mhs.NilaiPenguji2 < 0 || mhs.NilaiPenguji2 > 100);
        do {
            cout << "Nilai Penguji 3: ";
            cin >> mhs.NilaiPenguji3;
        } while (mhs.NilaiPenguji3 < 0 || mhs.NilaiPenguji3 > 100);;
        
        fo.write((char *) &mhs, sizeof(mhs));
    }
    fo.close();
    outputAkhir (mhs);
}