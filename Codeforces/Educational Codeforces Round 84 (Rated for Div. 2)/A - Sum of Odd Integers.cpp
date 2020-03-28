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
		int flag = 1;
		int n, k; cin >> n >> k;
		if (n % k) {
			int x = n / k;
			int y = n % k;
			if (x & 1 && y & 1) flag = 0;
			if (~x & 1 && (k - y) & 1) flag = 0;
			if (x < k)flag = 0;
		}
		else {
			int x = n / k;
			if (x < k) flag = 0;
			if (~x & 1) {
				if (k & 1) flag = 0;
			}

		}
		cout << (flag ? "YES\n" : "NO\n");

	}
	return 0;
}