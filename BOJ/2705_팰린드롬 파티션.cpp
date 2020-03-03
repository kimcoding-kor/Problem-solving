#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main(){
    FIO;
    int dp[1005];
    FOR(i,1,1000) dp[i] = 1;
    FOR(i,1,1000) FOR(j,0,i - 1){
        if((i - j) & 1) continue;
        dp[i] += dp[(i - j) >> 1];
    }
    int t; cin >> t; while(t--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}