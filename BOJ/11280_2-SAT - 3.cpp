#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	vvi adj(2 * n + 1);
	vi finish(2 * n + 1), dfsn(2 * n + 1), cpn(2 * n + 1);
	stack <int> st;
	int cnt = 0, z = 0;
	auto ndx = [&](int x) {return x < 0 ? -x * 2 : x * 2 - 1; };
	while (m--) {
		int a, b; cin >> a >> b;
		adj[ndx(a)].push_back(abs(b) * 2 - (b < 0));
		adj[ndx(b)].push_back(abs(a) * 2 - (a < 0));
	}
	function <int(int)> get_scc = [&](int now) {
		int ret = dfsn[now] = ++cnt;
		st.push(now);
		for (int next : adj[now]) {
			if (!dfsn[next]) ret = min(ret, get_scc(next));
			else if (!finish[next]) ret = min(ret, dfsn[next]);
		}
		if (ret == dfsn[now]) {
			z++;
			while (1) {
				int tp = st.top(); st.pop();
				finish[tp] = 1;
				cpn[tp] = z;
				if (tp == now) break;
			}
		}
		return ret;
	};
	FOR(i,1,2*n)
		if (!dfsn[i]) get_scc(i);
	int ans = 1;
	FOR(i, 1, n) if (cpn[ndx(-i)] == cpn[ndx(i)]) ans = 0;
	cout << ans << '\n';
	return 0;
}