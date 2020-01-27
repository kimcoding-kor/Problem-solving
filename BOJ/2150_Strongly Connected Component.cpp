#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

vvi scc, adj, r_adj;
vi visit, newscc;
stack <int> st;
int v, e;

void dfs(int now) {
	visit[now] = 1;
	for (int next : adj[now]) {
		if (visit[next]) continue;
		dfs(next);
	}
	st.push(now);
}

void dfs2(int now) {
	visit[now] = 1;
	newscc.push_back(now);
	for (int next : r_adj[now]) {
		if (visit[next]) continue;
		dfs2(next);
	}
 }

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> v >> e;
	adj = r_adj = vvi(v + 1);
	visit = vi(v + 1);
	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		r_adj[b].push_back(a);
	}
	for (int i = 1; i <= v; i++)
		if(!visit[i]) dfs(i);
	visit = vi(v + 1);
	while (st.size()) {
		int now = st.top(); st.pop();
		if (visit[now]) continue;
		newscc.clear();
		dfs2(now);
		sort(newscc.begin(), newscc.end());
		scc.push_back(newscc);
	}
	sort(scc.begin(), scc.end());
	cout << (int)scc.size() << '\n';
	for (vi i : scc) {
		for (int j : i) cout << j << ' ';
		cout << "-1\n";
	}
	return 0;
}