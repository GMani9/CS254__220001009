#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, Limit;
    cin >> n >> Limit;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(Limit + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= Limit; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[n][Limit] << endl;
    return 0;
}

// Time Complexity: O(nW)