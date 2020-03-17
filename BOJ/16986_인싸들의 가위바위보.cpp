#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, k; cin >> n >> k;
	int t[10][10] = {};
	FOR(i, 1, n) FOR(j, 1, n) cin >> t[i][j];
	int bc[4][21];
	FOR(i, 1, 20) cin >> bc[2][i];
	FOR(i, 1, 20) cin >> bc[3][i];
	bool v[10] = {};
	int w[4] = {}, c[4] = {};
    function <bool(int,int,int)> solve = [&](int i, int f, int s){
		++c[f], ++c[s];
        if(w[1] == k) return 1;
        if(w[2] == k || w[3] == k) return --c[f], --c[s], 0;
        if(f != 1 && s != 1){
            if(t[bc[f][c[f]]][bc[s][c[s]]] == 2 || (t[bc[f][c[f]]][bc[s][c[s]]] == 1 && f > s)){
                if(++w[f] && solve(i + 1, f, 1)) return 1;
                else return --w[f], --c[f], --c[s], 0;
            }
            if(++w[s] && solve(i + 1, s, 1)) return 1;
            return --w[s], --c[f], --c[s], 0;
        }
        FOR(j,1,n){
            if(v[j]) continue;
			v[j] = 1;
			if (t[j][bc[(f & s) + 2][c[(f & s) + 2]]] == 2) {
				if (++w[1] && solve(i + 1, 1, 6 - f - s)) return 1;
				--w[1];
			}
			else if (++w[(f & s) + 2] && solve(i + 1, (f & s) + 2, 6 - f - s)) return 1;
			else --w[(f & s) + 2];
			v[j] = 0;
        }
		--c[f], --c[s];
        return 0;
    };
    cout << solve(1,1,2) << '\n';
    return 0;
}