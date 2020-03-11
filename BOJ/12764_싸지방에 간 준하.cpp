#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define fs first
#define sd second
#define ep emplace
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    FIO;
    int n; cin >> n;
    vector<pii> v(n);
    vector <int> ans;
    FOR(i, 0, n - 1) cin >> v[i].fs >> v[i].sd;
    sort(all(v));
    priority_queue <int> com;
    priority_queue <pii> end;
    FOR(i,0,n-1){
        while(end.size() && v[i].fs >= -end.top().fs) {
            com.ep(-end.top().sd);
            end.pop();
        }
        int idx;
        if(com.empty()) {
            idx = (int)ans.size();
            ans.eb(1);
        }
        else {
            ans[idx = -com.top()]++;
            com.pop();
        }
        end.ep(-v[i].sd, idx);
    }
    cout << (int)ans.size() << '\n';
    for(int i : ans) cout << i << ' ';
    return 0;
}