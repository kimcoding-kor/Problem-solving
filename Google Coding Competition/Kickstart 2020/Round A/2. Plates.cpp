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
		int n, k, p;
		cin >> n >> k >> p;
		int dp[55][1505], sum[55][35] = {};
		memset(dp, -1, sizeof(dp));
		FOR(i, 1, n) {
			FOR(j, 1, k) {
				int x; cin >> x;
				sum[i][j] = sum[i][j - 1] + x;
			}
		}
		function <int(int, int)> DP = [&](int now, int cnt) {
			int& ret = dp[now][cnt];
			if (ret != -1) return ret;
			if (now == n) return ret = sum[now][min(cnt, k)];
			ret = 0;
			FOR(i, 0, k) {
				if (i > cnt) break;
				ret = max(ret, DP(now + 1, cnt - i) + sum[now][i]);
			}
			return ret;
		};
		cout << "Case #" << t << ": " << DP(1, p) << '\n';
	}
	return 0;
}