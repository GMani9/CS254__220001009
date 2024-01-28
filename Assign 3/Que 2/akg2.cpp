#include <bits/stdc++.h>
using namespace std;

void maxSubSum(const vector<int>& arr, ofstream& outputFile) {
    int n = arr.size();
    int maxSum = arr[0];
    int currSum = arr[0];
    int start = 0, end = 0, temp = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > currSum + arr[i]) {
            currSum = arr[i];
            temp = i;
        } else {
            currSum = currSum + arr[i];
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            start = temp;
            end = i;
        }
    }

    outputFile << "Maximum subarray sum: " << maxSum << endl;

    outputFile << "Subarray: ";
    for (int i = start; i <= end; ++i) {
        outputFile << arr[i];
        if (i < end) {
            outputFile << " + ";
        }
    }
    outputFile << " = " << maxSum << endl;
    outputFile << endl;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int testCases;
    inputFile >> testCases;

    for (int testCase = 1; testCase <= testCases; ++testCase) {
        int size;
        inputFile >> size;

        vector<int> input(size);
        for (int i = 0; i < size; ++i) {
            inputFile >> input[i];
        }

        outputFile << "Test Case " << testCase << ":" << endl;
        maxSubSum(input, outputFile);
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
