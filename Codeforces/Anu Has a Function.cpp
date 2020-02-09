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
	int n; cin >> n;
	vi v(n);
	FOR(i, 0, n - 1) {
		cin >> v[i];
	}
	int cnt, idx;
	RFOR(i, 30, 0) {
		cnt = 0, idx = -1;
		FOR(j, 0, n - 1) {
			if ((1 << i) & v[j])
				cnt++, idx = j;
			if (cnt > 1) break;
		}
		if (cnt == 1) break;
	}
	if (!cnt) idx = 0;
	cout << v[idx] << ' ';
	FOR(i, 0, n - 1)
		if (i != idx) cout << v[i] << ' ';
	return 0;
}