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
    ll ans = 0;
    int n; cin >> n;
    vi v(n + 1);
    map <int,int> m;
    FOR(i,1,n) {
        cin >> v[i];
        m[i - v[i]]++;
    }
    FOR(i,1,n){
        int x = i + v[i];
        if(m.find(x) == m.end()) continue;
        ans += m[x];
    }

    cout << ans << '\n';
    return 0;
}
