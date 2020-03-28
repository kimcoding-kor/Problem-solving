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
		map <int, int> a;
		vi v;
		FOR(i, 1, n) a[i] = 1;
		FOR(i, 1, n) {
			int k; cin >> k;
			int chk = 0;
			FOR(i, 1, k) {
				int x; cin >> x;
				if (!chk && a.find(x) != a.end()) {
					a.erase(a.find(x));
					chk = 1;
				}
			}
			if (!chk) v.eb(i);
		}
		int chk = 0;
		for (int i : v) {
			if (a.size()) {
				cout << "IMPROVE" << '\n';
				cout << i << ' ' << a.begin()->fs << '\n';
				chk = 1;
				break;
			}
		}
		if(!chk) cout << "OPTIMAL\n";
	}
	return 0;
}