#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	FOR(t, 1, test) {
		int a = 0, b = 0, c = 0;
		int n; cin >> n;
		int map[105][105] = {};
		FOR(i, 1, n) FOR(j,1,n) cin >> map[i][j];
		FOR(i, 1, n) a += map[i][i];
		
		FOR(i, 1, n) {
			vector <bool> visit(n + 1);
			int flag = 0;
			FOR(j, 1, n) {
				if (visit[map[i][j]]) {
					flag = 1;
					break;
				}
				visit[map[i][j]] = 1;
			}
			if (flag) b++;
		}

		FOR(j, 1, n) {
			vector <bool> visit(n + 1);
			int flag = 0;
			FOR(i, 1, n) {
				if (visit[map[i][j]]) {
					flag = 1;
					break;
				}
				visit[map[i][j]] = 1;
			}
			if (flag) c++;
		}
		cout << "Case #" << t << ": " << a << ' ' << b << ' ' << c << '\n';
	}
	return 0;
}