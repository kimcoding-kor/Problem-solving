#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define cr(a,b) (y >= x) ? a : b
#define cc(a,b) (y >= x) ? b : a

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int map[101][101] = {}, r, c, k;
	cin >> r >> c >> k;
	FOR(i, 1, 3) FOR(j, 1, 3)
		cin >> map[i][j];
	int ans = 0, x = 3, y = 3;
	while (map[r][c] != k && (ans++) <= 100) {
		int Max = 0;
		FOR(i,1,100) {
			int cnt[101] = {};
			vector <pair<int, int>> v;
			FOR(j, 1, 100) {
				if (!map[cr(i, j)][cc(i, j)]) continue;
				cnt[map[cr(i,j)][cc(i,j)]]++;
			}
			FOR(j, 1, 100) {
				if (!cnt[j]) continue;
				v.push_back({ cnt[j], j });
			}
			sort(all(v));
			FOR(j,0,(int)v.size()-1) {
				map[cr(i, j * 2 + 1)][cc(i, j * 2 + 1)] = v[j].second;
				map[cr(i, j * 2 + 2)][cc(i, j * 2 + 2)] = v[j].first;
			}
			Max = max(Max, (int)v.size() * 2);
			FOR(j, (int)v.size() * 2 + 1, 100)
				map[cr(i, j)][cc(i, j)] = 0;
		}
		((y >= x) ? x : y) = Max;
	}
	cout << (ans > 100 ? -1 : ans) << '\n';
	return 0;
}