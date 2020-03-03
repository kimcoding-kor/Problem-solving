#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    FIO;
    int n;
    cin >> n;
    int sum[50005] = {}, ans = 0;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    FOR(i, 1, n) {
        int l = i, r = n;
        while (l <= r) {
            int m = l + r >> 1;
            int a = sum[m] - sum[i - 1];
            int b = sum[n] - a;
            if (a < b) l = m + 1;
            else r = m - 1;
            ans = max(ans,min(a, b));
        }
    }
    cout << ans << '\n';
    return 0;
}