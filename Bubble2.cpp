#include <iostream>
using namespace std;
typedef int array[50];
void insert(array arr,int& nB2){
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

void print(array arr, int nB2) {
    for (int i = 0; i < nB2; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubble2A(array arr, int nB2){
    for(int i=0;i<nB2-1;i++){
        for(int j=nB2-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                tukar(arr[j],arr[j-1]);
                print(arr,nB2);
            }
        }
    }
}

void bubble2D(array arr, int nB2){
    for(int i=0;i<nB2-1;i++){
        for(int j=nB2-1;j>i;j--){
            if(arr[j]>arr[j-1]){
                tukar(arr[j],arr[j-1]);
                print(arr,nB2);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int nB2;
    array arr;
    insert(arr,nB2);
    bubble2A(arr,nB2);
    cout<<endl;
    bubble2D(arr,nB2);
    return 0;
}
