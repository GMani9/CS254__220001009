#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    int x = a[r];
    int i = l-1;
    for(int j = l; j < r; ++j) 
        if(a[j] < x) swap(a[++i], a[j]);
    swap(a[i+1], a[r]);
    return i+1;
}

int selection(vector<int>& a, int l, int r, int k) {
    if(r>l) {
        int p = partition(a, l, r);
        if(k < p) return selection(a, l, p-1, k);
        if(k > p) return selection(a, p+1, r, k);
        if(k == p) return a[k];
    }
    if(l == k) return a[l];
    if(r == k) return a[r];
    return INT_MAX;
}

int main() {
    int t; vector<int> a;

    ifstream arr1("../arr1.txt");
    while(arr1 >> t) a.push_back(t);
    arr1.close();
    int n = a.size();

    int x = selection(a, 0, n-1, (n-1)/2);
    int y = selection(a, 0, n-1, n/2);

    ofstream outputFile("output.txt");
    outputFile << (x+y)/2 << "\n";
    outputFile.close();
}