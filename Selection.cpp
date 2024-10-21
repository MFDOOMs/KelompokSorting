#include <iostream>
using namespace std;

void insert(int arr[],int& nS){
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

void SelectionA(int arr[],int nS){
    int pass=1,posisi;
    for(int i=0;i<nS-1;i++){
        posisi=i;
        for(int j=i+1;j<nS;j++){
            if(arr[posisi]>arr[j]){
                posisi=j;
            }
        }
        tukar(arr[i],arr[posisi]);
        cout<<"pass ke-"<<pass<<": ";
        for(int k=0;k<nS;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        pass++;
    }
}

void SelectionD(int arr[],int nS){
    int pass=1,posisi;
    for(int i=0;i<nS-1;i++){
        posisi=i;
        for(int j=i+1;j<nS;j++){
            if(arr[posisi]<arr[j]){
                posisi=j;
            }
        }
        tukar(arr[i],arr[posisi]);
        cout<<"pass ke-"<<pass<<": ";
        for(int k=0;k<nS;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        pass++;
    }
}

int main(int argc, char const *argv[])
{
    int nS;
    int* arr= new int[nS];
    insert(arr,nS);
    SelectionA(arr,nS);
    cout<<endl;
    SelectionD(arr,nS);
    delete[] arr;
    return 0;
}
