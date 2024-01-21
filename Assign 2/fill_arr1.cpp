#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5); 
    const int numRandomNumbers = 100000;
    ofstream arr1("arr1.txt");

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        arr1 << randomNum;

        if (i < numRandomNumbers - 1) {
            arr1 << ' ';
        }
    }

    arr1.close();
    cout << "Random integers have been stored in arr1.txt." << endl;

    return 0;
}