#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

struct ST{
    int* a, leaf;
    ST(int n){
        leaf = 1 << (int)ceil(log2(n));
        a = new int[leaf-- << 1];
        memset(a, 0x3f, sizeof(a));
    }
    void update(int i, int v){
        i += leaf;
        a[i] = v;
        while(i >>= 1) a[i] = min(a[i << 1], a[i << 1 | 1]);
    }
    int query(int l, int r){
        l += leaf, r += leaf;
        int ret = 1e9;
        for(;l < r;l >>= 1, r >>= 1){
            if(l & 1) ret = min(ret, a[l++]);
            if(~r & 1) ret = min(ret, a[r--]);
        }
        if(l == r) ret = min(ret, a[l]);
        return ret;
    }
    ~ST(){
        delete[] a;
    }
};

int main() {
    FIO;
    int n,m; cin >> n;
    ST st(n);
    FOR(i,1,n) {
        int x; cin >> x;
        st.update(i, x);
    }
    cin >> m;
    while(m--){
        int t, a, b; cin >> t >>a >> b;
        if(t == 1) st.update(a, b);
        else cout << st.query(a, b) << '\n';
    }
    return 0;
}