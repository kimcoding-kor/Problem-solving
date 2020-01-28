#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> pii;
typedef stack <int> si;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		vvi adj, r_adj, scc;
		adj = r_adj = vvi(n + 1);
		vi visit, cpn, currscc;
		visit = cpn = vi(n + 1);
		vector <pii> ans;
		si st;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				char ch; cin >> ch;
				if (ch == '0' || i == j) continue;
				adj[i].push_back(j);
				r_adj[j].push_back(i);
			}
		function <void(int)> dfs = [&](int now) {
			visit[now] = 1;
			for (int next : adj[now]) {
				if (visit[next]) continue;
				dfs(next);
			}
			st.push(now);
		};
		for (int i = 1; i <= n; i++)
			if (!visit[i]) dfs(i);
		visit = vi(n + 1);
		function <void(int)> dfs2 = [&](int now) {
			visit[now] = 1;
			currscc.push_back(now);
			cpn[now] = scc.size();
			for (int next : r_adj[now]) {
				if (visit[next]) continue;
				dfs2(next);
			}
		};
		while (st.size()) {
			int now = st.top(); st.pop();
			if (visit[now]) continue;
			currscc.clear();
			dfs2(now);
			scc.push_back(currscc);
		}
		int sccs = scc.size();
		for (int i = 0; i < sccs; i++)
			for (int j = 0; j < scc[i].size(); j++)
				if(scc[i].size() != 1)
					ans.push_back({ scc[i][j], scc[i][(j + 1) % scc[i].size()] });
		vvi chk = vvi(sccs, vi(sccs));
		for (int i = 1; i <= n; i++)
			for (int j : adj[i]) {
				if (cpn[i] == cpn[j]) continue;
				chk[cpn[i]][cpn[j]] = 1;
			}
		for (int k = 0; k < sccs; k++)
			for (int i = 0; i < sccs; i++)
				for (int j = 0; j < sccs; j++)
					if (chk[i][k] && chk[k][j]) chk[i][j] = 0;
		for (int i = 0; i < sccs; i++)
			for (int j = 0; j < sccs; j++)
				if(chk[i][j]) ans.push_back({ scc[i][0],scc[j][0] });
		cout << ans.size() << '\n';
		for (pii i : ans) cout << i.first << ' ' << i.second << '\n';
		cout << '\n';
	}
	return 0;
}