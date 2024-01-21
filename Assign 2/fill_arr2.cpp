#include <bits/stdc++.h>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1e5);  
    const int numRandomNumbers = 100000;
    ofstream arr2("arr2.txt");

    for (int i = 0; i < numRandomNumbers; ++i) {
        int randomNum = dis(gen);
        arr2 << randomNum;

        if (i < numRandomNumbers - 1) {
            arr2 << ' ';
        }
    }

    arr2.close();
    cout << "Random integers have been stored in arr2.txt." << endl;

    return 0;
}