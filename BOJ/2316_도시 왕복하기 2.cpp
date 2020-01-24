#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define S 1
#define T 2 + n

vector <int> adj[801];
int f[801][801], c[801][801], par[801];
int n, m;

bool backedge() {
	for (int i = T; i != S; i = par[i]) {
		f[i][par[i]]--;
		f[par[i]][i]++;
	}
	return 1;
}

int bfs(int ans) {
	while (1) {
		fill(par, par + 801, -1);
		queue <int> q;
		q.push(S);
		while (q.size()) {
			int now = q.front(), flag = 0; q.pop();
			for (auto i : adj[now]) {
				if (c[now][i] - f[now][i] <= 0 || par[i] != -1) continue;
				q.push(i);
				par[i] = now;
				if (i == T) { flag = 1; break; }
			}
			if (flag) break;
		}
		if (par[T] == -1) break;
		ans += backedge();
	}
	return ans;
}

void addedge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
	c[a][b] = 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 3; i <= n; i++) 
		addedge(i + n, i);
	for (int i = 1, a, b; i <= m; i++) {
		scanf("%d %d", &a, &b);
		addedge(a, b + n);
		addedge(b, a + n);
	}
	printf("%d\n", bfs(0));
	return 0;
}