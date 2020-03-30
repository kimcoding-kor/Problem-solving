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
		int a, b; cin >> a >> b;
		string ans;
		FOR(i, 0, a - 1) ans += 'a';
		int sum = 0;
		FOR(i, 1, a) {
			sum += i;
			if (sum >= b) {
				ans[a - i - 1] = ans[a - 1 - (b - (sum - i + 1))] = 'b';
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}