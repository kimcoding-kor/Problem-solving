#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define pii pair<int,int>
#define eb emplace_back
#define fs first
#define sd second
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		vector <vll> v(n + 1, vll(26));
		string s; cin >> s;
		for (int i = 0; i < (int)s.size();i++) {
			v[i][s[i] - 'a']++;
			if(i) FOR(j, 0, 25)
				v[i][j] += v[i - 1][j];
		}
		vll ans(26);
		int x; FOR(i, 1, m) {
			cin >> x;
			FOR(j, 0, 25) ans[j] += v[x - 1][j];
		}
		FOR(i, 0, 25) ans[i] += v[n - 1][i];
		FOR(i, 0, 25) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}