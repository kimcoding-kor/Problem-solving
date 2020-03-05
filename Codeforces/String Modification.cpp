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
using namespace std;

int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n, num; cin >> n;
		string s, ans; cin >> s;
		FOR(i, 1, 5005) ans += 'z';
		FOR(i, 1, n) {
			string a;
			FOR(j, i - 1, n - 1) a += s[j];
			if ((i & 1) == (n & 1)) {
				RFOR(j, i - 2, 0) a += s[j];
			}
			else FOR(j, 0, i - 2) a += s[j];
			if (a < ans) ans = a, num = i;
		}
		cout << ans << '\n' << num << '\n';
	}
	return 0;
}