#include <cstdio>
#include <cstring>
#define min(a,b) (a < b ? a : b)

int dist[255][255], n, m, k;

void floyd() {
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	for (int c = 1; c <= n; c++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][c] + dist[c][j]);
}

int main() {
	memset(dist, 0x3f3f3f, sizeof(dist));
	scanf("%d %d", &n, &m);
	for (int i = 1, a, b, w; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		dist[a][b] = 0;
		dist[b][a] = !w;
	}
	floyd();
	scanf("%d", &k);
	for (int i = 1, a, b; i <= k; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", dist[a][b]);
	}
	return 0;
}