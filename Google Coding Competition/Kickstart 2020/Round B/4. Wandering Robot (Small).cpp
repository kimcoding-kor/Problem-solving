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
#define db double
#define vd vector <db>
#define vvd vector <vd>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod ((int)1e9)
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int test; cin >> test;

	FOR(t, 1, test) {
		db ans = 0;
		int w, h, l, r, u, d;
		cin >> w >> h >> l >> u >> r >> d;
		vvd dp(h + 1, vd(w + 1));

		dp[1][1] = 1.0;
		FOR(i, 1, h) FOR(j, 1, w) {
			if (i >= u && i <= d && j >= l && j <= r) continue;
			if (i == h && j == w) continue;
			if (i == h) dp[i][j + 1] += dp[i][j];
			else if (j == w) dp[i + 1][j] += dp[i][j];
			else {
				dp[i][j + 1] += dp[i][j] / 2;
				dp[i + 1][j] += dp[i][j] / 2;
			}
		}

		cout << "Case #" << t << ": " << dp[h][w] << '\n';
	}
	return 0;
}