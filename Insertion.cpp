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

void insertionDes(int larik[], int n) {
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (larik[j] > larik[j + 1]) {
                tukar(larik[j], larik[j + 1]);
            }
        }
        printLarik(larik, n);
    }
}

void insertionAsc(int larik[], int n) {
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (larik[j] < larik[j + 1]) {
                tukar(larik[j], larik[j + 1]);
            }
        }
        printLarik(larik, n);
    }
}

main() {
    int larik[20];
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> larik[i];

    insertionAsc(larik, n);
}