#include <cstdio>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int map[10][10];
bool r_chk[10][10], c_chk[10][10], z_chk[10][10];
int arr[100], cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (!map[i][j]) arr[cnt++] = i * 9 + j;
			else r_chk[i][map[i][j]] = c_chk[j][map[i][j]] = z_chk[i / 3 * 3 + j / 3][map[i][j]] = true;
		}
	function <bool(int)> dfs = [&](int level) {
		if (level == cnt) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					cout << map[i][j] << ' ';
				cout << '\n';
			}
			return true;
		}
		int r = arr[level] / 9, c = arr[level] % 9;
		for (int i = 1; i <= 9; i++) {
			int idx = r / 3 * 3 + c / 3;
			if (r_chk[r][i] || c_chk[c][i] || z_chk[idx][i]) continue;
			map[r][c] = i;
			r_chk[r][i] = c_chk[c][i] = z_chk[idx][i] = true;
			if (dfs(level + 1)) return true;
			r_chk[r][i] = c_chk[c][i] = z_chk[idx][i] = false;
		}
		return false;
	};
	dfs(0);
	return 0;
}