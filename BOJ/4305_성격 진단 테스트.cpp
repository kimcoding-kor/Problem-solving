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
	int n;
	while (cin >> n && n) {
		int cnt = 0;
		vvi adj = vvi(26), scc;
		si st;
		vi dfsn, finish, check;
		dfsn = finish = check = vi(26);
		while(n--) {
			char ch[5], a;
			for (int i = 0; i < 5; i++) cin >> ch[i];
			cin >> a;
			for (int i = 0; i < 5; i++) {
				check[ch[i] - 'A'] = 1;
				if (a != ch[i])
					adj[a - 'A'].push_back(ch[i] - 'A');
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
				vi newscc;
				while (st.size()) {
					int tp = st.top(); st.pop();
					newscc.push_back(tp);
					finish[tp] = 1;
					if (tp == now) break;
				}
				sort(newscc.begin(), newscc.end());
				scc.push_back(newscc);
			}
			return ret;
		};
		for (int i = 0; i < 26; i++)
			if (!dfsn[i] && check[i]) dfs(i);
		sort(scc.begin(), scc.end());
		for (vi i : scc) {
			for (int j : i) cout << (char)(j + 'A') << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}