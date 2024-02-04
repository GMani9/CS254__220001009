#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    int cnt = 0;

    int i = left;
    int j = mid + 1;    
    int k = left;       

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } 
        else {
            temp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }

    while (i <= mid) { temp[k++] = arr[i++]; }

    while (j <= right) {temp[k++] = arr[j++]; }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return cnt;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int cnt = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        cnt += mergeSort(arr, temp, left, mid);
        cnt += mergeSort(arr, temp, mid + 1, right);
        cnt += merge(arr, temp, left, mid, right);
    }

    return cnt;
}


int main() {

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int t; inputFile >> t;
    while (t--) {
        int n;
        inputFile >> n;

        int arr[n];
        for (int i=0; i<n; ++i) inputFile >> arr[i];

        int curr[n];
        int ans = mergeSort(arr, curr, 0, n - 1);


        outputFile << "No of inversions : " << ans << endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}