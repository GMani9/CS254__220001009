#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
    int m = a.size(), n = b.size();
    int i = 0, j = 0, k = 0;
    while(k < m + n) {
        if(j == n || a[i] <= b[j]) c[k] = a[i++];
        else if(i == m || b[j] <= a[i]) c[k] = b[j++];
        k++;
    }
}

int main() {
    int x; vector<int> a, b;

    ifstream arr1("../arr1.txt");
    while(arr1 >> x) a.push_back(x);
    sort(a.begin(), a.end());
    arr1.close();
   
    ifstream arr2("../arr2.txt");
    while(arr2 >> x) b.push_back(x);
    sort(b.begin(), b.end());
    arr2.close();

	int m = a.size(), n = b.size();
	vector<int> c(m + n);
	merge(a, b, c);

    ofstream outputFile("output1.txt");
	for(int y : c) outputFile << y << " ";
    outputFile.close();
}