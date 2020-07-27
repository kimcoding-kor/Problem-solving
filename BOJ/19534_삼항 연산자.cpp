#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair <int,int>
#define fs first
#define sd second
using namespace std;

int n;
string s;
vector <pii> adj[30];
vector <int> visit, idx;

void init() {
	idx.assign(s.length(), -1);
	stack <int> st;
	FOR(i, 0, s.length() - 1) {
		if (s[i] == '?') st.push(i);
		if (s[i] == ':') {
			idx[st.top()] = i;
			st.pop();
		}
	}
}

int ctoi(char c) {
	if (c == '0') return 26;
	if (c == '1') return 27;
	return c - 'a';
}

bool dfs(int now) {
	for (auto next : adj[now]) {
		int v = next.fs, c = next.sd;
		if (v >= 26) {
			if ((visit[now] ^ !c) != v - 26) return 0;
			continue;
		}
		if (visit[v] != -1) {
			if (visit[v] != (visit[now] ^ !c)) return 0;
			continue;
		}
		visit[v] = visit[now] ^ !c;
		if (!dfs(v)) return 0;
	}
	return 1;
}

void edge(int a, int b, int w, int x) {
	if (x) {
		adj[a].push_back({ b, w });
		adj[b].push_back({ a, w });
	}
	else {
		adj[a].pop_back();
		adj[b].pop_back();
	}
}

int solve(int l, int r) {
	if (l > r) return 0;
	if (l == r) {
		if (s[l] == '1') return 0;
		else {
			edge(ctoi(s[l]), 26, 1, 1);
			visit.assign(30, -1);
			visit[26] = 0, visit[27] = 1;
			int x = dfs(26) && dfs(27);
			int cnt = n;
			FOR(i, 0, n - 1) {
				if (adj[i].size()) {
					if (visit[i] != -1) {
						cnt--;
						continue;
					}
					visit[i] = 0;
					x &= dfs(i);
				}
			}
			edge(ctoi(s[l]), 26, 1, 0);
			if (!x) return 0;
			return 1 << cnt;
		}
	}

	int a = l, b;
	while (a <= r && s[a] != '?') a++;
	b = idx[a];

	int x = ctoi(s[l]), y = ctoi(s[a - 1]), ret;

	edge(x, y, 1, 1);
	ret = solve(a + 1, b - 1);
	edge(x, y, 1, 0);

	edge(x, y, 0, 1);
	ret += solve(b + 1, r);
	edge(x, y, 0, 0);

	return ret;
}

int main() {
	FIO;
	cin >> n >> s;
	init();
	cout << solve(0, s.length() - 1) << '\n';
	return 0;
}