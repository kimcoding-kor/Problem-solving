#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define MAX 65
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
	FIO;
	while (1) {
		int n, m; cin >> n >> m;
		if (!n && !m) break;
		vvi adj(MAX);
		vi finish(MAX), dfsn(MAX), cpn(MAX);
		int cnt = 0, z = 0;
		stack <int> st;
		auto ndx = [&](int a, int b) {return abs(a) * 2 - (b ? (a > 0) : (a < 0)); };
		while (m--) {
			int a = 0, b = 0;
			string s1, s2; cin >> s1 >> s2;
			FOR(i, 0, s1.length() - 2) a = a * 10 + (s1[i] - '0');
			FOR(i, 0, s2.length() - 2) b = b * 10 + (s2[i] - '0');
			a++, b++;
			if (s1[s1.length() - 1] == 'w') a = -a;
			if (s2[s2.length() - 1] == 'w') b = -b;
			adj[ndx(a, 1)].push_back(ndx(b, 0));
			adj[ndx(b, 1)].push_back(ndx(a, 0));
		}
		adj[ndx(1, 0)].push_back(ndx(1, 1));
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
		int chk = 1;
		FOR(i, 1, n) if (cpn[ndx(i, 0)] == cpn[ndx(i, 1)]) chk = 0;
		if (!chk) cout << "bad luck";
		else FOR(i, 2, n)
			cout << i - 1 << ((cpn[ndx(i, 0)] < cpn[ndx(i, 1)]) ? 'h' : 'w') << ' ';
        cout << '\n';
	}
	return 0;
}