#include <iostream>
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
    cout<<"Banyak Data : ";cin>>n;
}

void inputData(larikMahasiswa& mhs,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<"Data Mahasiswa ke-"<<i+1<<" : "<<endl;
        cout<<"NPM : ";cin>>mhs[i].npm;
        cout<<"Nama : ";cin.ignore();getline(cin,mhs[i].nama);
        do {
            cout << "Nilai Penguji 1 : ";
            cin >> mhs[i].NilaiPenguji1;
        } while (mhs[i].NilaiPenguji1 < 0 || mhs[i].NilaiPenguji1 > 100);
        do {
            cout << "Nilai Penguji 2 : ";
            cin >> mhs[i].NilaiPenguji2;
        } while (mhs[i].NilaiPenguji2 < 0 || mhs[i].NilaiPenguji2 > 100);
        do {
            cout << "Nilai Penguji 3 : ";
            cin >> mhs[i].NilaiPenguji3;
        } while (mhs[i].NilaiPenguji3 < 0 || mhs[i].NilaiPenguji3 > 100);
    }
    
}

float NilaiAkhir(Mahasiswa mhs){
    return(mhs.NilaiPenguji1+mhs.NilaiPenguji2+mhs.NilaiPenguji3)/3.0;
}

float rataRataNilaiAkhir(larikMahasiswa& mhs, int n) {
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

void output(larikMahasiswa mhs,int n){
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"No\t\tNPM\t\tNama\t\tNilai 1\t\tNilai 2\t\t Nilai 3\t\t Nilai Akhir\t\tHuruf Mutu\t\tStatus"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i <n; i++)
    {
        float NilaiAkhir1=NilaiAkhir(mhs[i]);
        char Mutu=HurufMutu(NilaiAkhir1);
        string Stat =statusMhs(NilaiAkhir1);
        cout<<i+1<<"\t\t"<<mhs[i].npm<<"\t\t"<<mhs[i].NilaiPenguji1<<"\t\t"<<mhs[i].NilaiPenguji2<<"\t\t"<<mhs[i].NilaiPenguji3<<"\t\t"<<NilaiAkhir1<<"\t\t"<<Mutu<<"\t\t"<<Stat<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
    larikMahasiswa mhs;
    int n;
    Banyak(n);
    inputData(mhs,n);
    float rata=rataRataNilaiAkhir(mhs,n);
    float Tertinggi=NilaiTinggi(mhs,n);
    float Terendah=NilaiRendah(mhs,n);
    output(mhs,n);
    cout<<"Rata-rata : "<<rata<<endl;
    cout<<"Nilai Tertinggi : "<<Tertinggi<<endl;
    cout<<"Nilai Terendah : "<<Terendah<<endl;
    
    return 0;
}
