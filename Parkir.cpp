#include <iostream>
#include <cctype>
using namespace std;

struct waktu{
    int jam;
    int menit;
    int detik;
};

struct Kendaraan{
    char jenis;
    int biaya;
    string tipe;
    waktu lama;
};

struct Lamaparkir{
    waktu masuk;
    waktu keluar;
};


void InputJenis(Kendaraan& Nama1){
{
    while (true) {
        cout << "Jenis Kendaraan yang digunakan (A untuk Mobil dan B untuk Motor): ";
        cin >> Nama1.jenis;
        Nama1.jenis = tolower(Nama1.jenis);

        if (Nama1.jenis == 'a') {
            Nama1.tipe = "Mobil";
            break;

        } else if (Nama1.jenis == 'b') {
            Nama1.tipe = "Motor";
            break;

        } else {
            cout << "Input tidak valid. Harap masukkan 'A' atau 'B'.\n";
        }
    }
}

}
void InputWaktu(Lamaparkir& DataM,Kendaraan& Nama){
    cout<<"Masukan waktu masuk: "<<endl;
    while (true){
        cout<<"Jam: ";
        cin>>DataM.masuk.jam;
        if (DataM.masuk.jam < 0 || DataM.masuk.jam > 23){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }
    
    while (true){
        cout<<"Menit: ";
        cin>>DataM.masuk.menit;
        if (DataM.masuk.menit > 60 || DataM.masuk.menit < 0){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else{
            break;
        }
    }

    while (true){
        cout<<"Detik: ";
        cin>>DataM.masuk.detik;
        if (DataM.masuk.detik < 0 || DataM.masuk.detik > 60){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }
    
    cout<<"Masukan waktu keluar: "<<endl;
    while (true){
        cout<<"Jam: ";
        cin>>DataM.keluar.jam;
        if (DataM.keluar.jam < 0 || DataM.keluar.jam > 23){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }
    while (true){
        cout<<"Menit: ";
        cin>>DataM.keluar.menit;
        if (DataM.keluar.menit > 60 || DataM.keluar.menit < 0){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else{
            break;
        }
    }

    while (true){
        cout<<"Detik: ";
        cin>>DataM.keluar.detik;
        if (DataM.keluar.detik < 0 || DataM.keluar.detik > 60){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }
}

void HitungLama (Lamaparkir DataM,Kendaraan& Nama){
if(DataM.masuk.detik>DataM.keluar.detik){
    DataM.keluar.detik+=60;
    DataM.keluar.menit-=1;
}
Nama.lama.detik=DataM.keluar.detik-DataM.masuk.detik;

    if(DataM.masuk.menit>DataM.keluar.menit){
        DataM.keluar.menit+=60;
        DataM.keluar.jam-=1;
        
    }
    Nama.lama.menit=DataM.keluar.menit-DataM.masuk.menit;
    if (DataM.masuk.jam >DataM.keluar.jam)
    {
        DataM.keluar.jam=DataM.keluar.jam+24;
        
    }
 Nama.lama.jam = DataM.keluar.jam-DataM.masuk.jam;
    
}

void HitungBayar(Lamaparkir DataM,Kendaraan& Nama){
    int Bmobil=3000;
    int Bmotor=2000;
    Nama.biaya=0;
    int totalJam = Nama.lama.jam + (Nama.lama.menit > 0 ? 1 : 0);
    if (Nama.jenis == 'a') {
        Nama.biaya = totalJam * Bmobil;
    } else if (Nama.jenis == 'b') {
        Nama.biaya = totalJam * Bmotor;
    }
}

void print(Kendaraan Nama){
    cout<<"Jenis Kendaraan : "<<Nama.tipe<<endl;
    cout<<"Lama parkir : "<<Nama.lama.jam<<" jam "<<Nama.lama.menit<<" menit "<<Nama.lama.detik<<" detik"<<endl;
    cout<<"Biaya yang harus dibayarkan :"<<Nama.biaya<<" rp"<<endl;
}

int main(int argc, char const *argv[])
{
    waktu pukul;
    Kendaraan Kdrn;
    Lamaparkir Lparkir;
    InputJenis(Kdrn);
    InputWaktu(Lparkir,Kdrn);
    HitungLama(Lparkir,Kdrn);
    HitungBayar(Lparkir,Kdrn);
    print(Kdrn);

    return 0;
}
