#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
	int n, m;
	while (~scanf("%d %d", &n,&m)) {
		vvi adj(2 * n + 1);
		vi finish, dfsn, cpn;
		finish = dfsn = cpn = vi(2 * n + 1);
		stack <int> st;
		int cnt = 0, z = 0;
		auto ndx = [&](int a, int b) {return abs(a) * 2 - (b ? (a > 0) : (a < 0)); };
		while (m--) {
			int a, b; scanf("%d %d", &a, &b);
			adj[ndx(a, 1)].push_back(ndx(b, 0));
			adj[ndx(b, 1)].push_back(ndx(a, 0));
		}
		adj[ndx(1, 1)].push_back(ndx(1, 0));
		function <int(int)> get_scc = [&](int now) {
			int ret = dfsn[now] = ++cnt;
			st.push(now);
			for (int next : adj[now]) {
				if (!dfsn[next]) ret = min(ret, get_scc(next));
				else if (!finish[next]) ret = min(ret, dfsn[next]);
			}
			if (ret == dfsn[now]) {
				while (1) {
					int tp = st.top(); st.pop();
					finish[tp] = 1;
					cpn[tp] = z;
					if (tp == now) break;
				}
				z++;
			}
			return ret;
		};
		FOR(i, 1, 2 * n)	
			if (!dfsn[i]) get_scc(i);
		int ans = 1;
		FOR(i, 1, n) if (cpn[ndx(i, 0)] == cpn[ndx(i, 1)]) ans = 0;
		printf("%s\n", (ans ? "yes" : "no"));
	}
	return 0;
}