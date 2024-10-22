#include <iostream>
using namespace std;
typedef int array[50];

void insert(array arr,int& nS){
cout<<"Masukan Banyak angka yang ingin di sort : ";
cin>>nS;
cout<<" Masukan angka : ";
for(int i=0;i<nS;i++){
    cin>>arr[i];
}
}

void tukar(int& x, int& y){
    int temp=x;
    x=y;
    y=temp;
}

void print(array arr, int nS) {
    for (int i = 0; i < nS; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void SelectionA(array arr,int nS){
    int posisi;
    for(int i=0;i<nS-1;i++){
        posisi=i;
        for(int j=i+1;j<nS;j++){
            if(arr[posisi]>arr[j]){
                posisi=j;
            }
        }
        tukar(arr[i],arr[posisi]);
        print(arr,nS);
    }
}

void SelectionD(array arr,int nS){
    int posisi;
    for(int i=0;i<nS-1;i++){
        posisi=i;
        for(int j=i+1;j<nS;j++){
            if(arr[posisi]<arr[j]){
                posisi=j;
            }
        }
        tukar(arr[i],arr[posisi]);
        print(arr,nS);
    }
}

int main(int argc, char const *argv[])
{
    int nS;
    array arr;
    insert(arr,nS);
    SelectionA(arr,nS);
    cout<<endl;
    SelectionD(arr,nS);
    return 0;
}
