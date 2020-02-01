#include <cstdio>
#include <climits>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	char s[25]; cin >> s;
	auto cal = [&](char ch, int a, int b) {
		if (ch == '+') return a + b;
		if (ch == '-') return a - b;
		return a * b;
	};
	int ans = INT_MIN;
	function <void(int, int)> rec = [&](int now,int sum) {
		if (now >= n - 1) {
			if (now == n - 1)
				sum = cal(s[now - 1], sum, s[now] - '0');
			ans = max(ans, sum);
			return;
		}
		int a = s[now] - '0', b = s[now + 2] - '0', c = cal(s[now + 1], a, b);
		rec(now + 4, now ? cal(s[now - 1], sum, c) : c);
		rec(now + 2, now ? cal(s[now - 1], sum, a) : a);
	};
	if (n == 1) ans = s[0] - '0';
	else rec(0, 0);
	cout << ans << '\n';
	return 0;
}