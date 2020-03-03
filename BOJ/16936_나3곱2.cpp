#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
#define vll vector <ll>
#define all(x) (x).begin(), (x).end()
#define eb emplace_back
using namespace std;

int main() {
    FIO;
    int n, root;
    cin >> n;
    vll v(n), in(n), f(n, -1);
    FOR(i, 0, n - 1) cin >> v[i];
    sort(all(v));
    FOR(i, 0, n - 1) {
        ll x = v[i];
        int idx = lower_bound(all(v), x * 2) - v.begin();
        if (idx < n && x * 2 == v[idx]) f[i] = idx, in[idx]++;
        if (x % 3) continue;
        idx = lower_bound(all(v), x / 3) - v.begin();
        if (idx < n && x / 3 == v[idx]) f[i] = idx, in[idx]++;
    }
    FOR(i, 0, n - 1) if (!in[i]) root = i;
    for (; root != -1; root = f[root])
        cout << v[root] << ' ';
    return 0;
}