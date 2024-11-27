#include <iostream>
using namespace std;

struct waktu {
    int jam;
    int menit;
    int detik;
};


void inputWaktu(waktu& x);
int detik(waktu x);
void konversiWaktu(waktu mulai, waktu akhir, waktu& selisih);
void output (waktu mulai, waktu akhir, waktu selisih);


int main() {
    waktu mulai;
    waktu akhir;
    waktu selisih;

    cout << "Masukkan waktu awal  : \n"; inputWaktu(mulai);
    cout << "Masukkan waktu akhir : \n"; inputWaktu(akhir);
    konversiWaktu(mulai, akhir, selisih);
    output(mulai, akhir, selisih);
}


void inputWaktu(waktu& x){
    while (true) {
        cout << "Jam: ";
        cin >> x.jam;
        if (x.jam < 0 || x.jam > 23){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }
    
    while (true) {
        cout << "Menit: ";
        cin >> x.menit;
        if (x.menit > 60 || x.menit < 0){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Detik: ";
        cin >> x.detik;
        if (x.detik > 60 || x.detik < 0){
            cout << "Input tidak valid, coba lagi.\n";
        }
        else {
            break;
        }
    }
}

int detik(waktu x){
    return (x.jam * 3600 + x.menit * 60 + x.detik);
}

void konversiWaktu(waktu mulai, waktu akhir, waktu& selisih) {
    int hasil = 0;
    if (detik(akhir) < detik(mulai)) {
        hasil = detik(akhir) + 24 * 3600 - detik(mulai);
    }
    else hasil = detik(akhir) - detik(mulai);
    
    selisih.jam = hasil / 3600;
    selisih.menit = (hasil % 3600) / 60;
    selisih.detik = (hasil % 3600) % 60;
}

void output (waktu mulai, waktu akhir, waktu selisih) {
    cout << endl;
    cout << "Jam Datang \t= " << mulai.jam << " : " << mulai.menit << " : " << mulai.detik << endl;
    cout << "Jam Pulang \t= " << akhir.jam << " : " << akhir.menit << " : " << akhir.detik << endl;
    cout << "Lama parkir \t= "<< selisih.jam << " : " << selisih.menit << " : "<< selisih.detik << endl;
}