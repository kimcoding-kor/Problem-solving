#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	ll s[25];
	for (int i = 1; i <= n; i++) {
		char ch; cin >> ch;
		if (i & 1) s[i] = (ch - '0');
		else s[i] = (1LL << 31) + ch;
	}
	auto cal = [&](ll chk, int a, int b) {
		if (chk == '+' + (1LL << 31)) return a + b;
		if (chk == '-' + (1LL << 31)) return a - b;
		return a * b;
	};
	int ans = INT_MIN;
	int visit[20] = {}, arr[10];
	function <void(int)> rec = [&](int level) {
		if (level == n / 2 + 1) {
			ll temp[25]; memcpy(temp, s, sizeof(s));
			for (int i = 1; i < level; i++) {
				int l = arr[i] - 1, r = arr[i] + 1;
				while (temp[l] >= (1LL << 31)) l -= 2;
				while (temp[r] >= (1LL << 31)) r += 2;
				temp[l] = cal(s[arr[i]], temp[l], temp[r]);
				temp[r] = (1LL << 31);
			}
			ans = max(ans, (int)temp[1]);
			return;
		}
		for (int i = 2; i < n; i += 2) {
			if (visit[i]) continue;
			visit[i] = 1;
			arr[level] = i;
			rec(level + 1);
			visit[i] = 0;
		}
	};
	if (n == 1) ans = s[1];
	else rec(1);
	cout << ans << '\n';
	return 0;
}