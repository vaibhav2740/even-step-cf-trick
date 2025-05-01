#include <bits/stdc++.h>
using namespace std;

/*
  CF “Zero Path”
  Trick: path length L=n+m−1, sums move in even steps.
  Maintain [minSum, maxSum] at each cell; check 0 at end.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (auto &row : grid) cin >> row;

        // dp[i][j] holds {minSum, maxSum} reachable at (i,j)
        vector dp(n, vector<pair<int,int>>(m, {INT_MAX, INT_MIN}));
        // start at (0,0)
        int start = (grid[0][0]=='1'? 1 : -1);
        dp[0][0] = {start, start};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i==0 && j==0) continue;
                int delta = (grid[i][j]=='1'? 1 : -1);
                int lo = INT_MAX, hi = INT_MIN;
                for (auto [pi,pj] : {make_pair(i-1,j), make_pair(i,j-1)}) {
                    if (pi>=0 && pj>=0) {
                        auto [prevMin, prevMax] = dp[pi][pj];
                        lo = min(lo, prevMin + delta);
                        hi = max(hi, prevMax + delta);
                    }
                }
                dp[i][j] = {lo, hi};
            }
        }

        auto [finalMin, finalMax] = dp[n-1][m-1];
        // 0 must lie in [finalMin,finalMax] and parity match
        bool ok = (finalMin <= 0 && 0 <= finalMax) 
                  && ((finalMax - finalMin) % 2 == 0);
        cout << (ok ? "YES\n" : "NO\n");
    }
}
