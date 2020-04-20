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
#define pic pair<int,char>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod 998244353
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	int n, k;
	vvi vr, vc, map;

	function <bool(int)> f2 = [&](int idx) {
		int r = (idx - 1) / n + 1;
		int c = (idx - 1) % n + 1;
		if (r > n)
			return true;
		if (r == c)
			return f2(idx + 1);
		FOR(i, 1, n) {
			if (vr[r][i] || vc[c][i]) continue;
			vr[r][i] = vc[c][i] = 1;
			map[r][c] = i;
			if (f2(idx + 1)) return true;
			vr[r][i] = vc[c][i] = 0;
		}
		return false;
	};

	function <bool(int, int)> f = [&](int d, int sum) {
		if ((k - sum) / (n - d + 1) == 0) return false;
		if ((k - sum) > n * (n - d + 1)) return false;
		if (n == d) {
			map[d][d] = k - sum;
			vr[d][k - sum] = vc[d][k - sum] = 1;
			bool x = f2(1);
			vr[d][k - sum] = vc[d][k - sum] = 0;
			return x;
		}
		FOR(i, 1, n) {
			if (k - sum < i) break;
			vr[d][i] = vc[d][i] = 1;
			map[d][d] = i;
			if (f(d + 1, sum + i)) return true;
			vr[d][i] = vc[d][i] = 0;
		}
		return false;
	};

	FOR(t, 1, test) {
		string ans;
		cin >> n >> k;
		vr = vc = map = vvi(n + 1, vi(n + 1));
		if(!f(1,0)) cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
		else {
			cout << "Case #" << t << ": " << "POSSIBLE\n";
			FOR(i, 1, n) {
				FOR(j, 1, n) cout << map[i][j] << ' ';
				cout << '\n';
			}
		}
	}
	return 0;
}