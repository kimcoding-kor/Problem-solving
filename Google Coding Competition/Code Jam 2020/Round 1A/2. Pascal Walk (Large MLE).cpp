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
		int n; cin >> n;
		cout << "Case #" << t << ": " << '\n';
		int r = 1, k = 1;
		cout << r << ' ' << k << '\n';
		r++, k++;
		if(n >= 2) cout << r << ' ' << k << '\n';
		if (n == 3) {
			cout << r + 1 << ' ' << k + 1 << '\n';
			continue;
		}
		int sum = 2; r++;
		FOR(i, 2, 1000) {
			if (sum + i > n) break;
			sum += i;
			cout << r << ' ' << k << '\n';
			r++, k++;
		}
		r--;
		FOR(i, 1, n - sum) {
			cout << r << ' ' << k << '\n';
			r++, k++;
		}
	}
	return 0;
}