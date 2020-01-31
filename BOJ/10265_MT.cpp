#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef stack <int> si;
typedef pair <int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k, z = 0; cin >> n >> k;
	si st;
	vvi adj = vvi(n + 1), scc;
	vi dfsn, finish, cpn, cnt;
	dfsn = finish = cpn = vi(n + 1);
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		adj[x].push_back(i);
	}
	function <int(int)> dfs = [&](int now) {
		int ret = dfsn[now] = ++z;
		st.push(now);
		for (int next : adj[now]) {
			if (!dfsn[next]) ret = min(ret, dfs(next));
			else if (!finish[next]) ret = min(ret, dfsn[next]);
		}
		if (ret == dfsn[now]) {
			vi newscc;
			while (1) {
				int tp = st.top(); st.pop();
				cpn[tp] = cnt.size();
				finish[tp] = 1;
				newscc.push_back(tp);
				if (tp == now) break;
			}
			cnt.push_back(newscc.size());
			scc.push_back(newscc);
		}
		return ret;
	};
	for (int i = 1; i <= n; i++)
		if (!dfsn[i]) dfs(i);
	vi in = vi(cnt.size());
	for (int i = 1; i <= n; i++) for (int j : adj[i])
		if (cpn[i] != cpn[j]) in[cpn[j]]++;
	vector <pii> v;
	function <int(int)> dfs2 = [&](int now) {
		int ret = 1;
		for (int next : adj[now]) {
			if (cpn[now] == cpn[next]) continue;
			ret += dfs2(next);
		}
		return ret;
	};
	for (int i = 0; i < in.size(); i++) {
		if (in[i]) continue;
		if (cnt[i] > k) continue;
		int child = 0;
		for (int j : scc[i]) child += dfs2(j) - 1;
		v.push_back({ cnt[i], child });
	}
	if (!(int)v.size()) {
		cout << "0\n";
		return 0;
	}
	vvi dp = vvi(v.size(), vi(k + 1, -1));
	dp[0][v[0].first] = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		dp[i][v[i].first] = v[i].second;
		for (int j = 0; j <= k; j++) {
			if (j - v[i].first < 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			else dp[i][j] = max({ dp[i][j],dp[i - 1][j - v[i].first] + v[i].second, dp[i - 1][j] });
		}
	}
	int ans = 0;
	for (int i = 0; i <= k; i++)
		if (dp[v.size() - 1][i] != -1)
			ans = max(ans, dp[v.size() - 1][i] + i);
	cout << (ans > k ? k : ans) << '\n';
	return 0;
}