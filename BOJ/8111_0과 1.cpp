#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pii pair <int,int>
#define fs first
#define sd second
using namespace std;

int main(){
    FIO;
    int t; cin >> t ;while(t--){
        int n; cin >> n;
        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }
        queue <int> q;
        vector <pii> chk(20005, {-1,-1});
        q.emplace(1); chk[1] = {1,-1};
        while(q.size()){
            int now = q.front(); q.pop();
            int a = (now * 10 + 1) % n, b = (now * 10) % n;
            if(chk[a].fs == -1) chk[a] = {1, now}, q.emplace(a);
            if(chk[b].fs == -1) chk[b] = {0, now}, q.emplace(b);
            if(!a || !b) break;
        }
        stack <int> s;
        for(int i = 0; i != -1; i = chk[i].sd)
            s.emplace(chk[i].fs);
        if((int)s.size() > 100) cout << "BRAK";
        else while(s.size()) {
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    }
    return 0;
}