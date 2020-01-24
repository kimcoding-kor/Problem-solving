#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> p;

#define cost first
#define ver second

vector <vector <p>> adj;
vi dist,hay;
int n, m, k;

void dijkstra(int st) {
	priority_queue <p> pq;
	pq.push({ 0,st });
	while (pq.size()) {
		p now = pq.top(); pq.pop();
		for (auto next : adj[now.ver]) {
			if (dist[next.ver] >= next.cost - now.cost) {
				dist[next.ver] = next.cost - now.cost;
				pq.push({ -dist[next.ver],next.ver });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	adj.resize(n + 1);
	dist.resize(n + 1, 1e9 + 7);
	hay.resize(n + 1);
	for (int i = 1, a, b, w; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back({ w,b });
		adj[b].push_back({ w,a });
	}
	for (int i = 1, a, b; i <= k; i++) {
		scanf("%d %d", &a, &b);
		hay[a] = max(hay[a], b);
	}
	dijkstra(n);
	for (int i = 1; i <= n; i++)
		if (hay[i])
			adj[0].push_back({ dist[i] - hay[i], i });
	vi pre_dist = dist;
	dist.assign(n + 1, 1e9 + 7);
	dijkstra(0);
	for (int i = 1; i < n; i++)
		printf("%d\n", pre_dist[i] >= dist[i]);
	return 0;
}