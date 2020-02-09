#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define Fi first
#define Se second
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ppi pair <pii,pii>
using namespace std;

int main() {
	FIO;
	int n, m; cin >> n >> m;
	int dir[4][2] = { {-1,0},{1,0}, {0,1},{0,-1} };
	vvi arr(n + 1, vi(m + 1)), visit(n + 1, vi(m + 1));
	FOR(i, 1, n) FOR(j, 1, m) cin >> arr[i][j];
	map <pii, int> one;
	map <ppi, int> two;
	auto bfs = [&](int r, int c, int chk) {
		int cnt = 0;
		queue <pii> q;
		vector <pii> v;
		q.push({ r,c });
		arr[r][c] = 1;
		while (q.size()) {
			cnt++;
			pii now = q.front(); q.pop();
			for (auto d : dir) {
				int nr = now.Fi + d[0], nc = now.Se + d[1];
				if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
				if (visit[nr][nc] != chk && !arr[nr][nc]) {
					v.push_back({ nr,nc });
					visit[nr][nc] = chk;
				}
				if (arr[nr][nc] == 2) {
					q.push({ nr,nc });
					arr[nr][nc] = 1;
				}
 			}
		}
		if (v.size() == 1) one[{v[0].Fi, v[0].Se}]+=cnt;
		if (v.size() == 2) {
			sort(all(v));
			two[{ {v[0].Fi, v[0].Se}, { v[1].Fi,v[1].Se }}] += cnt;
		}
	};
	FOR(i, 1, n) FOR(j, 1, m)
		if (arr[i][j] == 2) bfs(i, j, i * 1001 + j);
	int ans = 0;
	for (auto it = two.begin(); it != two.end(); ++it) {
		int Max = it->Se;
		auto a = one.find({ it->Fi.Fi.Fi, it->Fi.Fi.Se });
		if (a != one.end()) Max += a->Se;
		auto b = one.find({ it->Fi.Se.Fi, it->Fi.Se.Se });
		if (b != one.end()) Max += b->Se;
		ans = max(ans, Max);
	}
	int m1 = 0, m2 = 0;
	for (auto it = one.begin(); it != one.end(); ++it) {
		m2 = max(min(it->Se, m1), m2);
		m1 = max(m1, it->Se);
	}
	ans = max(ans, m1 + m2);
	cout << ans << '\n';
	return 0;
}