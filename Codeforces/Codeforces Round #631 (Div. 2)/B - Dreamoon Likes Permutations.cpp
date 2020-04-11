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
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int arr[200005] = {};
		FOR(i, 1, n) cin >> arr[i];
		bool visit[200005] = {};
		int idx = 0, Max = 0;
		FOR(i, 1, n) {
			if (visit[arr[i]]) break;
			visit[arr[i]] = 1;
			idx = i;
			Max = max(Max, arr[i]);
		}
		vi ans;

		if (idx == Max) {
			memset(visit, 0, sizeof(visit));
			int w = idx; Max = 0;
			FOR(i, idx + 1, n) {
				if (visit[arr[i]]) break;
				visit[arr[i]] = 1;
				w = i;
				Max = max(Max, arr[i]);
			}
			if(w == n && Max == n - idx && idx && idx != n)
				ans.eb(idx), ans.eb(n - idx);
		}

		idx = 0, Max = 0;

		memset(visit, 0, sizeof(visit));
		RFOR(i, n, 1) {
			if (visit[arr[i]]) break;
			visit[arr[i]] = 1;
			idx = i;
			Max = max(Max, arr[i]);
		}
		if (n - idx + 1 == Max) {
			memset(visit, 0, sizeof(visit));
			int w = idx; Max = 0;
			FOR(i, 1, idx - 1) {
				if (visit[arr[i]]) break;
				visit[arr[i]] = 1;
				w = i;
				Max = max(Max, arr[i]);
			}
			if (w == idx - 1 && Max == idx - 1 && idx != 1 && n - idx + 1 != n)
				if(!ans.size() || (ans.size() && ans[0] != idx - 1)) ans.eb(idx - 1), ans.eb(n - idx + 1);
		}
		cout << ans.size() / 2 << '\n';
		for (int i = 0; i < ans.size(); i += 2) {
			cout << ans[i] << ' ' << ans[i + 1] << '\n';
		}
	}
	return 0;
}