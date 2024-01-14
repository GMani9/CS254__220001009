#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ifstream input("input.txt");

    int n, W;
    input >> n >> W;

    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; i++) {
        input >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        input >> values[i];
    }

    input.close();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    int ans;
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "The max. value that can be obtained is : " << dp[n][W] << endl;

    return 0;
}
