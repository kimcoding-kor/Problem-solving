#include <cstdio>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vvi adj(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1, x; j <= n; j++) {
			cin >> x;
			if (x) adj[i].push_back(j);
		}
	for (int i = 1; i <= n; i++) {
		vi visit(n + 1);
		function <bool(int)> dfs = [&](int now) {
			for (int next : adj[now]) {
				if (visit[next]) continue;
				visit[next] = 1;
				if (dfs(next)) return 1;
			}
			return 0;
		};
		dfs(i);
		for (int j = 1; j <= n; j++)
			cout << visit[j] << ' ';
		cout << '\n';
	}
	return 0;
}