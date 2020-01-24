#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int map[105], num[15], dice[5], ans;

void mapping() {
	for (int i = 0; i < 20; i++) map[i] = i + 1;
	map[map[map[map[5] = 26] = 32] = 38] = 50;
	map[map[map[10] = 44] = 48] = 50;
	map[map[map[map[15] = 56] = 54] = 52] = 50;
	map[map[map[50] = 60] = 70] = 20;
	map[20] = 100;
}

int next_idx(int idx, int cnt) {
	while (cnt--) {
		if (idx == 100) break;
		int next = map[idx];
		if (cnt && (next == 5 || next == 10 || next == 15))
			next++, cnt--;
		idx = next;
	}
	return idx;
}

int score(int idx) {
	if (idx <= 20) return idx * 2;
	if (idx <= 70) return idx / 2;
	return 0;
}

bool visit(int idx, int next) {
	for (int i = 1; i <= 4; i++) {
		if ((idx == i) || (dice[i] != next)) continue;
		if ((next == 100) || (next == 0)) continue;
		return 1;
	}
	return 0;
}

void permutation(int level,int sum) {
	if (level == 11) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		int now = dice[i];
		if (now == 100) continue;
		int next = next_idx(dice[i], num[level]);
		if (visit(i, next)) continue;
		dice[i] = next;
		permutation(level + 1, sum + score(next));
		dice[i] = now;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	mapping();
	for (int i = 1; i <= 10; i++) cin >> num[i];
	permutation(1, 0);
	cout << ans << '\n';
	return 0;
}