#include <iostream>
using namespace std;
void insert(int arr[],int& n){
    cout<<"Masukan banyak angka yang ingin di sort : ";
    cin>>n;
    cout<<"Masukan angka : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}

void swap(int& x, int& y){
    int temp=x;
    x=y;
    y=temp;
}

void bubble2A(int arr[], int n){
    int pass=1;
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                cout<<"Pass ke-"<<pass<<": ";
                for(int k =0;k<n;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
            pass++;
            }
        }
    }
}

void bubble2D(int arr[], int n){
    int pass=1;
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(arr[j]>arr[j-1]){
                swap(arr[j],arr[j-1]);
                cout<<"Pass ke-"<<pass<<": ";
                for(int k =0;k<n;k++){
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
    int n;
    int* arr = new int[n];
    insert(arr,n);
    bubble2A(arr,n);
    cout<<endl;
    bubble2D(arr,n);
    delete[] arr;
    return 0;
}
