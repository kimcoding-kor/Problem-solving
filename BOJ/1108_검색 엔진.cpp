#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef stack <int> si;
typedef map <string, int> msi;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, cnt = 0, scc_cnt = 0; cin >> n;
	vvi adj = vvi(2505);
	vi dfsn, finish, cpn;
	dfsn = finish = cpn = vi(2505);
	msi m;
	si st;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (m.find(s) == m.end()) m[s] = (int)m.size();
		int x; cin >> x;
		while (x--) {
			string a; cin >> a;
			if (m.find(a) == m.end()) m[a] = (int)m.size();
			adj[m[s]].push_back(m[a]);
		}
	}
	function <int(int)> dfs = [&](int now) {
		int ret = dfsn[now] = ++cnt;
		st.push(now);
		for (int next : adj[now]) {
			if (!dfsn[next]) ret = min(ret, dfs(next));
			else if (!finish[next]) ret = min(ret, dfsn[next]);
		}
		if (ret == dfsn[now]) {
			while (1) {
				int tp = st.top(); st.pop();
				cpn[tp] = scc_cnt;
				finish[tp] = 1;
				if (tp == now) break;
			}
			scc_cnt++;
		}
		return ret;
	};
	for (auto i = m.begin(); i != m.end(); ++i)
		if (!dfsn[i->second]) dfs(i->second);
	vll dp = vll((int)m.size());
	function <ll(int)> get_dp = [&](int now) {
		ll& ret = dp[now];
		if (ret) return ret;
		ret = 1;
		for (int next : adj[now]) {
			if (cpn[now] == cpn[next]) continue;
			ret += get_dp(next);
		}
		return ret;
	};
	string ans; cin >> ans;
	cout << get_dp(m[ans]) << '\n';
	return 0;
}