#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef stack <int> si;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, s, t, k = 0;
	cin >> n >> m >> s >> t;
	vvi adj = vvi(n + 1), scc;
	si st;
	vi dfsn, finish, cpn, cnt;
	dfsn = finish = cpn = cnt = vi(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	function <int(int)> dfs = [&](int now) {
		int ret = dfsn[now] = ++k;
		st.push(now);
		for (int next : adj[now]) {
			if (!dfsn[next]) ret = min(ret, dfs(next));
			else if (!finish[next]) ret = min(ret, dfsn[next]);
		}
		if (ret == dfsn[now]) {
			vi newscc;
			while (st.size()) {
				int tp = st.top(); st.pop();
				newscc.push_back(tp);
				finish[tp] = 1;
				cpn[tp] = scc.size();
				if (tp == now) break;
			}
			cnt[scc.size()] = newscc.size();
			scc.push_back(newscc);
		}
		return ret;
	};
	for (int i = 1; i <= n; i++)
		if (!dfsn[i]) dfs(i);
	vvi scc_adj = vvi(scc.size());
	vi dp = vi(scc.size(), -1);
	for (int i = 1; i <= n; i++)
		for (int j : adj[i])
			if (cpn[i] != cpn[j])
				scc_adj[cpn[i]].push_back(cpn[j]);
	function <int(int)> get_dp = [&](int now) {
		int& ret = dp[now];
		if (ret != -1) return ret;
		ret = 0;
		if (cpn[t] == now) return ret = cnt[now];
		for (int next : scc_adj[now])
			ret = max(ret, get_dp(next));
		return ret += (ret ? cnt[now] : 0);
	};
	cout << get_dp(cpn[s]) << '\n';
	return 0;
}