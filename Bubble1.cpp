#include <iostream>
using namespace std;
typedef int larik[100];

void tukar (int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

void printLarik (larik a, int n){
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

void bubble1D (int n, larik &a){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (a[j] < a[j+1]){
                tukar(a[j],a[j+1]);
                printLarik (a, n);
                cout << endl;
            }
        }
    }
}

void bubble1A (int n, larik &a){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (a[j] > a[j+1]){
                tukar(a[j],a[j+1]);
                printLarik (a, n);
                cout << endl;
            }
        }
    }
}