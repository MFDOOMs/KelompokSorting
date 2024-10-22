/*
Nama         : Fardan Fadhilah Andicha Putra
NPM          : 140810240084
Bagian       : Bubble sort cara ke-1 dan shell sort
Tanggal Buat : 21 Oktober 2024
Deskripsi    : 

Nama         : Tristan Bonardo Silalahi
NPM          : 140810240058
Bagian       : Bubble sort cara ke-2 dan selection sort
Tanggal Buat : 21 Oktober 2024
Deskripsi    : Menyorting angka secara ascending dan descending dengan menggunakan bubble sort cara ke-2 dan selection sort 

Nama         : Noell Valentino Timothy
NPM          : 140810240064
Bagian       : Bubble sort cara ke-3 dan insertion sort
Tanggal Buat : 21 Oktober 2024
Deskripsi    : 
*/

#include <iostream>
using namespace std;

// Deklarasi array dengan alias
typedef int larik[30];


// Deklarasi Fungsi
int inputBanyakData(int banyakData);
void inputData(int& banyakData, larik kumpulanData);
void menu(int banyakData, larik kumpulanData);
void tukar(int& x, int& y);
void cetakLarik(larik kumpulanData, int n);

void bubble1Asc(int banyakData, larik kumpulanData);
void bubble1Des(int banyakData, larik kumpulanData);
void bubble2Asc(int banyakData, larik kumpulanData);
void bubble2Des(int banyakData, larik kumpulanData);
void bubble3Asc(int banyakData, larik kumpulanData);
void bubble3Des(int banyakData, larik kumpulanData);

void insertionAsc(int banyakData, larik kumpulanData);
void insertionDes(int banyakData, larik kumpulanData);

void selectionAsc(int banyakData, larik kumpulanData);
void selectionDes(int banyakData, larik kumpulanData);

void shellAsc(int banyakData, larik kumpulanData);
void shellDes(int banyakData, larik kumpulanData);


// Utama
int main()
{
    int banyakData = inputBanyakData(banyakData);

    larik kumpulanData;
    inputData(banyakData, kumpulanData);

    menu(banyakData, kumpulanData);
    return 0;
}


// Pendefinisian Fungsi
void inputData(int& banyakData, larik kumpulanData) {
    cout << "Masukkan " << banyakData << " jumlah data untuk disortir\t: \n";
    for (int i = 0; i < banyakData; i++)
    {
        cin >> kumpulanData[i];
    }
}


int inputBanyakData(int banyakData) {
    cout << "Masukkan banyak data yang ingin diolah\t: ";
    cin >> banyakData;
    return banyakData;
}


void menu(int banyakData, larik kumpulanData) {
    int urutan = 0, algoritma = 0;
    string lanjut = "";

    cout << "\nPilih bagaimana urutan data akan disortir : \n";
    cout << "1. Ascending   (dari paling kecil) \n";
    cout << "2. Descending  (dari paling besar) \n";
    do {
    cout << "Masukkan pilihan (1 - 2) : ";
    cin >> urutan;
    } while (urutan < 1 || urutan > 2);

    cout << "\nPilih algoritma sorting yang akan digunakan : \n";
    cout << "1. Bubble Sort (Cara 1)    \n";
    cout << "2. Bubble Sort (Cara 2)    \n";
    cout << "3. Bubble Sort (Cara 3)    \n";
    cout << "4. Selection Sort          \n";
    cout << "5. Insertion Sort          \n";
    cout << "6. Shell Sort              \n";
    do {
    cout << "Masukkan pilihan (1 - 2) : ";
    cin >> algoritma;
    } while (algoritma < 1 || algoritma > 6);


    switch (urutan)
    {
    case 1:
        switch (algoritma) {
        case 1 : bubble1Asc(banyakData, kumpulanData); break;
        case 2 : bubble2Asc(banyakData, kumpulanData); break;
        case 3 : bubble3Asc(banyakData, kumpulanData); break;
        case 4 : selectionAsc(banyakData, kumpulanData); break;
        case 5 : insertionAsc(banyakData, kumpulanData); break;
        case 6 : shellAsc(banyakData, kumpulanData); break;
        default: break;
        }
        break;

    case 2:
        switch (algoritma) {
        case 1 : bubble1Des(banyakData, kumpulanData); break;
        case 2 : bubble2Des(banyakData, kumpulanData); break;
        case 3 : bubble3Des(banyakData, kumpulanData); break;
        case 4 : selectionDes(banyakData, kumpulanData); break;
        case 5 : insertionDes(banyakData, kumpulanData); break;
        case 6 : shellDes(banyakData, kumpulanData); break;
        default: break;
        }
        break;
    }

    do {
        cout << "Apakah anda ingin mengurutkan data lagi? (Ya/Tidak) \n";
        cin >> lanjut;
    } while (lanjut != "Ya" && lanjut != "ya" && lanjut != "Tidak" && lanjut != "tidak");
    if (lanjut == "Ya" || lanjut == "ya")
        main();
}

void tukar(int& x, int& y) {
    int temp = y;
    y = x;
    x = temp;
}

void cetakLarik(larik kumpulanData, int n) {
    for (int i = 0; i < n; i++)
        cout << kumpulanData[i] << " ";
    cout << endl;
}

void bubble1Asc(int banyakData, larik kumpulanData) {
    int proses = 1;
    for (int i = 0; i < banyakData; i++) {
        for (int j = 0; j < banyakData - 1; j++) {
            if (kumpulanData[j] > kumpulanData[j + 1]) {
                tukar(kumpulanData[j], kumpulanData[j + 1]);
                cout << "Proses ke-" << proses++ << " : ";
                cetakLarik(kumpulanData, banyakData);
            }
        }
    }
}

void bubble1Des(int banyakData, larik kumpulanData) {
    int proses = 1;
    for (int i = 0; i < banyakData; i++) {
        for (int j = 0; j < banyakData - 1; j++) {
            if (kumpulanData[j] < kumpulanData[j + 1 ]) {
                tukar(kumpulanData[j], kumpulanData[j + 1]);
                cout << "Proses ke-" << proses++ << " : ";
                cetakLarik(kumpulanData, banyakData);
            }
        }
    }
}

void bubble2Asc(int banyakData, larik kumpulanData) {
    int proses = 1;
    for(int i = 0; i < banyakData - 1; i++) {
        for(int j = banyakData - 1; j > i; j--){
            if(kumpulanData[j] < kumpulanData[j - 1]){
                tukar(kumpulanData[j], kumpulanData[j - 1]);
                cout << "Proses ke-" << proses++ << " : ";
                cetakLarik(kumpulanData, banyakData);
            }
        }
    }
}

void bubble2Des(int banyakData, larik kumpulanData) {
    int proses = 1;
    for(int i = 0; i < banyakData - 1; i++){
        for(int j = banyakData - 1; j > i; j--){
            if(kumpulanData[j] > kumpulanData[j - 1]){
                tukar(kumpulanData[j], kumpulanData[j - 1]);
                cout << "Proses ke-" << proses++ << " : ";
                cetakLarik(kumpulanData, banyakData);
            }
        }
    }
}

void bubble3Asc(int banyakData, larik kumpulanData) {
    for (int i = 0; i < banyakData; i++) {
        cout << "Proses ke-" << i + 1 << " : ";
        for (int j = i + 1; j < banyakData; j++)
            if (kumpulanData[i] > kumpulanData[j]) tukar(kumpulanData[i], kumpulanData[j]);
        cetakLarik(kumpulanData, banyakData);
    }
}

void bubble3Des(int banyakData, larik kumpulanData) {
    for (int i = 0; i < banyakData; i++) {
        cout << "Proses ke-" << i + 1 << " : ";
        for (int j = i + 1; j < banyakData; j++)
            if (kumpulanData[i] < kumpulanData[j]) tukar(kumpulanData[i], kumpulanData[j]);
        cetakLarik(kumpulanData, banyakData);
    }
}

void insertionAsc(int banyakData, larik kumpulanData) {
    for (int i = 1; i < banyakData; i++) {
        cout << "Proses ke-" << i + 1 << " : ";
        for (int j = i - 1; j >= 0; j--) {
            if (kumpulanData[j] > kumpulanData[j + 1])
                tukar(kumpulanData[j], kumpulanData[j + 1]);
        }
        cetakLarik(kumpulanData, banyakData);
    }
}

void insertionDes(int banyakData, larik kumpulanData) {
    for (int i = 1; i < banyakData; i++) {
        cout << "Proses ke-" << i + 1 << " : ";
        for (int j = i - 1; j >= 0; j--) {
            if (kumpulanData[j] < kumpulanData[j + 1])
                tukar(kumpulanData[j], kumpulanData[j + 1]);
        }
        cetakLarik(kumpulanData, banyakData);
    }
}

void selectionAsc(int banyakData, larik kumpulanData) {
    int posisi = 0;
    for(int i = 0; i < banyakData - 1; i++){
        cout << "Proses ke-" << i + 1 << " : ";
        posisi = i;
        for(int j = i + 1; j < banyakData; j++){
            if(kumpulanData[posisi] > kumpulanData[j]){
                posisi = j;
            }
        }
        tukar(kumpulanData[i], kumpulanData[posisi]);
        cetakLarik(kumpulanData, banyakData);
    }
}

void selectionDes(int banyakData, larik kumpulanData) {
    int posisi = 0;
    for(int i = 0; i < banyakData - 1; i++){
        cout << "Proses ke-" << i + 1 << " : ";
        posisi = i;
        for(int j = i + 1; j < banyakData; j++){
            if(kumpulanData[posisi] < kumpulanData[j]) {
                posisi = j;
            }
        }
        tukar(kumpulanData[i], kumpulanData[posisi]);
        cetakLarik(kumpulanData, banyakData);
    }
}

void shellAsc(int banyakData, larik kumpulanData) {
    int j = 0, proses = 1;
    for (int jarak = banyakData / 2; jarak > 0; jarak /= 2){
        for (int i = jarak; i < banyakData; i++){
            cout << "Proses ke-" << proses++ << " : ";
            int temp = kumpulanData[i];
            for (j = i; j >= jarak && temp < kumpulanData[j - jarak]; j -= jarak){
                kumpulanData[j] = kumpulanData[j - jarak];
            }
            kumpulanData[j] = temp;
            cetakLarik (kumpulanData, banyakData);
        }
    }
}

void shellDes(int banyakData, larik kumpulanData) {
    int j = 0, proses = 1;
    for (int jarak = banyakData / 2; jarak > 0; jarak /= 2){
        for (int i = jarak; i < banyakData; i++){
            cout << "Proses ke-" << proses++ << " : ";
            int temp = kumpulanData[i];
            for (j = i; j >= jarak && temp > kumpulanData[j - jarak]; j -= jarak){
                kumpulanData[j] = kumpulanData[j - jarak];
            }
            kumpulanData[j] = temp;
            cetakLarik (kumpulanData, banyakData);
        }
    }
}