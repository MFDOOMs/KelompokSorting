#include <iostream>
using namespace std;

void tukar(int& x, int& y) {
    int temp = y;
    y = x;
    x = temp;
}

void printLarik(int larik[], int n) {
    for (int i = 0; i < n; i++)
        cout << larik[i] << " ";
    cout << endl;
}

void bubbleSort3Des (int larik[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (larik[i] < larik[j]) tukar(larik[i], larik[j]);
        printLarik(larik, n);
    }
}

void bubbleSort3Asc (int larik[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (larik[i] > larik[j]) tukar(larik[i], larik[j]);
        printLarik(larik, n);
    }
}

main() {
    int larik[20];
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> larik[i];

    bubbleSort3Asc(larik, n);
    bubbleSort3Des(larik, n);
}