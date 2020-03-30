#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
using namespace std;

int main() {
    FIO;
    int n, x, y;
    cin >> n >> x >> y;
    vi ans(n);
    FOR(i,1,n) {
        FOR(j, i + 1,n) {
            int v = min({j - i, abs(x - i) + abs(j - y) + 1, abs(y - i) + abs(j - x) + 1});
            ans[v]++;
        }
    }
    FOR(i,1,n - 1) cout << ans[i] << '\n';
    return 0;
}
