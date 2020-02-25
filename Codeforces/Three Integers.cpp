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
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 1e9;
		int A, B, C;
		FOR(i, 1, 20000) {
			for (int j = 1; j * j <= i; j++) {
				if (i % j) continue;
				int k = c % i;
				int val = abs(b - i) + abs(a - j) + min(k, i - k);
				if (val < ans) {
					ans = val, A = j, B = i;
					if (k < i - k) C = c - k;
					else C = c + i - k;
				}
				val = abs(b - i) + abs(a - i / j) + min(k, i - k);
				if (val < ans) {
					ans = val, A = i / j, B = i;
					if (k < i - k) C = c - k;
					else C = c + i - k;
				}
			}
		}
		cout << ans << '\n';
		cout << A << ' ' << B << ' ' << C << '\n';
	}
	return 0;
}