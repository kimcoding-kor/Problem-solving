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
    ll x; cin >> x;
    FOR(i,-1000,1000) FOR(j,-1000,1000)
        if(1ll*i*i*i*i*i - 1ll*j*j*j*j*j == x)
            return cout << i << ' ' << j << '\n', 0;
    return 0;
}
