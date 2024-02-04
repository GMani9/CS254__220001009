#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < nums.size(); i++) {
        min_heap.push(nums[i]);
        
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    return min_heap.top();
}

int main() {

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int t; inputFile >> t;
    while (t--) {
        int n; inputFile >> n;
        vector<int> nums;
        for (int i=0; i<n; i++) {
            int x; inputFile >> x;
            nums.push_back(x);
        }
        int k; inputFile >> k;

        int ans = kthLargest(nums, k);

        outputFile << "The " << k << "th largest element is: " << ans << endl;
    
    }

    return 0;
}
