#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector <ll> vll;

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
	vll v;
	function <void(int)> rec = [&](int now) {
		if (now >= n - 1) {
			if(now == n - 1) v.push_back(s[now] - '0');
			vll temp;
			for (int i = 0; i < v.size(); i++) {
				if (v[i] - (1LL << 31) != '*') temp.push_back(v[i]);
				else {
					int val = cal('*', temp.back(), v[(i++) + 1]);
					temp.pop_back();
					temp.push_back(val);
				}
			}
			int sum = temp[0];
			for (int i = 2; i < temp.size(); i+=2)
				sum = cal(temp[i - 1] - (1LL << 31), sum, temp[i]);
			ans = max(ans, sum);
			if (now == n - 1) v.pop_back();
			return;
		}
		int a = s[now] - '0', b = s[now + 2] - '0', c = cal(s[now + 1], a, b);
		if (now + 2 <= n - 1) {
			v.push_back(c);
			v.push_back((1LL << 31) + s[now + 3]);
			rec(now + 4);
			v.pop_back(); v.pop_back();
		}
		v.push_back(a); v.push_back((1LL << 31) + s[now + 1]);
		rec(now + 2);
		v.pop_back(); v.pop_back();
	};
	if (n == 1) ans = s[0] - '0';
	else rec(0);
	cout << ans << '\n';
	return 0;
}