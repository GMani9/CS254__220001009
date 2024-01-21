#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> a;

    ifstream arr1("../arr1.txt");
    while(arr1 >> x) a.push_back(x);
    arr1.close();
    int n  = a.size();
    
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] < min1) {
            min2 = min1;
            min1 = a[i];
            continue;
        }
        if(a[i] < min2) min2 = a[i];
    }

    ofstream outputFile("output.txt");
    outputFile << "First minima : " << min1 << "\n";
    outputFile << "Second minima : " << min2 << "\n";
    outputFile.close();

}