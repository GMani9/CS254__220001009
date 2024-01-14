#include <bits/stdc++.h>
using namespace std;

const int n = 4;
const int MAX = 1000000;

int dis[n+1][n+1] = {
    {0, 0, 0, 0, 0},
    {0, 0, 20, 42, 35},
    {0, 20, 0, 30, 34},
    {0, 42, 30, 0, 12},
    {0, 35, 34, 12, 0},
};

int memory[n+1][1 << (n+1)];

int solve(int i, int num) { 

    if (num == ((1 << i) | 3))
        return dis[1][i];  
        
    if (memory[i][num] != 0)
        return memory[i][num];

    int s = MAX;

    for (int j = 1; j <= n; j++) {
        if ((num & (1 << j)) && j != i && j != 1) {
            s = min(s, solve(j, num & (~(1 << i))) + dis[j][i]);
        }
    }

    return memory[i][num] = s;
}

int main()
{
    int ans = MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, solve(i, (1 << (n+1)) - 1) + dis[i][1]);
    }

    cout << "The shortest possible route: " << ans;

    return 0;
}
