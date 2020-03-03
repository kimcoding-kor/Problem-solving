#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	int f[100005][17];
	memset(f, 0x3f, sizeof(f));
	FOR(i, 1, n) cin >> f[i][0];
	FOR(j, 1, 16) FOR(i, 1, n)
		if(i + (1 << (j - 1)) <= n)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	while (m--) {
		int a, b; cin >> a >> b;
		int x = (int)log2(b - a + 1);
		cout << min(f[a][x], f[b - (1 << x) + 1][x]) << '\n';
	}
	return 0;
}