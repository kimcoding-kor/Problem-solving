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
#define mod 998244353
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	FOR(t, 1, test) {
		int n, m; cin >> n >> m;
		int dir[4][2] = { {-1,0}, {1,0}, {0, -1},{0,1} };
		vvi map(n + 1, vi(m + 1));
		FOR(i, 1, n) FOR(j, 1, m) cin >> map[i][j];

		ll ans = 0;

		while (1) {
			vvi temp = map;
			int z = 0;
			FOR(i, 1, n) FOR(j, 1, m) ans += map[i][j];
			FOR(i, 1, n) FOR(j, 1, m) {
				if (!map[i][j]) continue;
				double sum = 0;
				int cnt = 0;
				for(auto d : dir) FOR(k, 1, 100) {
					int nr = i + d[0] * k, nc = j + d[1] * k;
					if (nr < 1 || nc < 1 || nr > n || nc > m) break;
					if (map[nr][nc]) {
						sum += map[nr][nc];
						cnt++;
						break;
					}
					
				}
				if (map[i][j] < sum / cnt) temp[i][j] = 0, z++;
			}
			if (!z) break;
			map = temp;
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}