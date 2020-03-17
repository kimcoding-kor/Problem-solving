#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    FIO;
    int n;
    cin >> n;
    int sum[25][25] = {}, total = 0;
    FOR(i, 1, n) FOR(j, 1, n) {
            int x;
            cin >> x;
            sum[i][j] = sum[i - 1][j] + x;
            total += x;
    }
    int dp[25][25][2005];
    memset(dp,-1,sizeof(dp));
    function<int(int, int, int)> DP = [&](int now, int here, int x) {
        int &ret = dp[now][here][x];
        if(ret != -1) return ret;
        if(now > n) return ret = abs(total - x - x);
        ret = 1e9;
        FOR(i, 0, here)
            ret = min(ret,DP(now + 1, i, x + sum[i][now]));
        return ret;
    };
    cout << DP(1, n, 0) << '\n';
    auto path = [&](){
        int cost = 0;
        FOR(i,1,n) {
            int Min = 1e9, idx;
            FOR(j,0,n) {
                if(dp[i+1][j][cost + sum[j][i]] == -1) continue;
                if (Min > dp[i + 1][j][cost + sum[j][i]]) {
                    Min = dp[i + 1][j][cost + sum[j][i]];
                    idx = j;
                }
            }
            cost += sum[idx][i];
            cout << n - idx << ' ';
        }
    };
    path();
    return 0;
}