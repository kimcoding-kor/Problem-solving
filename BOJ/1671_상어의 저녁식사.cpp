#include <cstdio>
#include <cstring>
#include <vector>

struct p {
	int a, b, c;
	bool operator> (p t) {
		return a >= t.a && b >= t.b && c >= t.c;
	}
}shark[51];

int n, match[51], visit[51];
std :: vector <int> adj[51];

bool dfs(int now) {
	visit[now] = 1;
	for (auto next : adj[now]) {
		int &x = match[next];
		if (!x || !visit[x] && dfs(x)) {
			x = now;
			return 1;
		}
	}
	return 0;
}

int bmatch(int ans) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 2; j++) {
			memset(visit, 0, sizeof(visit));
			ans += dfs(i);
		}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &shark[i].a, &shark[i].b, &shark[i].c);
	for(int i=1;i<=n;i++)
		for (int j = i + 1; j <= n; j++) {
			if (shark[i] > shark[j]) adj[i].push_back(j);
			else if(shark[j] > shark[i]) adj[j].push_back(i);
		}
	printf("%d\n", n - bmatch(0));
	return 0;
}