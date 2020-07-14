#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	int n, m;
	cin >> n >> m;

	int dist[505][505];

	FOR(i, 1, n) FOR(j, 1, n)
		cin >> dist[i][j];

	FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dist[a][b] <= c)
			cout << "Enjoy other party\n";
		else
			cout << "Stay here\n";
	}

	return 0;
}