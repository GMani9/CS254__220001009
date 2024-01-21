#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) i++;
        else {
            int temp = a[j];
            for (int k = j; k > i; k--) a[k] = a[k - 1];
            a[i] = temp;
            i++, j++, m++;
        }
    }
}

void mergeSort(vector<int>& a, int l, int r) {
    if (r>l) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int x; vector<int> a;

    ifstream arr1("../arr1.txt");
    while(arr1 >> x) a.push_back(x);
    arr1.close();
    int n = a.size();

    mergeSort(a, 0, n - 1);
    
    ofstream outputFile("output.txt");
    for (int x : a) outputFile << x << ' ';
    outputFile.close();   
}