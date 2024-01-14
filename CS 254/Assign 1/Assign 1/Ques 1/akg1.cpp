#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ifstream input("input.txt");

    int n;
    input >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        input >> arr[i];
    }

    input.close();

    int mx = -99999, smx = -99999;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mx) {
            smx = mx;
            mx = arr[i];
        } else if (arr[i] > smx) {
            smx = arr[i];
        }
    }

    cout << "The max. sum of two elements is : " << smx + mx << endl;

    return 0;
}
