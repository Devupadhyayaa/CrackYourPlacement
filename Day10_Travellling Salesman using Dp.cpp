#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int n;
vector<vector<int>> dist;
vector<vector<int>> dp;
void solve() {
    int max_mask = 1 << (n + 1);
    dp.assign(n + 1, vector<int>(max_mask, INF));
    for (int i = 1; i <= n; ++i) {
        dp[i][1 | (1 << i)] = dist[1][i];
    }
    for (int mask = 1; mask < max_mask; ++mask) {
        for (int i = 1; i <= n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 1; j <= n; ++j) {
                    if (mask & (1 << j) && j != i && j != 1) {
                        dp[i][mask] = min(dp[i][mask], dp[j][mask & (~(1 << i))] + dist[j][i]);
                    }
                }
            }
        }
    }

    int result = INF;
    int final_mask = (1 << (n + 1)) - 1; 
    for (int i = 2; i <= n; ++i) { 
        result = min(result, dp[i][final_mask]);
    }
    cout << "Minimum cost: " << result << endl;
}
