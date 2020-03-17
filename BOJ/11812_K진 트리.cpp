#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;

int main() {
    FIO;
    ll n, k,q;
    cin >> n >> k >> q;
    while(q--){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if(k == 1) {
            cout << abs(a-b) << '\n';
            continue;
        }
        ll val = 0;
        while(a != b){
            if(a < b) b = (b-1) / k;
            else a = (a - 1) / k;
            val++;
        }
        cout << val << '\n';
    }
    return 0;
}