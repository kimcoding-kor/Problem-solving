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
	int n, m; cin >> n >> m;
	int arr[1005] = {}, ans = 1;
	int v[1005];
	FOR(i, 1, n) {
		int x; cin >> x; v[i] = x;
		if (arr[x % m]) return cout << 0 << '\n', 0;
		arr[x % m] = 1;
	}
	FOR(i, 1, n) FOR(j, i + 1, n) {
		ans = (1LL * ans * abs(v[j] - v[i])) % m;
	}
	cout << ans << '\n';
	return 0;
}