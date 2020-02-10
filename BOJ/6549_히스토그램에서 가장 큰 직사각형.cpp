#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define fs first
#define sd second
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ppi pair <pii,pii>
using namespace std;

int main() {
	FIO;
	int n;
	while (cin >> n && n) {
		ll ans = 0;
		stack <pii> st;
		st.push({ -1,0 });
		FOR(i, 1, n + 1) {
			int x = 0;
			if (i <= n) cin >> x;
			while (st.size() && st.top().fs >= x) {
				pii now = st.top(); st.pop();
				int h = now.fs;
				int w = i - st.top().sd - 1;
				ans = max(ans, 1LL * h * w);
			}
			st.push({ x, i });
		}
		while (st.size()) st.pop();
		cout << ans << '\n';
	}
	return 0;
}