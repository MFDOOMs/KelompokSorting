#include <iostream>
using namespace std;
void insert(int arr[],int& nB2){
    cout<<"Masukan banyak angka yang ingin di sort : ";
    cin>>nB2;
    cout<<"Masukan angka : ";
    for(int i=0;i<nB2;i++){
        cin>>arr[i];
    }

}

void tukar(int& x, int& y){
    int temp=x;
    x=y;
    y=temp;
}

void bubble2A(int arr[], int nB2){
    int pass=1;
    for(int i=0;i<nB2-1;i++){
        for(int j=nB2-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                tukar(arr[j],arr[j-1]);
                cout<<"Pass ke-"<<pass<<": ";
                for(int k =0;k<nB2;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
            pass++;
            }
        }
    }
}

void bubble2D(int arr[], int nB2){
    int pass=1;
    for(int i=0;i<nB2-1;i++){
        for(int j=nB2-1;j>i;j--){
            if(arr[j]>arr[j-1]){
                tukar(arr[j],arr[j-1]);
                cout<<"Pass ke-"<<pass<<": ";
                for(int k =0;k<nB2;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
            pass++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int nB2;
    int* arr = new int[nB2];
    insert(arr,nB2);
    bubble2A(arr,nB2);
    cout<<endl;
    bubble2D(arr,nB2);
    delete[] arr;
    return 0;
}
