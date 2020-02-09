#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		vi v(2 * n);
		FOR(i, 0, 2 * n - 1) cin >> v[i];
		sort(all(v));
		cout << v[n] - v[n - 1] << '\n';
	}
	return 0;
}