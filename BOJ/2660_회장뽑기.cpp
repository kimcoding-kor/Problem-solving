#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define mod ((int)1e9 + 7)
using namespace std;

int main() {
	FIO;
	int n, a, b;
	cin >> n;

	int dist[55][55];
	memset(dist, 0x3f, sizeof(dist));

	FOR(i, 1, n) dist[i][i] = 0;
	while (cin >> a >> b && a != -1 && b != -1)
		dist[a][b] = 1, dist[b][a] = 1;

	FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int score = 1e9 * 2, cnt = 0, Max[55] = {};
	FOR(i, 1, n) {
		FOR(j, 1, n)
			Max[i] = max(Max[i], dist[i][j]);
		if (score > Max[i]) {
			score = Max[i];
			cnt = 1;
		}
		else if (score == Max[i]) cnt++;
	}

	cout << score << ' ' << cnt << '\n';
	FOR(i, 1, n)
		if (score == Max[i])
			cout << i << ' ';
	return 0;
}