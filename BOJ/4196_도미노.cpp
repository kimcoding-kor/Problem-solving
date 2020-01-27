#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n, m; cin >> n >> m;
		vvi adj, r_adj, scc;
		adj = r_adj = vvi(n + 1);
		vi visit = vi(n + 1), newscc, cpn, in;
		stack <int> st;
		while (m--) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			r_adj[b].push_back(a);
		}
		function <void(int)> dfs = [&](int now) {
			visit[now] = 1;
			for (int next : adj[now]) {
				if (visit[next]) continue;
				dfs(next);
			}
			st.push(now);
		};
		function <void(int)> dfs2 = [&](int now) {
			visit[now] = 1;
			newscc.push_back(now);
			cpn[now] = (int)scc.size();
			for (int next : r_adj[now]) {
				if (visit[next]) continue;
				dfs2(next);
			}
		};
		for (int i = 1; i <= n; i++)
			if (!visit[i]) dfs(i);
		visit = cpn = vi(n + 1);
		while (st.size()) {
			int now = st.top(); st.pop();
			if (visit[now]) continue;
			newscc.clear();
			dfs2(now);
			scc.push_back(newscc);
		}
		in = vi(scc.size());
		for (int i = 1; i <= n; i++)
			for (auto next : adj[i]) {
				if (cpn[i] == cpn[next]) continue;
				in[cpn[next]]++;
			}
		int ans = 0;
		for (int i : in) ans += !i;
		cout << ans << '\n';
	}
	return 0;
}