#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define mod ((int)1e9+9)
using namespace std;

int main() {
    FIO;
    int n, f = 1; cin >> n;
    FOR(i,1,n) f = (1ll * f * (2*i - 1)) % mod;
    cout << f << '\n';
    return 0;
}