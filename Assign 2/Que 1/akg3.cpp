#include <bits/stdc++.h>
using namespace std;
 
void intersect(vector<int>& a, vector<int>& b, int m, int n, vector<int>& ans) {
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (a[i] < b[j]) i++;
		else if (b[j] < a[i]) j++;
		else {
			ans.push_back(b[j]);
			i++, j++;
			while(i < m && a[i] == a[i-1]) i++;
			while(j < n && b[j] == b[j-1]) j++;
		}
	}
}

int main() {
 int x; vector<int> a, b;

    ifstream arr1("../arr1.txt");
    while(arr1 >> x) a.push_back(x);
    sort(a.begin(), a.end());
	unique(a.begin(), a.end());
    arr1.close();
   
    ifstream arr2("../arr2.txt");
    while(arr2 >> x) b.push_back(x);
    sort(b.begin(), b.end());
	unique(b.begin(), b.end());
    arr2.close();
	
	int m = a.size();
	int n = b.size();

    vector<int> ans;
 	intersect(a, b, m, n, ans);
    ofstream outputFile("output3.txt");
	for(int y : ans) outputFile << y << ' ';
    outputFile.close();
}