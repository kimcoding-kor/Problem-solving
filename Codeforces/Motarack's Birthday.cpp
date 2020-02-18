#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ll long long
#define vll vector <ll>
#define all(x) (x).begin(), (x).end()
#define fs first
#define sd second
#define eb emplace_back
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		vll v(n);
		vll a;
		vi visit(n);
		ll ans1 = 0, Max = 0;
		for (int i = 0; i < n; i++) cin >> v[i];
 
		for (int i = 0; i < n; i++) {
			if (v[i] == -1) {
				if (i) {
					if (v[i - 1] != -1) {
						visit[i - 1] = 1;
						a.eb(v[i - 1]);
					}
				}
				if (i < n - 1) {
					if (v[i + 1] != -1) {
						visit[i + 1] = 1;
						a.eb(v[i + 1]);
					}
				}
			}
			else {
				if (i) {
					if (v[i - 1] != -1) Max = max(Max, abs(v[i - 1] - v[i]));
				}
				if (i < n - 1) {
					if (v[i + 1] != -1) Max = max(Max, abs(v[i + 1] - v[i]));
				}
			}
		}
		if (a.empty()) {
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}
		sort(all(a));
		ll val = (a[0] + a[a.size() - 1]) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] == -1) {
				if (i) {
					if (v[i - 1] != -1) Max = max(Max, abs(v[i - 1] - val));
				}
				if (i < n - 1) {
					if (v[i + 1] != -1) Max = max(Max, abs(v[i + 1] - val));
				}
			}
		}
		cout << Max << ' ' << val << '\n';
	}
	return 0;
}