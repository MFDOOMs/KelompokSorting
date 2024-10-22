#include <iostream>
using namespace std;
typedef int larik[100];

void cetakLarik (larik a, int n){
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

void shellSortA (larik &a, int n){
    int j;
    for (int jarak=n/2; jarak>0; jarak/=2){
        for (int i=jarak; i<n; i++){
            int temp = a[i];
            for (j=i; j>=jarak && temp < a[j-jarak]; j-=jarak){
                a[j] = a[j-jarak];
            }
            a[j]=temp;
            cetakLarik (a,n);
            cout << "\n";
        }
    }
}

void shellSortD (larik &a, int n){
    int j;
    for (int jarak=n/2; jarak>0; jarak/=2){
        for (int i=jarak; i<n; i++){
            int temp = a[i];
            for (j=i; j>=jarak && temp > a[j-jarak]; j-=jarak){
                a[j] = a[j-jarak];
            }
            a[j]=temp;
            cetakLarik (a,n);
            cout << "\n";
        }
    }
}