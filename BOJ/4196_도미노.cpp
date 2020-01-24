#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector <vector <int>> v1, v2;
vector <int> visit,root;

void bfs(int st, vector <vector <int>> &v) {
	queue <int> q;
	q.push(st);
	visit[st] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto& next : v[now]) {
			if (visit[next]) continue;
			visit[next] = 1;
			q.push(next);
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n, m;
		scanf("%d %d", &n, &m);
		v1.resize(n + 1);
		v2.resize(n + 1);
		visit.resize(n + 1);
		root.resize(n + 1, 1);
		for (int i = 1, a, b; i <= m; i++) {
			scanf("%d %d", &a, &b);
			v1[a].push_back(b);
			v2[b].push_back(a);
			root[b] = 0;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!root[i]) continue;
			bfs(i, v1);
			cnt++;
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i]) continue;
			bfs(i, v1);
			bfs(i, v2);
			cnt++;
		}
		printf("%d\n", cnt);
		v1.clear();
		v2.clear();
		visit.clear();
		root.clear();
	}
	return 0;
}