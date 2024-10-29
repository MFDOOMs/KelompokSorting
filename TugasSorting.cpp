/*
Nama         : Fardan Fadhilah Andicha Putra
NPM          : 140810240084
Bagian       : Bubble sort cara ke-1 dan shell sort
Tanggal Buat : 28 Oktober 2024
Deskripsi    : Menyorting angka secara ascending dan descending dengan menggunakan bubble sort cara ke-1 dan shell sort 

Nama         : Tristan Bonardo Silalahi
NPM          : 140810240058
Bagian       : Bubble sort cara ke-2 dan selection sort
Tanggal Buat : 28 Oktober 2024
Deskripsi    : Menyorting angka secara ascending dan descending dengan menggunakan bubble sort cara ke-2 dan selection sort 

Nama         : Noell Valentino Timothy
NPM          : 140810240064
Bagian       : Bubble sort cara ke-3 dan insertion sort
Tanggal Buat : 28 Oktober 2024
Deskripsi    : Menyorting angka secara ascending dan descending dengan menggunakan bubble sort cara ke-3 dan insertion sort 
*/


#include <iostream>
using namespace std;


// Deklarasi array dengan alias
typedef char larik[50];


// Deklarasi Fungsi
void inputBanyak(int& n);
void inputData(larik arr, int n);
void tukar(char& x, char& y);
void cetakLarik(larik arr, int n);
void bubbleSort1Asc(larik arr, int n);
void bubbleSort1Des(larik arr, int n);
void bubbleSort2Asc(larik arr, int n);
void bubbleSort2Des(larik arr, int n);
void bubbleSort3Asc (larik arr, int n);
void bubbleSort3Des (larik arr, int n);
void selectionAsc(larik arr, int n);
void selectionDes(larik arr, int n);
void insertionAsc(larik arr, int n);
void insertionDes(larik arr, int n);
void shellAsc (larik arr, int n);
void shellDes (larik arr, int n);
void menuSort();
void menuBawahAsc();
void menuBawahDes();
void linearSearch(larik arr, int n, char x);
void binarySearch(larik arr, int n, char x);
void menuUtama();
void menuSearch();


// Utama
int main()
{
    menuUtama();
    return 0;
}


// Pendefinisian Fungsi
void menuUtama() {
    bool MenuU = true;
    int pilihan;
    do
    {
        cout << "1. Sorting" << endl;
        cout << "2. Searching" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masukan Pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            menuSort();
            break;
        case 2:
            menuSearch();
            break;
        case 3:
            MenuU =false;
            break;
        default:
            cout<<"pilihan tidak valid";
            break;
        }
    } while (MenuU);
}

void menuSort(){
    bool menuA = true;
    int pilihan;
    do
    {
        cout<<"1. Mengurutkan secara ascending"<<endl;
        cout<<"2. Mengurutkan secara descending"<<endl;
        cout<<"3. Keluar"<<endl;
        cout<<" Masukan pilihan : ";cin>>pilihan;
        switch (pilihan)
        {
        case 1:
            menuBawahAsc();
            break;
        
        case 2:
            menuBawahDes();
            break;

        case 3:
            menuA = false;
            break;

        default:
        cout<<"pilihan tidak valid!"<<endl;
            break;
        }
    } while (menuA == true);
}

void menuSearch(){
    bool menuS;
    int pilihan;
    int n;
    larik arr;
    char x;
    do
    {
        cout<<"1. Linear search"<<endl;
        cout<<"2. Binary Search"<<endl;
        cout<<"3. Mundur"<<endl;
        cout<< "Masukkan pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            inputBanyak(n);
            inputData(arr,n);
            linearSearch(arr,n,x);
            break;
        case 2:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort1Asc(arr,n);
            binarySearch(arr,n,x);
            break;
        case 3:
            menuS = false;
            break;
        
        default:
            cout<<"Pilihan tidak valid"<<endl;
            break;
        }
    } while (menuS);
}

void menuBawahAsc(){
    bool menuBA = true;
    int pilihanA;
    int n;
    larik arr;
    do
    {
        cout<<"1. Bubble Sort cara 1"<<endl;
        cout<<"2. Bubble Sort cara 2"<<endl;
        cout<<"3. Bubble Sort cara 3"<<endl;
        cout<<"4. Selection Sort"<<endl;
        cout<<"5. Insertion Sort"<<endl;
        cout<<"6. Shell Sort"<<endl;
        cout<<"7. Mundur"<<endl;
        cout<<"Masukan pilihan : ";cin>>pilihanA;
        cout<<endl;
        switch (pilihanA)
        {
        case 1:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort1Asc(arr,n);
            cout<<endl;
            break;
        case 2:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort2Asc(arr,n);
            cout<<endl;
            break;
        case 3:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort3Asc(arr,n);
            cout<<endl;
            break;
        case 4:
            inputBanyak(n);
            inputData(arr,n);
            selectionAsc(arr,n);
            cout<<endl;
            break;
        case 5:
            inputBanyak(n);
            inputData(arr,n);
            insertionAsc(arr,n);
            cout<<endl;
            break;
        case 6:
            inputBanyak(n);
            inputData(arr,n);
            shellAsc(arr,n);
            cout<<endl;
            break;
        case 7:
            menuBA = false;
            break;
        default:
        cout<<"input tidak valid !"<<endl;
            break;
        }
    } while (menuBA == true);   
}

void menuBawahDes(){
    bool menuBD = true;
    int pilihanD;
    int n;
    larik arr;
    do
    {
        cout<<"1. Bubble Sort cara 1"<<endl;
        cout<<"2. Bubble Sort cara 2"<<endl;
        cout<<"3. Bubble Sort cara 3"<<endl;
        cout<<"4. Selection Sort"<<endl;
        cout<<"5. Insertion Sort"<<endl;
        cout<<"6. Shell Sort"<<endl;
        cout<<"7. Mundur"<<endl;
        cout<<"Masukan pilihan : ";cin>>pilihanD;
        cout<<endl;
        switch (pilihanD)
        {
        case 1:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort1Des(arr,n);
            cout<<endl;
            break;
        case 2:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort2Des(arr,n);
            cout<<endl;
            break;
        case 3:
            inputBanyak(n);
            inputData(arr,n);
            bubbleSort3Des(arr,n);
            cout<<endl;
            break;
        case 4:
            inputBanyak(n);
            inputData(arr,n);
            selectionDes(arr,n);
            cout<<endl;
            break;
        case 5:
            inputBanyak(n);
            inputData(arr,n);
            insertionDes(arr,n);
            cout<<endl;
            break;
        case 6:
            inputBanyak(n);
            inputData(arr,n);
            shellDes(arr,n);
            cout<<endl;
            break;
            case 7:
            menuBD = false;
            break;
        default:
        cout<<"input tidak valid !"<<endl;
            break;
        }
    } while (menuBD == true);
}

void inputBanyak(int& n){
    cout << "Masukan banyak angka : ";
    cin >> n;
}

void inputData(larik arr,int n){
    cout << "Masukan angka sebanyak " << n << " : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void tukar (char& x, char& y){
    char temp = x;
    x = y;
    y = temp;
}

void cetakLarik(larik arr, int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort1Asc(larik arr, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j] > arr[j+1]){
                tukar(arr[j],arr[j+1]);
                cetakLarik (arr, n);
                cout << endl;
            }
        }
    }
    cout<<"Data terurut : "<<endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void bubbleSort1Des(larik arr, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j] < arr[j+1]){
                tukar(arr[j],arr[j+1]);
                cetakLarik (arr, n);
                cout << endl;
            }
        }
    }
    cout<<"Data terurut : "<<endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void bubbleSort2Asc(larik arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                tukar(arr[j],arr[j-1]);
                cetakLarik(arr,n);
                cout<<endl;
            }
        }
    }
    cout<<"Data terurut : "<<endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void bubbleSort2Des(larik arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]>arr[j-1]){
                tukar(arr[j],arr[j-1]);
                cetakLarik(arr,n);
                cout<<endl;
            }
        }
    }
    cout<<"Data terurut : "<<endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void bubbleSort3Des (larik arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j]){ 
            tukar(arr[i], arr[j]);
            cetakLarik(arr, n);
            cout<<endl;
            }
    }
    cout<<"Data terurut : "<<endl;
    cetakLarik(arr,n);
}

void bubbleSort3Asc (larik arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]){
            tukar(arr[i], arr[j]);
            cetakLarik(arr, n);
            cout<<endl;
            }
    }
    cout<<"Data terurut : "<<endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void selectionAsc(larik arr, int n) {
    int posisi;
    bool benar;

    for (int i = 0; i < n - 1; i++) {
        posisi = i;
        benar = false;

        for (int j = i + 1; j < n; j++) {
            if (arr[posisi] > arr[j]) {
                posisi = j;
            }
        }

        if (posisi != i) {
            tukar(arr[i], arr[posisi]);
            benar = true;
            cetakLarik(arr, n);
            cout<<endl;
        }

        if (!benar) {
            break;
        }
    }
    cout << "Data terurut : " << endl;
    cetakLarik(arr,n);
    cout<<endl;
}


void selectionDes(larik arr, int n) {
    int posisi;
    bool benar;

    for (int i = 0; i < n - 1; i++) {
        posisi = i;
        benar = false;

        for (int j = i + 1; j < n; j++) {
            if (arr[posisi] < arr[j]) {
                posisi = j;
            }
        }

        if (posisi != i) {
            tukar(arr[i], arr[posisi]);
            benar = true;
            cetakLarik(arr, n);
            cout<<endl;
        }

        if (!benar) {
            break;
        }
    }
    cout << "Data terurut : " << endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void insertionAsc(larik arr, int n) {
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j + 1]) {
                tukar(arr[j], arr[j + 1]);
            }
        }
        cetakLarik(arr, n);
        cout<<endl;
    }
    cout << "Data terurut : " << endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void insertionDes(larik arr, int n) {
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[j + 1]) {
                tukar(arr[j], arr[j + 1]);
            }
        }
        cetakLarik(arr, n);
        cout<<endl;
    }
    cout << "Data terurut : " << endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void shellAsc (larik arr, int n){
    int j;
    for (int jarak=n/2; jarak>0; jarak/=2){
        for (int i=jarak; i<n; i++){
            int temp = arr[i];
            for (j=i; j>=jarak && temp < arr[j-jarak]; j-=jarak){
                arr[j] = arr[j-jarak];
            }
            arr[j]=temp;
            cetakLarik (arr,n);
            cout << "\n";
        }
    }
    cout << "Data terurut : " << endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void shellDes (larik arr, int n){
    int j;
    for (int jarak=n/2; jarak>0; jarak/=2){
        for (int i=jarak; i<n; i++){
            int temp = arr[i];
            for (j=i; j>=jarak && temp > arr[j-jarak]; j-=jarak){
                arr[j] = arr[j-jarak];
            }
            arr[j]=temp;
            cetakLarik (arr,n);
            cout << "\n";
        }
    }
    cout << "Data terurut : " << endl;
    cetakLarik(arr,n);
    cout<<endl;
}

void linearSearch(larik arr, int n, char x) {
    cout << "Masukkan angka yang ingin dicari : ";
    cin >> x;
    bool found = false; 
    for (int i=0; i<n; i++){
        if (arr[i] == x){
        cout << "Angka ditemukan di index : " << i << endl;
        found = true;
        break;
        }
    }
    if (!found){
        cout << "Angka tidak ditemukan." << endl;
    }
}

void binarySearch(larik arr, int n, char x) {
    cout << "Masukkan angka yang ingin dicari : ";
    cin >> x;
    bool found = false; 

    int bawah = 0;
    int atas = n - 1;

    while (bawah <= atas){
        int tengah = bawah + (atas - bawah) / 2;

        if (arr[tengah] == x) {
            cout << "Angka ditemukan di index : " << tengah << endl;
            found = true;
            break;
        }

        else if (arr[tengah] > x) {
            atas = tengah - 1;
            continue;
        }
        else if (arr[tengah] < x) {
            bawah = tengah + 1;
            continue;
        }
    }

    if (!found){
        cout << "Angka tidak ditemukan." << endl;
    }
}