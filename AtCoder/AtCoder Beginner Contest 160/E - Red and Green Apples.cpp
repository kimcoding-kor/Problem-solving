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
    ll x, y, a, b,c;
    cin >> x >> y >> a >> b >> c;
    priority_queue <ll, vll, greater <ll>> pq;
    vll v = vll(a);
    FOR(i, 0, a - 1) cin >> v[i];
    sort(all(v));
    RFOR (i, a - 1, a - x) pq.ep(v[i]);
    v = vll(b);
    FOR(i, 0, b - 1) cin >> v[i];
    sort(all(v));
    RFOR(i,b - 1, b - y) pq.ep(v[i]);
    v = vll(c);
    FOR(i,0,c - 1) cin >> v[i];
    sort(all(v));
    RFOR(i, c - 1, 0){
        if(pq.top() >= v[i]) break;
        pq.pop();
        pq.ep(v[i]);
    }
    ll sum = 0;
    while(pq.size()) sum += pq.top(), pq.pop();
    cout << sum << '\n';
    return 0;
}
