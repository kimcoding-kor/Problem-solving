#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main(){
    FIO;
    int n,m; cin >> n >> m;
    queue <int> q;
    bool t[55] = {}, a[55][55] = {};
    int k; cin >> k;
    while(k--) {
        int x; cin >> x;
        t[x] = 1;
        q.emplace(x);
    }
    FOR(i,1,m) {
        int x; cin >> x;
        while(x--){
            int y; cin >> y;
            a[i][y] = 1;
        }
    }
    while(q.size()){
        int now = q.front(); q.pop();
        FOR(i,1,m) if(a[i][now]){
            FOR(j,1,n) if(!t[j] && a[i][j]) {
                t[j] = 1;
                q.emplace(j);
            }
        }
    }
    int ans = 0;
    FOR(i,1,m) {
        bool f = 0;
        FOR(j,1,n) {
            if (a[i][j] && t[j]) {
                f = 1;
                break;
            }
        }
        if(!f) ans++;
    }
    cout << ans << '\n';
    return 0;
}