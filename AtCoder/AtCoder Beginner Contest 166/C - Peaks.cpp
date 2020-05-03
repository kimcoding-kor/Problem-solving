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
#define mod 998244353
#define EPS 1e-9
#define tc int t; cin >> t; while(t--)
using namespace std;

int main() {
    FIO;
    int n,m; cin >> n >> m;
    vi h(n + 1), chk(n + 1, 1);
    FOR(i,1,n) cin >> h[i];
    while(m--){
        int a, b; cin >> a >> b;
        if(h[a] < h[b]) chk[a] = 0;
        if(h[a] > h[b]) chk[b] = 0;
        if(h[a] == h[b]) chk[a] = chk[b] = 0;
    }
    int ans = 0;
    FOR(i,1,n) ans += chk[i];
    cout << ans << '\n';
    return 0;
}
