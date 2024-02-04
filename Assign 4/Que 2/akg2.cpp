#include <bits/stdc++.h>
using namespace std;

double findMedian(int* a, int n, int* b, int m) {

	int index1 = 0, index2 = n, i, j, median;

	while (index1 <= index2) {
		i = (index1 + index2) / 2;
		j = ((n + m + 1) / 2) - i;

		if (j < 0) {
			index2 = i - 1;
			continue;
		}

		if (i < n && j > 0 && b[j - 1] > a[i])
			index1 = i + 1;

		else if (i > 0 && j < m && b[j] < a[i - 1])
			index2 = i - 1;

		else {
			if (i == 0) median = b[j - 1];
			else if (j == 0) median = a[i - 1];
			else median = max(a[i - 1], b[j - 1]);
			break;
		}
	}

	if ((n + m) % 2 == 1)
		return (double)median;

	if (i == n)
		return (median + b[j]) / 2.0;

	if (j == m)
		return (median + a[i]) / 2.0;

	return (median + min(a[i], b[j])) / 2.0;
}

int main() {

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int t; inputFile >> t;
    while (t--) {
		int n; inputFile >> n;
		int m; inputFile >> m;
		int a[n],b[m];
		for (int i=0; i<n; i++) inputFile >> a[i];
		for (int i=0; i<m; i++) inputFile >> b[i];
		
		outputFile << "The median is : ";
		if (n < m) outputFile << findMedian(a, n, b, m);
		else outputFile << findMedian(b, m, a, n);
		outputFile << endl;

	}

    inputFile.close();
    outputFile.close();

	return 0;
}
